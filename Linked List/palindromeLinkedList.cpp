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

node* reverse (node* &head) {
    node* prev = NULL;
    node* forward = NULL;
    node* curr = head;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    cout << "Reversed list: ";
    print(prev);
    return prev;
}

bool isPalindrome(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && slow != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }

    slow->next = reverse(slow);
    slow = slow->next;
    
    while (head != NULL && slow != NULL) {
        if (head->data != slow->data) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    node *node1 = new node(1);
    node *head = node1;

    insertAtHead(head, 2);
    insertAtHead(head, 3);
    // insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);

    if (isPalindrome(head)) {
        cout << "List is plaindrome" << endl;
    }
    else {
        cout << " List is Not Palindrome" << endl;
    }
    return 0;
}