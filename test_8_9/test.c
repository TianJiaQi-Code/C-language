//#include <stdio.h>
//#include <stddef.h>
//
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//
////将结构体首地址设置为0，则结构体成员的地址就是对应的偏移量
//#define OFFSETOF(struct_name, member_name) (int)&(((struct_name*)0)->member_name)
//
//int main()
//{
//	printf("%d\n", OFFSETOF(struct S, c1));
//	printf("%d\n", OFFSETOF(struct S, i));
//	printf("%d\n", OFFSETOF(struct S, c2));
//
//	printf("%zd\n", offsetof(struct S, c1));
//	printf("%zd\n", offsetof(struct S, i));
//	printf("%zd\n", offsetof(struct S, c2));
//	return 0;
//}

#include <stdio.h>

#define SWAP(n) n = (((n & 0xaaaaaaaa) >> 1) + ((n & 0x55555555) << 1))

int main()
{
	int n = 10;
	printf("%d\n", SWAP(n));
	return 0;
}