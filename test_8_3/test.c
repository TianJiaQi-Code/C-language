struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    //��cur==NULLʱ����ѭ��
    while (cur)
    {
        if (cur->val == val)//ɾ��
        {
            if (cur == head)
            {
                //ͷɾ
                head = cur->next;
                free(cur);
                cur = head;
            }
            else
            {
                //����ɾ
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else//ָ����һ��
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}