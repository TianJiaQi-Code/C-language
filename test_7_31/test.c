struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (head != NULL)
    {
        head = head->next;
        cur->next = prev;
        prev = cur;
        cur = head;
    }
    return prev;
}