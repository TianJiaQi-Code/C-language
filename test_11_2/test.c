#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
    //m生成了几个数，n为随机数
    //p判断红球中几个,q判断蓝球号是否中奖
    int arr[7] = { 0 };
    int i, n, m = 0, flag;
    int arr2[7];
    int p = 0, q = 0;
    printf("请输入6位红球号，1位蓝球号:");
    for (i = 0; i < 7; i++)
        scanf("%d", &arr2[i]);
    printf("本次您的双色球号为:");
    for (i = 0; i < 7; i++)
        printf("%d", arr2[i]);
    while (1)
    {
        flag = 1;
        srand((unsigned int)time(NULL));
        n = rand() % 32 + 1;
        //去重
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
    printf("本次双色球为:\n");
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
            printf("恭喜您中了六等奖\n");
            break;
        case 1:
            printf("恭喜您中了六等奖\n");
            break;
        case 2:
            printf("恭喜您中了六等奖\n");
            break;
        case 3:
            printf("恭喜您中了五等奖\n");
            break;
        case 4:
            printf("恭喜您中了四等奖\n");
            break;
        case 5:
            printf("恭喜您中了三等奖\n");
            break;
        case 6:
            printf("恭喜您中了一等奖\n");
            break;
        default:
            printf("请联系工作人员，系统错误\n");
            break;
        }
    }
    else
        switch (p)
        {
        case 0:
            printf("很遗憾,您没有中奖\n");
            break;
        case 4:
            printf("恭喜您中了五等奖\n");
            break;
        case 5:
            printf("恭喜您中了四等奖\n");
            break;
        case 6:
            printf("恭喜您中了二等奖\n");
            break;
        default:
            printf("请联系工作人员，系统错误\n");
            break;
        }
}