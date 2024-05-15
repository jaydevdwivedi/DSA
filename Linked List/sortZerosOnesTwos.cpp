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

void sort(node *&head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
        {
            twoCount++;
        }
        temp = temp->next;
    }
    cout << zeroCount << " ";
    cout << oneCount << " ";
    cout << twoCount << " ";
    cout << endl;

    temp = head;
    while (zeroCount > 0)
    {
        temp->data = 0;
        temp = temp->next;
        zeroCount--;
    }

    while (oneCount > 0)
    {
        temp->data = 1;
        temp = temp->next;
        oneCount--;
    }
    while (twoCount > 0)
    {
        temp->data = 2;
        temp = temp->next;
        twoCount--;
    }
    // print(head);           
}
int main()
{
    node *node1 = new node(2);
    node *head = node1;

    insertAtHead(head, 0);
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    print(head);

    sort(head);
    print(head);
    return 0;
}