#define _CRT_SECURE_NO_WARNINGS 1

//ģ��ʵ��strncat
//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strncat(char* dest, const char* src, size_t num)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (num)
//	{
//		*dest = *src;
//		dest++;
//		src++;
//		num--;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[10] = "World!";
//	char str2[20] = "Hello ";
//	//strcat(str2, str1);
//	//strncat(str2, str1, 7);
//	my_strncat(str2, str1, 7);
//	return 0;
//}

//ģ��ʵ��strncpy
//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (num)
//	{
//		if (*src != '\0')
//		{
//			*dest = *src;
//			dest++;
//			src++;
//		}
//		else
//		{
//			*dest = 0;
//			dest++;
//		}
//		num--;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str1[20] = "Hello World";
//	char str2[20] = "xxxxxxxxxxxxxxxxxxxx";
//	//strncpy(str2, str1, 15);
//	my_strncpy(str2, str1, 15);
//	return 0;
//}

//�ҵ���
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
//���磺
//�������Ԫ���ǣ�1��2��3��4��5��1��2��3��4��6
//ֻ��5��6ֻ����1�Σ�Ҫ�ҳ�5��6.

//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,1,2,3,4,6 };
//	int not_dog[10];
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		int temp = arr[i];
//		for (j = i + 1; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				not_dog[k] = arr[i];
//				k++;
//				break;
//			}
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		int j = 0;
//		for (j = 0; j < k; j++)
//		{
//			if (arr[i] == not_dog[j])
//			{
//				break;
//			}
//		}
//		if (j >= k)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	return 0;
//}