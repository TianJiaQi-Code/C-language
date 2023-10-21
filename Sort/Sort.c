#include "Sort.h"
#include "stack.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			--end;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 找出小的那个孩子
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			// 继续往下调整
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	// 向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		// max如果被换走了，修正一下
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

// 三数取中
int GetMidi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])	// mid是最大值
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else    // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])	// mid是最小值
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// 快速排序Hoare版本
int PartSort1(int* a, int left, int right)
{
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);
	int keyi = left;
	while (left < right)
	{
		// 找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// 找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);
	int key = a[left];
	// 保存key的值后，左边形成第一个坑
	int hole = left;
	while (left < right)
	{
		// 右边先走，找小，填到左边的坑，右边形成新的坑位
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;
		// 左边再走，找大，填到右边的坑，左边形成新的坑位
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);
	int prev = left;
	int cur = prev + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}

void QuickSort1(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	// 小区间优化，小区间不再递归分割排序，降低递归次数
	if ((end - begin + 1) > 10)
	{
		int keyi = PartSort3(a, begin, end);
		QuickSort1(a, begin, keyi - 1);
		QuickSort1(a, keyi + 1, end);
	}
	else
	{
		InsertSort(a + begin, end - begin + 1);
	}
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	//int keyi = PartSort1(a, begin, end);
	//int keyi = PartSort2(a, begin, end);
	int keyi = PartSort3(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	STInit(&st);
	STPush(&st, end);
	STPush(&st, begin);
	while (!STEmpty(&st))
	{
		int left = STTop(&st);
		STPop(&st);
		int right = STTop(&st);
		STPop(&st);
		int keyi = PartSort1(a, left, right);
		if (keyi + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, keyi + 1);
		}
		if (left < keyi - 1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, left);
		}
	}
	STDestroy(&st);
}

void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (end <= begin)
		return;
	int mid = (end + begin) / 2;
	// [begin, mid] [mid + 1, end]
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);
	// 归并到tmp数组，再拷贝回去
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	// 拷贝回原数组
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// [begin1, end1] [begin2, end2] 归并
			// 如果第二组不存在，这一组不用归并了
			if (begin2 >= n)
			{
				break;
			}
			// 如果第二组的右边界越界，修正一下
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
			// 拷贝回原数组
			memcpy(a + i, tmp + i, (end2 - i + 1) * sizeof(int));
		}
		gap *= 2;
	}
	free(tmp);
}

void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	printf("range:%d\n", range);
	if (count == NULL)
	{
		perror("malloc fail");
		return;
	}
	memset(count, 0, sizeof(int) * range);
	// 统计数据出现次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	// 排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}