#include<bits/stdc++.h>
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

node* reverseInKGroups(node* head, int k) {
    cout << "Before reverse, head: " << head->data << endl;
    cout << "Before reverse, head->next: " << head->next->data << endl;
    // base case
    if (head == NULL) {
        return NULL;
    }

    node* curr = head;
    node* prev = NULL;
    node* forward = NULL;
    int i = 0;

    while (curr != NULL && i < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }

    cout << "After reverse, head: " << head->data << endl;

    if (forward != NULL) {
        head -> next = reverseInKGroups(forward, k);
        cout << "On recursive call, head->next: " << head->next->data << endl;
    }

    return prev;
}

int main() {
    node* node1 = new node(2);
    node* head = node1;
    insertAtHead(head, 17);
    insertAtHead(head, 11);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 3);
    print(head);
    
    head = reverseInKGroups(head, 2);
    print(head);
    return 0;
}