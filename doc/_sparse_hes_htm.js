var list_across0 = [
'_contents.htm',
'_reference.htm',
'_index.htm',
'_search.htm',
'_external.htm'
];
var list_up0 = [
'cppad.htm',
'adfun.htm',
'sparse_derivative.htm',
'sparse_hes.htm'
];
var list_down3 = [
'install.htm',
'introduction.htm',
'ad.htm',
'adfun.htm',
'preprocessor.htm',
'multi_thread.htm',
'utility.htm',
'ipopt_solve.htm',
'example.htm',
'speed.htm',
'appendix.htm'
];
var list_down2 = [
'record_adfun.htm',
'drivers.htm',
'forward.htm',
'reverse.htm',
'sparsity_pattern.htm',
'sparse_derivative.htm',
'optimize.htm',
'abs_normal.htm',
'funcheck.htm',
'check_for_nan.htm'
];
var list_down1 = [
'sparse_jac.htm',
'sparse_jacobian.htm',
'sparse_hes.htm',
'sparse_hessian.htm'
];
var list_down0 = [
'sparse_hes.cpp.htm'
];
var list_current0 = [
'sparse_hes.htm#Syntax',
'sparse_hes.htm#Purpose',
'sparse_hes.htm#SizeVector',
'sparse_hes.htm#BaseVector',
'sparse_hes.htm#f',
'sparse_hes.htm#x',
'sparse_hes.htm#w',
'sparse_hes.htm#subset',
'sparse_hes.htm#pattern',
'sparse_hes.htm#pattern.subset',
'sparse_hes.htm#coloring',
'sparse_hes.htm#coloring.cppad.symmetric',
'sparse_hes.htm#coloring.cppad.general',
'sparse_hes.htm#coloring.colpack.symmetric',
'sparse_hes.htm#coloring.colpack.general',
'sparse_hes.htm#coloring.colpack.star Deprecated 2017-06-01',
'sparse_hes.htm#work',
'sparse_hes.htm#n_sweep',
'sparse_hes.htm#Uses Forward',
'sparse_hes.htm#Example',
'sparse_hes.htm#Subset Hessian'
];
function choose_across0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_across0[index-1];
}
function choose_up0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_up0[index-1];
}
function choose_down3(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down3[index-1];
}
function choose_down2(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down2[index-1];
}
function choose_down1(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down1[index-1];
}
function choose_down0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down0[index-1];
}
function choose_current0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_current0[index-1];
}