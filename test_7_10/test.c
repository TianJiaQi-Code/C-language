#include <stdio.h>



//void my_strcpy(char str1[], char str2[])
//{
//	char* ptr1 = str1;
//	char* ptr2 = str2;
//	while (*ptr1 != '\0' && *ptr2 != '\0')
//	{
//		*ptr1 = *ptr2;
//		ptr1++;
//		ptr2++;
//	}
//	*ptr1 = '\0';
//}
//
//int main()
//{
//	char str1[20] = "xxxxxxxxxxxxxxx";
//	char str2[20] = "Hello World!";
//	my_strcpy(str1, str2);
//	puts(str1);
//	return 0;
//}

//#include <stdio.h>
//
//int my_strlen(char str[])
//{
//	char* p = str;
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//
//int main()
//{
//	char str[20] = "hello world!";
//	int ret = my_strlen(str);
//	printf("%d", ret);
//	return 0;
//}

//void Swap(char* buf1, char* buf2, int size)
//{
//	int i;
//	char tmp;
//	for (i = 0; i < size; i++)
//	{
//		tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
//void bubble_sort(void* base, int num, int size, int (*cmp)(const void*, const void*))
//{
//	int i;
//	for (i = 0; i < num - 1; i++)
//	{
//		int j;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
//			{
//				Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
//			}
//		}
//	}
//}
//
//int cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}
//
//int main()
//{
//	int arr[10] = { 1,4,7,2,5,8,3,6,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//int main()
//{
//	int arr[10] = { 1,4,7,2,5,8,3,6,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	qsort(arr, sz, sizeof(int), cmp);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}