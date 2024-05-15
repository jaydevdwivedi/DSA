#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* temp)
{
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data)
{
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);

    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}

void insertAtPosition (Node* &head, Node* &tail, int index, int data) {
    Node* temp = head;

    if(index == 0) {
        insertAtHead(head, data);
        return;
    }

    int count = 0;

    while (count < index-1)
    {
        temp = temp->next;
        count++;
    }
    
    if(temp->next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* &head) {
    
    // deleting first node
    if (position == 0) {
        Node* temp = head;
        head = head ->next;

        // Memory free start node
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;

        int count = 0;
        while (count < position -1) {
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);

    // insertAtHead(head, 20);
    // print(head);
    // insertAtHead(head, 30);
    // print(head);
    // insertAtHead(head, 40);
    // print(head);
    // insertAtHead(head, 50);
    // print(head);

    insertAtTail(tail, 20);
    print(head);
    insertAtTail(tail, 40);
    print(head);
    insertAtTail(tail, 50);
    print(head);
    insertAtPosition(head, tail, 2, 30);
    print(head);
    insertAtPosition(head, tail, 3, 60);
    print(head);
    insertAtPosition(head, tail, 0, 70);
    print(head);
    insertAtPosition(head, tail, 7, 80);
    print(head);


    return 0;
}