#include "Sort.h"

void InsterTest(int arr[], int n)
{
	InsertSort(arr, n);
	PrintArray(arr, n);
}

void ShellTest(int arr[], int n)
{
	ShellSort(arr, n);
	PrintArray(arr, n);
}

int main()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	//InsterTest(arr, sizeof(arr) / sizeof(arr[0]));
	ShellTest(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}