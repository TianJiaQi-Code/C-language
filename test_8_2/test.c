//链表循环
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

//两个链表的交集
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    struct ListNode* curA = headA;
//    struct ListNode* curB = headB;
//    int lenA = 1;
//    int lenB = 1;
//    //计算headA的长度
//    while (curA->next)
//    {
//        curA = curA->next;
//        lenA++;
//    }
//    //计算headB的长度
//    while (curB->next)
//    {
//        curB = curB->next;
//        lenB++;
//    }
//    //不相交（尾节点的地址不同）
//    if (curA != curB)
//    {
//        return NULL;
//    }
//    //计算长度差
//    int gap = abs(lenA - lenB);
//    //假设headA较长，headB较短，如果不是，就互换
//    struct ListNode* longlist = headA;
//    struct ListNode* shortlist = headB;
//    if (lenA < lenB)
//    {
//        longlist = headB;
//        shortlist = headA;
//    }
//    //长的先走差距步
//    while (gap--)
//    {
//        longlist = longlist->next;
//    }
//    //同时走找交点
//    while (longlist != shortlist)
//    {
//        longlist = longlist->next;
//        shortlist = shortlist->next;
//    }
//    return longlist;
//}

//链表分割
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
//        //不空，可能导致出现环
//        gtail->next = NULL;
//
//        struct ListNode* head = lhead->next;
//        free(lhead);
//        free(ghead);
//        return head;
//    }
//};