struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur != NULL)
    {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

class PalindromeList
{
public:
    bool chkPalindrome(ListNode* head)
    {
        struct ListNode* list1 = head;
        struct ListNode* mid = middleNode(head);
        struct ListNode* list2 = reverseList(mid);
        while (list2 != NULL)
        {
            if (list1->val != list2->val)
            {
                return false;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
    }
};