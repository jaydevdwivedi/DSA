#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

void print(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtTail(ListNode *&head, ListNode *&tail, int data)
{
    ListNode *newNode = new ListNode(data);
    if (tail == NULL)
    {
        tail = newNode;
        head = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

long long int getLength(ListNode *head)
{

    long long int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

ListNode *rotateRight(ListNode *head, int k)
{

    if (head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }
    // k = 2, length = 2
    long long int length = getLength(head);
    // cout << "len:" << length << ", ";
    k = k % length;

    if (k == 0) {
        return head;
    }

    cout << "modified k:" << k << endl;
    long long int newK = length - k;
    cout << "newK:" << newK << endl;
    ListNode *temp = head;

    while (newK)
    {
        cout << "Inside first while loop" << endl;
        temp = temp->next;
        newK--;
    }
    ListNode *ans = temp;
    while (temp->next != ans)
    {
        cout << "Iteration changed" << endl;
        if (temp->next == NULL)
        {
            cout << "First IF consition" << ", ";
            temp->next = head;
        }
        if (temp->next != ans)
        {
            cout << "Second IF condition";
            temp = temp->next;
        }
        cout << endl;
    }
    temp->next = NULL;
    return ans;
}

int main()
{
    // ListNode* node1 = new ListNode(0);
    ListNode *head = NULL;
    ListNode *tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    // insertAtTail(head, tail, 4);
    // insertAtTail(head, tail, 5);
    print(head);

    int k = 2;
    print(rotateRight(head, k));
    // cout << endl;
    return 0;
}