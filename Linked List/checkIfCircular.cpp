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

    ~node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for " << value << endl;
    }
};

void insertNode(node *&tail, int element, int data)
{
    // empty list
    if (tail == NULL)
    {
        node *newNode = new node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        node *temp = new node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(node *tail)
{
    node *temp = tail;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool checkCircular(node *tail)
{
    if (tail == NULL)
    {
        return true;
    }
    
    node *temp = tail;
    temp = temp->next;

    while (temp != NULL && temp != tail)
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
    node *node1 = new node(10);
    node *tail = node1;

    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 30, 40);
    insertNode(tail, 40, 50);
    if (checkCircular(tail)) {
        cout << "Linked List is circular" << endl;
    }
    else {
        cout << "Linked List is not circular" << endl;
    }
    return 0;
}