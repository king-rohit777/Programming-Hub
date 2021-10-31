#include <bits/stdc++.h>
using namespace std;

class LinkedList
{

    struct Node
    {
        int data;
        Node *next;
        Node(int d)
        {
            data = d;
            next = NULL;
        }
    };
    Node *head, *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtBeginning(int data)
    {

        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            Node *current = head;
            tail->next = newNode; // TC : o(1)
            tail = tail->next;
            // TC : o(n)
            //  while (current->next != NULL)
            //  {
            //      current = current->next;
            //  }
            //  current->next = newNode;
        }
    }

    void print()
    {

        if (head == NULL)
        {
            cout << "LIst is Empty" << endl;
            return;
        }
        else
        {
            Node *current = head;
            while (current != NULL)
            {
                cout << current->data << "->";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
    }

    void deleteNode(int dataToDel)
    {

        Node *current = head;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else if (head->data == dataToDel)
        {
            head = head->next;
            free(current);
            return;
        }
        else
        {
            while (current->next != NULL && current->next->data != dataToDel)
            {
                current = current->next;
            }
            if (current->next == NULL)
            {
                cout << "Data does not exist" << endl;
                return;
            }
            else
            {
                Node *nodetoDel = current->next;
                current->next = current->next->next;
                free(nodetoDel);
            }
        }
    }
};

int main()
{
    LinkedList ll = LinkedList();
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtBeginning(40);
    ll.insertAtBeginning(50);
    ll.print();
    ll.deleteNode(50);
    ll.print();
    ll.deleteNode(10);
    ll.print();
    ll.deleteNode(30);
    ll.print();
}