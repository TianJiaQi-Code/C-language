//��ת������
struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
        return NULL;
    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

//��ͬ����
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//�Գƶ�����
bool check(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;
    return check(p->left, q->right) && check(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root)
{
    return check(root, root);
}

//��һ����������
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL)
        return false;

    if (root->val == subRoot->val)
    {
        if (isSameTree(root, subRoot) == true)
            return true;
    }
    if (isSubtree(root->left, subRoot))
        return true;
    if (isSubtree(root->right, subRoot))
        return true;

    return false;
}