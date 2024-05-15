#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node* random;

    node(int val) {
        this->data = val;
        this->next = NULL;
        this->random = NULL;
    } 
};

void insertAtHead (node* &head, int val) {
    node* newNode = new node(val);
    if (head == NULL) {
        head = newNode;
        newNode->random = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
} 

void insertAtTail (node* &head, node* &tail, int val) {
    node* newNode = new node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }

    tail->next = newNode;
    tail = newNode;
}
void print(node* head) {
    if (head == NULL) {
        cout << "Linked List is empty" << endl;
    }
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printRandom(node* head) {
    while (head != NULL) {
        cout << head->random->data << " ";
        head = head->next;
    }
    cout << endl;
}

void setRandomPointer (node* &head, node* & tail) {
    node* temp = head;
    temp->random = head->next->next->next;
    temp = temp->next;

    temp->random = tail;
    temp = temp->next;

    temp->random = head;
    temp = temp->next;

    temp->random = head->next;
    temp = temp->next;

    temp->random = head->next->next;
}

node* copyList (node* head) {
    node* cloneHead = NULL;
    node* cloneTail = NULL;

    node* temp = head;

    // step-1: clone next links
    while (temp != NULL) {
        insertAtTail(cloneHead, cloneTail,  temp->data);
        temp = temp->next;
    }


    // step 2: create a map
    unordered_map<node*, node*> oldToNewNode;

    node* originalNode = head;
    node* cloneNode = cloneHead;


    while (originalNode != NULL && cloneNode != NULL) {
        node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    // Step 3: map the random pointers
    temp = head;

    while (temp != NULL){
        if (temp->next != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            else {
                temp->next = temp->random;
            }
        }
        temp = temp->next;
        if (temp != NULL) {
            temp = temp->next;
        }
    }


    // Step 4: Revert the changes made in step 2
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL) {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode != NULL) {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;

    }
    // step 5: return answer
    return cloneHead;
}
int main() {
    node* node1 = new node(5);
    node* head = node1;
    node* tail = node1;

    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    setRandomPointer(head, tail);

    cout << "Original Linked List:" << endl;
    print(head);
    cout << endl;

    cout << "Random Linked List:" << endl;
    printRandom(head);
    cout << endl;

    node* head2 = copyList(head);

    cout << "Cloned Linked List:" << endl;
    print(head2);
    cout << endl;
    
    cout << "Cloned Random Linked List:" << endl;
    printRandom(head2);
    cout << endl;
    
    return 0;
}