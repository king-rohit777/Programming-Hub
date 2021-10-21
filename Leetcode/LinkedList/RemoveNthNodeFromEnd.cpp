/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head;
        int i = 0;
        while (p != NULL)
        {
            i++;
            p = p->next;
        }

        if (i == 1)
            return NULL;

        ListNode *q = head, *r = NULL;
        int t = i - n;
        if (t == 0)
            return head->next;
        for (int j = 0; j < t; j++)
        {
            r = q;
            q = q->next;
        }

        r->next = q->next;
        return head;
    }
};