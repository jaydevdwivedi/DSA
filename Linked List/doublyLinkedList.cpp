#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for data: " << val << endl;
    }
};

int getLength(node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return 0;
    }
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void print(node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(node *&head, node *&tail, int data)
{
    if (tail == NULL)
    {
        node *temp = new node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        node *temp = new node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPos(node *&head, node *&tail, int data, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int i = 0;
    node *temp = head;
    while (i < pos - 1)
    {
        i++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }
    // temp = temp->prev;
    node *newNode = new node(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteNode(node *&head, node* &tail, int pos)
{
    if (pos == 0)
    {
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *current = head;
        node *previous = NULL;

        int i = 0;
        while (i < pos)
        {
            previous = current;
            current = current->next;
            i++;
        }
        if (current->next == NULL) {
            tail = previous;
        }
        current->prev = NULL;
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}
int main()
{
    // node *node1 = new node(10);
    node *head = NULL;
    node *tail = NULL;

    print(head);
    cout << "length: " << getLength(head) << endl;

    insertAtHead(head, tail, 20);
    print(head);
    cout << "length: " << getLength(head) << endl;

    insertAtTail(head, tail, 30);
    print(head);
    cout << "length: " << getLength(head) << endl;

    insertAtPos(head, tail, 40, 2);
    print(head);
    cout << "length: " << getLength(head) << endl;

    insertAtPos(head, tail, 50, 1);
    print(head);
    cout << "length: " << getLength(head) << endl;

    insertAtPos(head, tail, 60, 4);
    print(head);
    cout << "length: " << getLength(head) << endl;

    insertAtPos(head, tail, 70, 0);
    print(head);
    cout << "length: " << getLength(head) << endl;

    deleteNode(head, tail,  5);
    cout << "Printing Linked List: " << endl;
    print(head);
    cout << "length: " << getLength(head) << endl;

    return 0;
}