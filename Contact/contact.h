#pragma once

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
#define INC_SZ 2

enum OPTION
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//���͵�����
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼
//��̬�汾
typedef struct Contact
{
	PeoInfo* data;//ָ���˴�����ݵĿռ�
	int sz;//��¼��ǰ�ŵ���ЧԪ�صĸ���
	int capacity;//ͨѶ¼��ǰ���������
}Contact;

//��������
//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//������ϵ��
void AddContact(Contact* pc);
//��ʾ������ϵ�˵���Ϣ
void ShowContact(const Contact* pc);
//ɾ��ָ����ϵ��
void DelContact(Contact* pc);
//����ָ����ϵ��
void SearchContact(const Contact* pc);
//�޸�ָ����ϵ��
void ModifyContact(Contact* pc);
//����ͨѶ¼
void DestroyContact(Contact* pc);
//����ͨѶ¼��Ϣ���ļ�
void SaveContact(Contact* pc);