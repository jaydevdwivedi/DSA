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
        this->next = this;
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

void print(node *tail)
{
    node *temp = tail;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

pair<node *, node *> splitIntoTwo(node *tail)
{
    node *slow = tail;
    node *fast = tail;
    slow = tail->next;
    fast = tail->next->next;

    cout << "tail: " <<  tail->data << endl;
    cout << "fast: " << fast->data << endl;
    cout << "slow: " << slow->data << endl;
    cout << endl;
    while ((fast != tail) && (slow != tail))
    {
        cout << "fast: " << fast->data << endl;
        cout << "slow: " << slow->data << endl;

        fast = fast->next;
        if (fast != tail)
        {
            fast = fast->next;
        }
        slow = slow->next;
        cout << endl;
    }

    cout << "slow: " << slow->data << endl;
    cout << "fast: " << fast->data << endl;

    fast->next = slow->next;
    cout << "fast->next: " << fast->next->data << endl;
    slow->next = tail->next;
    cout << "slow->next: " << slow->next->data << endl;
    return make_pair(slow, fast);
}

int main()
{
    node *node1 = new node(1);
    node *tail = node1;

    insertNode(tail, 1, 2);
    insertNode(tail, 2, 3);
    insertNode(tail, 3, 4);
    insertNode(tail, 4, 5);
    insertNode(tail, 5, 6);
    print(tail);

    pair<node *, node *> splited = splitIntoTwo(tail);
    print(splited.first);
    print(splited.second);
}