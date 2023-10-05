#include "BinaryTree.h"
#include "queue.h"

BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->val = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeKLevel(BTNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}

void TreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	free(root);
}

BTNode* TreeFind(BTNode* root, int x)
{
	if (root == NULL)
		return NULL;
	if (root->val == x)
		return root;

	BTNode* ret = NULL;
	ret = TreeFind(root->left, x);
	if (ret)
		return ret;
	ret = TreeFind(root->right, x);
	if (ret)
		return ret;

	return NULL;
}

void LevelOrder(BTNode* root)
{
	Que q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->val);
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
		QueuePop(&q);
	}
	printf("\n");

	QueueDestroy(&q);
}

int TreeComplete(BTNode* root)
{
	Que q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		QueuePop(&q);
	}
	// 已经遇到空节点，如果队列中后面的节点还有非空，就不是完全二叉树
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}