bool isUnivalTree(struct TreeNode* root)
{
    // ��
    if (root == NULL)
        return true;
    // �Ƚ�
    if (root->left != NULL && root->val != root->left->val)
        return false;
    if (root->right != NULL && root->val != root->right->val)
        return false;

    return isUnivalTree(root->left) && isUnivalTree(root->right);
}