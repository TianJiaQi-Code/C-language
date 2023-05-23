#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    int i, j, input;
    while (scanf("%d", &input) != EOF)
    {
        for (i = 0; i < input; i++)
        {
            for (j = 0; j < input - i - 1; j++)
            {
                printf("  ");
            }
            for (j = 0; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    return 0;
}

//int main()
//{
//    int input, i, j;
//    while (scanf("%d", &input) != EOF)
//    {
//        for (i = 0; i < input; i++)
//        {
//            for (j = 0; j < input; j++)
//            {
//                if (i == j || i + j == input - 1)
//                    printf("*");
//                else
//                    printf(" ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}