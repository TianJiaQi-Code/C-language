#include <stdio.h>

int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;


    return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
	return 0;
}