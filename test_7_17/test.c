//struct tag
//{
//	member-list;
//}variable-list;

//struct Stu
//{
//	char name[20];//名字
//	int age;//年龄
//	char sex[5];//性别
//	char id[20];//学号
//}; //分号不能丢

////匿名结构体类型
//struct
//{
//	int a;
//	char b;
//	float c;
//}x;
//struct
//{
//	int a;
//	char b;
//	float c;
//}a[20], * p;

////在上面代码的基础上，下面的代码合法吗？
//p = &x;

////代码1
//struct Node
//{
//	int data;
//	struct Node next;
//};
////可行否？
//如果可以，那sizeof(struct Node)是多少？

////代码2
//struct Node
//{
//	int data;
//	struct Node* next;
//};

////代码3
//typedef struct
//{
//	int data;
//	Node* next;
//}Node;
////这样写代码，可行否？
////解决方案：
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;

//struct Point
//{
//	int x;
//	int y;
//}p1; //声明类型的同时定义变量p1
//struct Point p2; //定义结构体变量p2
////初始化：定义变量的同时赋初值。
//struct Point p3 = { x, y };
//struct Stu        //类型声明
//{
//	char name[15];//名字
//	int age;      //年龄
//};
//struct Stu s = { "zhangsan", 20 };//初始化
//struct Node
//{
//	int data;
//	struct Point p;
//	struct Node* next;
//}n1 = { 10, {4,5}, NULL }; //结构体嵌套初始化
//struct Node n2 = { 20, {5, 6}, NULL };//结构体嵌套初始化