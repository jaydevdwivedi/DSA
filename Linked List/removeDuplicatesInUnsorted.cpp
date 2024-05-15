#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
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
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

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

Node* removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    map <int, bool> visited;
    Node* temp = head;
    Node* current = temp;
    Node* prev = NULL;

    while (current != NULL)
    {
        cout << "inside while loop " << endl;
        cout << "visited[current]: " << visited[current->data] << endl;
        cout << "current: " << current->data << endl;
        if (visited[current->data] == true)
        {
            cout << "inside if condition " << endl;
            Node* node = prev->next;
            prev->next = prev->next->next;
            current=prev->next;
            delete node;
        }
        else {
            cout << "Inside ELSE condition" << endl;
            visited[current->data] = true;
            cout << "visited[current]: " << visited[current->data] << endl;
            prev = current;
            current = current->next;
        }
        cout << endl;
    }
    // print(temp);
    return temp;
}
int main()
{
    Node *node1 = new Node(4);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 5);
    insertAtTail(tail, 2);
    insertAtTail(tail, 4);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    print(head);

    head = removeDuplicates(head);
    print(head);
    return 0;
}