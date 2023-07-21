#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

int CheckCapacity(Contact* pc);

void LoadContact(Contact* pc)
{
	//打开文件
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//读文件
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		if (0 == CheckCapacity(pc))
			return;
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}

//动态的版本
void InitContact(Contact* pc)
{
	assert(pc);
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	//文件中保存的信息加载到通讯录中
	LoadContact(pc);
}

int CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			perror("CheakCapacity");
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
			return 1;
		}
	}
	return 1;
}

//动态的版本
void AddContact(Contact* pc)
{
	assert(pc);
	if (0 == CheckCapacity(pc))
	{
		return;
	}
	printf("请输入名字:");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("成功增加联系人\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	//打印列标题
	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	//打印数据
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

static int FindByName(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;//找到了
		}
	}
	return -1;//找不到
}

void DelContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	assert(pc);
	//删除
	printf("请输入要删除人的名字:");
	scanf("%s", name);
	//找到要删除的人
	int del = FindByName(pc, name);
	if (del == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	int i = 0;
	//删除坐标为del的联系人
	for (i = del; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("成功删除联系人\n");
}