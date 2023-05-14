#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    int year, month;
    while (scanf("%d %d", &year, &month) != EOF)
    {
        if (month != 2)
        {
            if (month == 4 || month == 6 || month == 9 || month == 11)
                printf("30\n");
            else
                printf("31\n");
        }
        else
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                printf("29\n");
            else
                printf("28\n");
        }
    }
    return 0;
}

//#include <stdio.h>
//
//int main()
//{
//    int n, i, flag = 0;
//    int seq[50];
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &seq[i]);
//    }
//    if (seq[0] > seq[1])
//    {
//        for (i = 1; i < n - 1; i++)
//        {
//            if (seq[i] < seq[i + 1])
//                flag = 1;
//        }
//    }
//    else if (seq[0] < seq[1])
//    {
//        for (i = 1; i < n - 1; i++)
//        {
//            if (seq[i] > seq[i + 1])
//                flag = 1;
//        }
//    }
//    if (flag == 1)
//        printf("unsorted");
//    else
//        printf("sorted");
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n, m, i, j, temp;
//    int seq[2000];
//    scanf("%d %d", &n, &m);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &seq[i]);
//    }
//    for (i = n; i < n + m; i++)
//    {
//        scanf("%d", &seq[i]);
//    }
//    for (i = 0; i < n + m - 1; i++)
//    {
//        for (j = 0; j < n + m - 1 - i; j++)
//        {
//            if (seq[j] > seq[j + 1])
//            {
//                temp = seq[j];
//                seq[j] = seq[j + 1];
//                seq[j + 1] = temp;
//            }
//        }
//    }
//    for (i = 0; i < n + m; i++)
//    {
//        printf("%d ", seq[i]);
//    }
//    return 0;
//}