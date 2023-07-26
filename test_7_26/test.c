//#include <stdio.h>
//int main()
//{
//	//����1
//	int num = 0;
//	scanf("%d", &num);
//	int arr[num] = { 0 };
//	//����2
//	int* ptr = NULL;
//	ptr = (int*)malloc(num * sizeof(int));
//	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
//	ptr = NULL;//�Ƿ��б�Ҫ��
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
//		//ʹ�ÿռ�
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
//		//ҵ����
//	}
//	else
//	{
//		exit(EXIT_FAILURE);
//	}
//	//��չ����
//	//����1
//	ptr = (int*)realloc(ptr, 1000);//����������(�������ʧ�ܻ���Σ�)
//	//����2
//	int* p = NULL;
//	p = realloc(ptr, 1000);
//	if (p != NULL)
//	{
//		ptr = p;
//	}
//	//ҵ����
//	free(ptr);
//	return 0;
//}

//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;//���p��ֵ��NULL���ͻ�������
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
//		*(p + i) = i;//��i��10��ʱ��Խ�����
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
//	free(p);//p����ָ��̬�ڴ����ʼλ��
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//�ظ��ͷ�
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
}status = INVALID;//��ʼ��Ϊ�Ƿ�

int my_atoi(char* str)
{

    int flag = 1;//��¼����λ
    //��ָ��
    assert(str);
    //���ַ�������
    if (*str == '\0')
    {
        return 0;
    }
    //���ַ�����
    while (*str == ' ')
    {
        str++;
    }
    //+_������
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

        //���������ַ�������
        if (isdigit(*str))
        {
            n = n * 10 + (*str - '0');
            //�������
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
            //���������ַ�ֱ������ѭ����status��ʱ����INVALID
            break;
        }
        str++;
    }
    if (*str == '\0')
    {
        status = VALID;//�ߵ�'\0'���ǺϷ�ת��
    }
    n *= flag;
    return (int)n;//ǿ������ת��Ϊint ����

}

int main()
{
    int n;
    char* str = "    -123a45";
    n = my_atoi(str);
    //�жϺϷ��Ƿ�ת��
    if (status == VALID)
    {
        printf("�Ϸ�ת����n=%d\n", n);
    }
    else
    {
        printf("�Ƿ�ת����n=%d\n", n);
    }
    return 0;
}