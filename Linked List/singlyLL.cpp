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
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
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

bool isLoopPresent (Node* head) {
    if (head == NULL) {
        return false;
    }

    map<Node*, bool> visited;
    Node* temp = head;
    while (temp != NULL) {
        if (visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node* floydDetect (Node* head) {
    if (head == NULL) 
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;
        if (slow == fast) {
            cout << "Present at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

Node* findStartingNodeOfLoop(Node* head) {
    if (head == NULL) 
    {
        return NULL;
    }
    Node* intersection = floydDetect(head);
    Node* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop (Node* head) {
    if (head == NULL) {
        return;
    }

    Node* startOfLoop = findStartingNodeOfLoop(head);
    Node* temp = startOfLoop;
    while (temp->next != startOfLoop) {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail =  node1;
    // insertAtHead(head, 20);
    // insertAtHead(head, 30);
    // insertAtHead(head, 40);
    print(head);
    tail->next = head->next;
    // if (isLoopPresent(head)) {
    //     cout << "Loop is present!" << endl;
    // }
    // else  {
    //     cout << "Loop is not present" << endl;
    // }
    // Node* loopIntersect = floydDetect(head);
    // cout << "Slow and Fast meet at " << loopIntersect->data;
    Node* res = findStartingNodeOfLoop(head);
    cout << "Starting point of the loop is: " <<  res->data << endl;
    removeLoop(head);
    print(head);
    // print(head);
    return 0;
}