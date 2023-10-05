#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

// 不是增删查改，学习二叉树结构
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	int val;
}BTNode;

// 手动构建二叉树
BTNode* BuyNode(int x);
// 二叉树销毁
void TreeDestroy(BTNode* root);
// 二叉树前序遍历
void PrevOrder(BTNode* root);
// 二叉树中序遍历
void InOrder(BTNode* root);
// 二叉树后序遍历
void PostOrder(BTNode* root);
// 层序遍历
void LevelOrder(BTNode* root);
// 二叉树节点个数
int TreeSize(BTNode* root);
// 二叉树叶子节点个数
int TreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int TreeKLevel(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, int x);
// 判断二叉树是否是完全二叉树
int TreeComplete(BTNode* root);
// 二叉树的高度
int TreeHeight(BTNode* root);