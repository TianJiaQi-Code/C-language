#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
    //m�����˼�������nΪ�����
    //p�жϺ����м���,q�ж�������Ƿ��н�
    int arr[7] = { 0 };
    int i, n, m = 0, flag;
    int arr2[7];
    int p = 0, q = 0;
    printf("������6λ����ţ�1λ�����:");
    for (i = 0; i < 7; i++)
        scanf("%d", &arr2[i]);
    printf("��������˫ɫ���Ϊ:");
    for (i = 0; i < 7; i++)
        printf("%d", arr2[i]);
    while (1)
    {
        flag = 1;
        srand((unsigned int)time(NULL));
        n = rand() % 32 + 1;
        //ȥ��
        for (i = 0; i < 6; i++)
            if (n == arr[i])
            {
                flag = 0;
                break;
            }
        if (flag)
            arr[m++] = n;
        if (m == 6)
            break;
    }
    srand((unsigned int)time(NULL));
    arr[6] = rand() % 16 + 1;
    printf("����˫ɫ��Ϊ:\n");
    for (i = 0; i < 7; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for (i = 0; i < 6; i++)
        if (arr[i] == arr2[i])
            p++;
    if (arr[6] == arr2[6])
        q = 1;
    if (q)
    {
        switch (p)
        {
        case 0:
            printf("��ϲ���������Ƚ�\n");
            break;
        case 1:
            printf("��ϲ���������Ƚ�\n");
            break;
        case 2:
            printf("��ϲ���������Ƚ�\n");
            break;
        case 3:
            printf("��ϲ��������Ƚ�\n");
            break;
        case 4:
            printf("��ϲ�������ĵȽ�\n");
            break;
        case 5:
            printf("��ϲ���������Ƚ�\n");
            break;
        case 6:
            printf("��ϲ������һ�Ƚ�\n");
            break;
        default:
            printf("����ϵ������Ա��ϵͳ����\n");
            break;
        }
    }
    else
        switch (p)
        {
        case 0:
            printf("���ź�,��û���н�\n");
            break;
        case 4:
            printf("��ϲ��������Ƚ�\n");
            break;
        case 5:
            printf("��ϲ�������ĵȽ�\n");
            break;
        case 6:
            printf("��ϲ�����˶��Ƚ�\n");
            break;
        default:
            printf("����ϵ������Ա��ϵͳ����\n");
            break;
        }
}