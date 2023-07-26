//#include <stdio.h>
//int main()
//{
//	//代码1
//	int num = 0;
//	scanf("%d", &num);
//	int arr[num] = { 0 };
//	//代码2
//	int* ptr = NULL;
//	ptr = (int*)malloc(num * sizeof(int));
//	if (NULL != ptr)//判断ptr指针是否为空
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//释放ptr所指向的动态内存
//	ptr = NULL;//是否有必要？
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//使用空间
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int* ptr = (int*)malloc(100);
//	if (ptr != NULL)
//	{
//		//业务处理
//	}
//	else
//	{
//		exit(EXIT_FAILURE);
//	}
//	//扩展容量
//	//代码1
//	ptr = (int*)realloc(ptr, 1000);//这样可以吗？(如果申请失败会如何？)
//	//代码2
//	int* p = NULL;
//	p = realloc(ptr, 1000);
//	if (p != NULL)
//	{
//		ptr = p;
//	}
//	//业务处理
//	free(ptr);
//	return 0;
//}

//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;//如果p的值是NULL，就会有问题
//	free(p);
//}

//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);
//}

//void test()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//ok?
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p不再指向动态内存的起始位置
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//重复释放
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	while (1);
//}

#include <ctype.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

enum Status
{
    VALID,
    INVALID
}status = INVALID;//初始化为非法

int my_atoi(char* str)
{

    int flag = 1;//记录符号位
    //空指针
    assert(str);
    //空字符串问题
    if (*str == '\0')
    {
        return 0;
    }
    //空字符问题
    while (*str == ' ')
    {
        str++;
    }
    //+_号问题
    if (*str == '+')
    {
        flag = 1;
        str++;
    }
    if (*str == '-')
    {
        flag = -1;
        str++;
    }
    long long n = 0;

    while (*str != '\0')
    {

        //不是数字字符的问题
        if (isdigit(*str))
        {
            n = n * 10 + (*str - '0');
            //溢出问题
            if (n > INT_MAX)
            {
                return INT_MAX;
                break;
            }
            if (n < INT_MIN)
            {
                return INT_MIN;
                break;
            }
        }
        else
        {
            //不是数字字符直接跳出循环，status此时还是INVALID
            break;
        }
        str++;
    }
    if (*str == '\0')
    {
        status = VALID;//走到'\0'就是合法转换
    }
    n *= flag;
    return (int)n;//强制类型转换为int 类型

}

int main()
{
    int n;
    char* str = "    -123a45";
    n = my_atoi(str);
    //判断合法非法转换
    if (status == VALID)
    {
        printf("合法转化：n=%d\n", n);
    }
    else
    {
        printf("非法转换：n=%d\n", n);
    }
    return 0;
}