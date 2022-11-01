

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dumHead = new ListNode(0);
        ListNode* p = dumHead;
        int add = 0;
        while (l1 || l2 || add)
        {
            int val = get_value(l1) + get_value(l2) + add;
            add = val / 10;
            p->next = new ListNode(val % 10);
            p = p->next;
            l1 = get_p(l1);
            l2 = get_p(l2);
        }
        ListNode* ret = dumHead->next;
        delete dumHead;
        return ret;
    }
private:
    int get_value(ListNode* l)
    {
        if (l != nullptr)
        {
            return l->val;
        }
        else
        {
            return 0;
        }
    }
    ListNode* get_p(ListNode* l)
    {
        if (l != nullptr)
        {
            return l->next;
        }
        else
        {
            return nullptr;
        }
    }
};

void deleteListNode(ListNode *l1)
{
    while (l1 != nullptr)
    {
        ListNode* p = l1->next;
        delete l1;
        l1 = p;
    }
}
