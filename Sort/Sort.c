#include "Sort.h"

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
		// �ҳ�С���Ǹ�����
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			// �������µ���
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
	// ���µ�������
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
		// max����������ˣ�����һ��
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

// ����ȡ��
int GetMidi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])	// mid�����ֵ
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
		else if (a[left] < a[right])	// mid����Сֵ
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// ��������Hoare�汾
int PartSort1(int* a, int left, int right)
{
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);
	int keyi = left;
	while (left < right)
	{
		// ��С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		// �Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);
	int key = a[left];
	// ����key��ֵ������γɵ�һ����
	int hole = left;
	while (left < right)
	{
		// �ұ����ߣ���С�����ߵĿӣ��ұ��γ��µĿ�λ
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;
		// ������ߣ��Ҵ���ұߵĿӣ�����γ��µĿ�λ
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

// ��������ǰ��ָ�뷨
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