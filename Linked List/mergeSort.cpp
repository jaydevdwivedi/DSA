#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtHead(node *&head, int d)
{

    // new node create
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&tail, int d)
{
    // new node create
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void print(node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(node *&tail, node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    node *nodeToInsert = new node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

void deletenode(int position, node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        node *curr = head;
        node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

node* findMid (node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }   
    return slow;
}

node* merge (node* left, node* right) {
    if (left == NULL) {
        return right;
    }
    else if (right == NULL) {
        return left;
    }  

    node* ans = new node(-1);
    node* temp = ans;

    while (left != NULL && right != NULL) {
        if (left ->data < right->data) {
            temp->next = left;
            temp= left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

node* mergeSort (node* head) {
    // base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // break linked list into two halves
    node* mid = findMid(head);
    
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node* result = merge(left, right);
    return result;
}

int main()
{
    node* node1 = new node(9);
    node* head = node1;
    node* tail =  node1;
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 5);
    insertAtHead(head, 3);
    print(head);

    head = mergeSort(head);
    cout << "Sorted List:" << endl;
    print(head);

    return 0;
}