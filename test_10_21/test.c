// 假设按照升序对array数组中[left, right)区间中的元素进行排序
void QuickSort(int array[], int left, int right)
{
	if (right - left <= 1)
		return;
	// 按照基准值对array数组的 [left, right)区间中的元素进行划分
	int div = partion(array, left, right);
	// 划分成功后以div为边界形成了左右两部分 [left, div) 和 [div+1, right)
	// 递归排[left, div)
	QuickSort(array, left, div);
	// 递归排[div+1, right)
	QuickSort(array, div + 1, right);
}