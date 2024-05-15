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

void print(node* tail) {
    node* temp = tail;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != tail) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode (node* &tail, int value) {
    if (tail == NULL) {
        cout << "List is empty " << endl;
    }
    else {
        // assumning that value is present in the linked list
        node* prev = tail;
        node* curr = prev->next;
        while (curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (tail == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (prev == curr) {
            tail = NULL;
        }
        else if (tail == curr) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    node* tail = NULL;
    // Insertion in empty list
    insertNode(tail, 5, 3);
    print(tail);
    deleteNode(tail, 3);
    print(tail);
    return 0;
}