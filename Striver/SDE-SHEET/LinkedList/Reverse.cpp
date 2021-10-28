class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == nullptr)
            return head;

        ListNode *prevNode = nullptr, *currNode = head, *nextNode = head->next;

        while (nextNode)
        {
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = prevNode; // handle last node
        return currNode;
    }
};