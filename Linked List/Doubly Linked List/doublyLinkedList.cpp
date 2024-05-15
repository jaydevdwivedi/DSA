#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *head)
{
    cout << "Printing Linked List" << endl;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtHead(Node*& head, int data)
{
    Node *temp = new Node(data);

    if (head == NULL) {
        cout << "Inside if condition" << endl;
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail (Node* &tail, int data) {
    Node* temp = new Node(data);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* head, Node* tail, int position, int data) {
    // Inserting at first position
    if (position == 0) {
        insertAtHead(head, data);
        return;
    }
    
    // traversing to the given position
    int count = 0;
    while (count < position) {
        head = head->next;
    }

    // Inserting at last position
    if (head->next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    // Inserting at other intermediate positions
    Node* temp= new Node(data);
    temp->next = head->next;
    head->next = temp;

}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);

    insertAtHead(head, 20);
    print(head);
    insertAtHead(head, 30);
    print(head);
    insertAtHead(head, 40);
    print(head);
    insertAtTail(tail, 50);
    print(head);
    insertAtTail(tail, 60);
    print(head);
    insertAtTail(tail, 70);
    print(head);
    return 0;
}