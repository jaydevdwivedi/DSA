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
        cout << "Printing List: ";
        cout << head->data << " " << endl;
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

node* merge(node *head1, node *head2, node *forward1, node *forward2)
{

    // base case
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }

    forward1 = head1->next;
    forward2 = head2->next;
    head1->next = head2;
    head2->next = forward1;
    cout << "RECURCIVE CALL" << endl;
    merge(forward1, forward2, forward1->next, forward2->next);
    return head1;
}

int main()
{

    node *node1 = new node(10);
    node *head1 = node1;

    insertAtHead(head1, 8);
    insertAtHead(head1, 6);
    insertAtHead(head1, 4);
    insertAtHead(head1, 2);

    node *node2 = new node(9);
    node *head2 = node2;

    insertAtHead(head2, 7);
    insertAtHead(head2, 5);
    insertAtHead(head2, 3);
    insertAtHead(head2, 1);

    print(head1);
    print(head2);

    head1 = merge(head1, head2, head1->next, head2->next);
    cout << "Recursion over!" << endl;
    print(head1);
    cout << "After print" << endl;

    return 0;
}