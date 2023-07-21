#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

int CheckCapacity(Contact* pc);

void LoadContact(Contact* pc)
{
	//���ļ�
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//���ļ�
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		if (0 == CheckCapacity(pc))
			return;
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//��̬�İ汾
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
	//�ļ��б������Ϣ���ص�ͨѶ¼��
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
			printf("���ݳɹ�\n");
			return 1;
		}
	}
	return 1;
}

//��̬�İ汾
void AddContact(Contact* pc)
{
	assert(pc);
	if (0 == CheckCapacity(pc))
	{
		return;
	}
	printf("����������:");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("�ɹ�������ϵ��\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	//��ӡ�б���
	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	//��ӡ����
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
			return i;//�ҵ���
		}
	}
	return -1;//�Ҳ���
}

void DelContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	assert(pc);
	//ɾ��
	printf("������Ҫɾ���˵�����:");
	scanf("%s", name);
	//�ҵ�Ҫɾ������
	int del = FindByName(pc, name);
	if (del == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	int i = 0;
	//ɾ������Ϊdel����ϵ��
	for (i = del; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("�ɹ�ɾ����ϵ��\n");
}