#include <stdio.h>

int main()
{
    int m;
    while (scanf("%d", &m) != EOF)
    {
        int start = m * m - m + 1;
        printf("%d", start);
        int i = 0;
        for (i = 1; i < m; i++)
        {
            printf("+%d", start + 2 * i);
        }
        printf("\n");
    }
    return 0;
}