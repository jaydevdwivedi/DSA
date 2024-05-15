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
            this->next = NULL;
        }
        cout << "Memory is free for " << value << endl;
    }
};

void print(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;

    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(node *&head, node *&tail, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void insertAtTail (node* &head, node*& tail, int data) {
    if (head == NULL) {
        insertAtHead(head, tail, data);
        return;
    }

}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node1->next = head;
    node *tail = node1;
    print(head);

    insertAtHead(head, tail, 20);
    print(head);

    insertAtHead(head, tail, 30);
    print(head);


    return 0;
}