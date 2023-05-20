#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void sort(int arr[], int sz)
{
	int temp[10] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		if (arr[i] % 2 == 1)
		{
			temp[j] = arr[i];
			j++;
		}
	}
	for (i = 0; i < sz; i++)
	{
		if (arr[i] % 2 == 0)
		{
			temp[j] = arr[i];
			j++;
		}
	}
	for (i = 0; i < sz; i++)
	{
		arr[i] = temp[i];
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	sort(arr, sz);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//#include <stdio.h>
//
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}