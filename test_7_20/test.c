﻿//#include <stdio.h>

//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};

//printf("%d\n", sizeof(struct A));

////一个例子
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//struct S s = { 0 };
//s.a = 10;
//s.b = 12;
//s.c = 3;
//s.d = 4;
////空间是如何开辟的？

//#include <stdio.h>
//
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	return 0;
//}

//enum Day//星期
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//enum Sex//性别
//{
//	MALE,
//	FEMALE,
//	SECRET
//};
//enum Color//颜色
//{
//	RED,
//	GREEN,
//	BLUE
//};

//enum Color//颜色
//{
//	RED = 1,
//	GREEN = 2,
//	BLUE = 4
//};

//enum Color//颜色
//{
//	RED = 1,
//	GREEN = 2,
//	BLUE = 4
//};
//
//enum Color clr = GREEN;//只能拿枚举常量给枚举变量赋值，才不会出现类型的差异。
//clr = 5;               //ok??

////联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
//
////联合变量的定义
//union Un un;
////计算连个变量的大小
//printf("%d\n", sizeof(un));

//union Un
//{
//	int i;
//	char c;
//};
//union Un un;
//// 下面输出的结果是一样的吗？
//printf("%d\n", &(un.i));
//printf("%d\n", &(un.c));
////下面输出的结果是什么？
//un.i = 0x11223344;
//un.c = 0x55;
//printf("%x\n", un.i);

#include <stdio.h>

union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
//下面输出的结果是什么？

int main()
{
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));

	return 0;
}