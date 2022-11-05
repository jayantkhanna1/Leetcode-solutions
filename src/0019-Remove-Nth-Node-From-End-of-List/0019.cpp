
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* h = new ListNode(-1);
        h->next = head;
        ListNode* p = h, *q = h;
        ++n;
        while (n-- != 0)
        {
            q = q->next;
        }
        while (q != nullptr)
        {
            p = p->next;
            q = q->next;
        }
        ListNode* retNode = h->next;
        delete h;
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        return retNode;
    }
};
