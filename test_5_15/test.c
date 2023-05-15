#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void print(int* p, int sz)//p = &arr[0]
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *p);
		p++;
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//printf("%d", sz);
	print(arr, sz);//arr = &arr[0]
	return 0;
}