#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

// ������ɾ��ģ�ѧϰ�������ṹ
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	int val;
}BTNode;

// �ֶ�����������
BTNode* BuyNode(int x);
// ����������
void TreeDestroy(BTNode* root);
// ������ǰ�����
void PrevOrder(BTNode* root);
// �������������
void InOrder(BTNode* root);
// �������������
void PostOrder(BTNode* root);
// �������
void LevelOrder(BTNode* root);
// �������ڵ����
int TreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root);
// ��������k��ڵ����
int TreeKLevel(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, int x);
// �ж϶������Ƿ�����ȫ������
int TreeComplete(BTNode* root);
// �������ĸ߶�
int TreeHeight(BTNode* root);