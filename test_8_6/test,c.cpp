//__FILE__ //���б����Դ�ļ�
//__LINE__ //�ļ���ǰ���к�
//__DATE__ //�ļ������������
//__TIME__ //�ļ��������ʱ��
//__STDC__ //�����������ѭANSI C����ֵΪ1������δ����

//printf("file:%s line:%d\n", __FILE__, __LINE__);

////�﷨��
//#define name stuff

//#define MAX 1000
//#define reg register //Ϊ register����ؼ��֣�����һ����̵�����
//#define do_forever for(;;) //�ø�����ķ������滻һ��ʵ��
//#define CASE break;case //��дcase����ʱ���Զ��� breakд�ϡ�
//// �������� stuff���������Էֳɼ���д���������һ���⣬ÿ�еĺ��涼��һ����б��(���з�)��
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
//PRINT("%d", i + 3);//������ʲôЧ����

//#define ADD_TO_SUM(num, value) \
//sum##num += value;
//...
//ADD_TO_SUM(5, 10);//�����ǣ���sum5����10.

//#define MAX(a, b) ( (a) > (b) ? (a) : (b) )
//...
//x = 5;
//y = 8;
//z = MAX(x++, y++);
//printf("x=%d y=%d z=%d\n", x, y, z);//����Ľ����ʲô��

//z = ((x++) > (y++) ? (x++) : (y++));

//x = 6 y = 10 z = 9

//#define MAX(a, b) ((a)>(b)?(a):(b))

//#define MALLOC(num, type)\
//(type *)malloc(num * sizeof(type))
//...
////ʹ��
//MALLOC(10, int);//������Ϊ����
////Ԥ�������滻֮��
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
//		printf("%d\n", arr[i]);//Ϊ�˹۲������Ƿ�ֵ�ɹ���
//#endif //__DEBUG__
//	}
//	return 0;
//}

//1.
//#if �������ʽ
////...
//#endif
////�������ʽ��Ԥ��������ֵ��
//�磺
//#define __DEBUG__ 1
//#if __DEBUG__
////..
//#endif
//2.�����֧����������
//#if �������ʽ
////...
//#elif �������ʽ
////...
//#else
////...
//#endif
//3.�ж��Ƿ񱻶���
//#if defined(symbol)
//#ifdef symbol
//#if !defined(symbol)
//#ifndef symbol
//4.Ƕ��ָ��
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