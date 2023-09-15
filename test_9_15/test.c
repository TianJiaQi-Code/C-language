#include <stdio.h>
#include <assert.h>

// 叶子节点个数
int TreeLeafSize(BTNode* root)
{
	// 是空，返回0
	if (root == NULL)
		return 0;
	// 是叶子，返回1
	if (root->left == NULL && root->right == NULL)
		return 1;
	// 不是空也不是叶子，返回左子树+右子树
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

// 第k层的节点个数
int TreeKLevel(BTNode* root, int k)
{
	assert(k > 0);
	// 是空，返回0
	if (root == NULL)
		return 0;
	// 不是空，并且是第k层，返回1
	if (k == 1)
		return 1;
	// 不是空也不是第k层
	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}

int main()
{
	return 0;
}