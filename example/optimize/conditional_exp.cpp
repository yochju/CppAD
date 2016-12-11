// $Id$
/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-16 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the
                    Eclipse Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */
/*
$begin optimize_conditional_exp.cpp$$

$section Example Optimization and Conditional Expressions$$

$head See Also$$
$cref cond_exp.cpp$$

$code
$srcfile%example/optimize/conditional_exp.cpp%0%// BEGIN C++%// END C++%1%$$
$$

$end
*/
// BEGIN C++
# include <cppad/cppad.hpp>
namespace {
	struct tape_size { size_t n_var; size_t n_op; };

	template <class Vector> void fun(
		const Vector& x, Vector& y, tape_size& before, tape_size& after
	)
	{	typedef typename Vector::value_type scalar;


		// phantom variable with index 0 and independent variables
		// begin operator, independent variable operators and end operator
		before.n_var = 1 + x.size(); before.n_op  = 2 + x.size();
		after.n_var  = 1 + x.size(); after.n_op   = 2 + x.size();

		// Create a variable that is is only used in the comparision operation
		scalar one = 1. / x[0];
		before.n_var += 1; before.n_op += 1;
		after.n_var  += 1; after.n_op += 1;

		// Note that the left and right operand in the CondExpLt comparison
		// are determined at this point. Hence the conditional skip operator
		// will be inserted here and the operations mentioned below can
		// also be skipped during zero order foward mode.

		// Create a variable that is only used when comparison result is true
		// (can be skipped when the comparison result is false)
		scalar two = x[0] * 5.0;
		before.n_var += 1; before.n_op += 1;
		after.n_var  += 1; after.n_op += 1;

		// Create two variables only used when the comparison result is false
		// (can be skipped when the comparison result is true)
		scalar three = 5.0 + x[0];
		scalar four  = three * 3.0;
		before.n_var += 2; before.n_op += 2;
		after.n_var  += 2; after.n_op += 2;

		// conditional expression
		// (conditional skip operator is added to operation sequence)
		scalar five = CppAD::CondExpLt(one, x[0], two, four);
		before.n_var += 1; before.n_op += 1;
		after.n_var  += 1; after.n_op += 2;

		// results for this operation sequence
		y[0] = five;
		before.n_var += 0; before.n_op  += 0;
		after.n_var  += 0; after.n_op   += 0;
	}
}

bool conditional_exp(void)
{	bool ok = true;
	using CppAD::AD;

	// domain space vector
	size_t n  = 1;
	CPPAD_TESTVECTOR(AD<double>) ax(n);
	ax[0] = 0.5;

	// declare independent variables and start tape recording
	CppAD::Independent(ax);

	// range space vector
	size_t m = 1;
	CPPAD_TESTVECTOR(AD<double>) ay(m);
	tape_size before, after;
	fun(ax, ay, before, after);

	// create f: x -> y and stop tape recording
	CppAD::ADFun<double> f(ax, ay);
	ok &= f.size_var() == before.n_var;
	ok &= f.size_op()  == before.n_op;

	// Optimize the operation sequence
	std::string options = "";
	f.optimize(options);
	ok &= f.size_var() == after.n_var;
	ok &= f.size_op()  == after.n_op;

	// Check case where result of the comparison is true (x[0] > 1.0).
	CPPAD_TESTVECTOR(double) x(n), y(m), check(m);
	x[0] = 1.75;
	y    = f.Forward(0, x);
	fun(x, check, before, after);
	ok  &= y[0] == check[0];
	ok  &= f.number_skip() == 2;

	// Check case where result of the comparision is false (x[0] <= 1.0)
	x[0] = 0.5;
	y    = f.Forward(0, x);
	fun(x, check, before, after);
	ok &= y[0] == check[0];
	ok  &= f.number_skip() == 1;

	return ok;
}

// END C++