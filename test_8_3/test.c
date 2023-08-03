struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    //当cur==NULL时结束循环
    while (cur)
    {
        if (cur->val == val)//删除
        {
            if (cur == head)
            {
                //头删
                head = cur->next;
                free(cur);
                cur = head;
            }
            else
            {
                //正常删
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else//指向下一个
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}