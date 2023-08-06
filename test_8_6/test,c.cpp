//__FILE__ //进行编译的源文件
//__LINE__ //文件当前的行号
//__DATE__ //文件被编译的日期
//__TIME__ //文件被编译的时间
//__STDC__ //如果编译器遵循ANSI C，其值为1，否则未定义

//printf("file:%s line:%d\n", __FILE__, __LINE__);

////语法：
//#define name stuff

//#define MAX 1000
//#define reg register //为 register这个关键字，创建一个简短的名字
//#define do_forever for(;;) //用更形象的符号来替换一种实现
//#define CASE break;case //在写case语句的时候自动把 break写上。
//// 如果定义的 stuff过长，可以分成几行写，除了最后一行外，每行的后面都加一个反斜杠(续行符)。
//#define DEBUG_PRINT printf("file:%s\tline:%d\t \
//date:%s\ttime:%s\n" ,\
//__FILE__,__LINE__ , \
//__DATE__,__TIME__ )

//#define MAX 1000;
//#define MAX 1000

//int main()
//{
//	if (condition)
//		max = MAX;
//	else
//		max = 0;
//
//	return 0;
//}

//#define name( parament-list ) stuff

//#define SQUARE( x ) x * x

//SQUARE(5);

//int a = 5;
//printf("%d\n", SQUARE(a + 1));

//printf("%d\n", a + 1 * a + 1);

//#define SQUARE(x) (x) * (x)

//printf("%d\n", (a + 1)* (a + 1));

//#define DOUBLE(x) (x) + (x)

//int a = 5;
//printf("%d\n", 10 * DOUBLE(a));

//printf("%d\n", 10 * (5) + (5));

//#define DOUBLE( x) ( ( x ) + ( x ) )

//char* p = "hello ""bit\n";
//printf("hello"" bit\n");
//printf("%s", p);

//int i = 10;
//#define PRINT(FORMAT, VALUE)\
//printf("the value of " #VALUE "is "FORMAT "\n", VALUE);
//...
//PRINT("%d", i + 3);//产生了什么效果？

//#define ADD_TO_SUM(num, value) \
//sum##num += value;
//...
//ADD_TO_SUM(5, 10);//作用是：给sum5增加10.

//#define MAX(a, b) ( (a) > (b) ? (a) : (b) )
//...
//x = 5;
//y = 8;
//z = MAX(x++, y++);
//printf("x=%d y=%d z=%d\n", x, y, z);//输出的结果是什么？

//z = ((x++) > (y++) ? (x++) : (y++));

//x = 6 y = 10 z = 9

//#define MAX(a, b) ((a)>(b)?(a):(b))

//#define MALLOC(num, type)\
//(type *)malloc(num * sizeof(type))
//...
////使用
//MALLOC(10, int);//类型作为参数
////预处理器替换之后：
//(int*)malloc(10 * sizeof(int));

//#include <stdio.h>
//int main()
//{
//	int array[ARRAY_SIZE];
//	int i = 0;
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		array[i] = i;
//	}
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//#define __DEBUG__
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#ifdef __DEBUG__
//		printf("%d\n", arr[i]);//为了观察数组是否赋值成功。
//#endif //__DEBUG__
//	}
//	return 0;
//}

//1.
//#if 常量表达式
////...
//#endif
////常量表达式由预处理器求值。
//如：
//#define __DEBUG__ 1
//#if __DEBUG__
////..
//#endif
//2.多个分支的条件编译
//#if 常量表达式
////...
//#elif 常量表达式
////...
//#else
////...
//#endif
//3.判断是否被定义
//#if defined(symbol)
//#ifdef symbol
//#if !defined(symbol)
//#ifndef symbol
//4.嵌套指令
//#if defined(OS_UNIX)
//#ifdef OPTION1
//unix_version_option1();
//#endif
//#ifdef OPTION2
//unix_version_option2();
//#endif
//#elif defined(OS_MSDOS)
//#ifdef OPTION2
//msdos_version_option2();
//#endif
//#endif

//int g_val = 2016;
//void print(const char* str)
//{
//	printf("%s\n", str);
//}

#include <stdio.h>
int main()
{
	extern void print(char* str);
	extern int g_val;
	printf("%d\n", g_val);
	print("hello bit.\n");
	return 0;
}