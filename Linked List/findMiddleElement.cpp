#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void print(node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtHead(node *&head, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

node *find(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *temp = head;
    node *temp2 = head->next;

    while (temp2 != NULL)
    {
        temp2 = temp2->next;
        if (temp2 != NULL)
        {
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return temp;
}

bool checkCircular(node *head)
{
    if (head == NULL)
    {
        return true;
    }
    node *temp = head;
    temp = temp->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    return true;
}

int main()
{
    node *node1 = new node(1);
    node *head = node1;
    print(head);

    insertAtHead(head, 2);
    print(head);
    insertAtHead(head, 3);
    print(head);
    insertAtHead(head, 4);
    print(head);
    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 6);
    print(head);

    if (checkCircular(head))
    {
        cout << "Linked List is circular" << endl;
    }
    else
    {
        cout << "Linked List is not circular" << endl;
    }

    node *ans = find(head);
    cout << "Ans: " << ans->data << endl;

    return 0;
}