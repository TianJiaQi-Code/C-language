#include <stdio.h>
#include <assert.h>

// Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root)
{
	// �ǿգ�����0
	if (root == NULL)
		return 0;
	// ��Ҷ�ӣ�����1
	if (root->left == NULL && root->right == NULL)
		return 1;
	// ���ǿ�Ҳ����Ҷ�ӣ�����������+������
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

// ��k��Ľڵ����
int TreeKLevel(BTNode* root, int k)
{
	assert(k > 0);
	// �ǿգ�����0
	if (root == NULL)
		return 0;
	// ���ǿգ������ǵ�k�㣬����1
	if (k == 1)
		return 1;
	// ���ǿ�Ҳ���ǵ�k��
	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}

int main()
{
	return 0;
}