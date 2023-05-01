#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//    int age;
//    long long second;
//    scanf("%d", &age);
//    second = age * 3.156e7;
//    printf("%lld", second);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    float weight, height, bmi;
//    scanf("%f %f", &weight, &height);
//    height = height / 100;
//    bmi = weight / (height * height);
//    printf("%.2f", bmi);
//    return 0;
//}

#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int a, b, ret;
	scanf("%d%d", &a, &b);
	ret = max(a, b);
	printf("%d", ret);
	return 0;
}