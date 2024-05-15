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

ListNode *deleteDuplicates(ListNode *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    stack<int> s;
    ListNode *newHead = head;
    ListNode *temp = newHead;
    s.push(head->val);

    head = head->next;
    while (head != NULL)
    {
        if (head->val != s.top())
        {
            ListNode *newNode = new ListNode(head->val);
            temp->next = newNode;
            temp = temp->next;
            s.pop();
            s.push(head->val);
        }
        head = head->next;
    }
    return newHead;
}

int main()
{

    return 0;
}