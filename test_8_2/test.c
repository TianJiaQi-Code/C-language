//����ѭ��
bool hasCycle(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

//��������Ľ���
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    struct ListNode* curA = headA;
//    struct ListNode* curB = headB;
//    int lenA = 1;
//    int lenB = 1;
//    //����headA�ĳ���
//    while (curA->next)
//    {
//        curA = curA->next;
//        lenA++;
//    }
//    //����headB�ĳ���
//    while (curB->next)
//    {
//        curB = curB->next;
//        lenB++;
//    }
//    //���ཻ��β�ڵ�ĵ�ַ��ͬ��
//    if (curA != curB)
//    {
//        return NULL;
//    }
//    //���㳤�Ȳ�
//    int gap = abs(lenA - lenB);
//    //����headA�ϳ���headB�϶̣�������ǣ��ͻ���
//    struct ListNode* longlist = headA;
//    struct ListNode* shortlist = headB;
//    if (lenA < lenB)
//    {
//        longlist = headB;
//        shortlist = headA;
//    }
//    //�������߲�ಽ
//    while (gap--)
//    {
//        longlist = longlist->next;
//    }
//    //ͬʱ���ҽ���
//    while (longlist != shortlist)
//    {
//        longlist = longlist->next;
//        shortlist = shortlist->next;
//    }
//    return longlist;
//}

//����ָ�
//class Partition
//{
//public:
//    ListNode* partition(ListNode* pHead, int x)
//    {
//        // write code here
//        struct ListNode* ghead;
//        struct ListNode* gtail;
//        struct ListNode* lhead;
//        struct ListNode* ltail;
//        ghead = gtail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        lhead = ltail = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//        struct ListNode* cur = pHead;
//        while (cur)
//        {
//            if (cur->val < x)
//            {
//                ltail->next = cur;
//                ltail = ltail->next;
//            }
//            else
//            {
//                gtail->next = cur;
//                gtail = gtail->next;
//            }
//            cur = cur->next;
//        }
//        ltail->next = ghead->next;
//        //���գ����ܵ��³��ֻ�
//        gtail->next = NULL;
//
//        struct ListNode* head = lhead->next;
//        free(lhead);
//        free(ghead);
//        return head;
//    }
//};