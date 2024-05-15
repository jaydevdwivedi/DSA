#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node (int d) {
        this->data = d;
        this->next = NULL;
    }
};

void print(node*head) {
    while (head != NULL) {
        cout <<head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* reverse (node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;

}

int main() {
    node* node1 = new node(3);
    node* head = node1;
    head->next = new node(5);
    head->next->next = new node(7);
    head->next->next->next = new node(9);
    print(reverse(head));
    return 0;
}