#include <stdio.h>

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int num = 2;
        int sum = 0;
        while (n)
        {
            sum += num;
            num += 3;
            n--;
        }
        printf("%d", sum);
        return 0;
    }
}