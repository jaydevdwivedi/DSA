#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr = NULL;
    int length = 0;

public:
    Stack()
    {
        arr = NULL;
        length = 0;
    }
    Stack(int val)
    {
        push(val);
    }

    void push(int val)
    {
        if (this->arr == NULL)
        {
            this->arr = new int;
            this->arr[0] = val;
            this->length++;
            return;
        }
        this->arr = new int[this->length + 1];
        this->arr[this->length] = val;
        this->length++;
    }

    void pop()
    {
        if (this->arr == NULL)
        {
            return;
        }
        this->arr = (int *)realloc(this->arr, (this->length - 1));
        delete &arr[length];
        this->length--;
    }

    int top()
    {
        if (this->arr == NULL)
        {
            return -1;
        }
        return this->arr[this->length - 1];
    }

    bool empty()
    {
        if (this->arr == NULL)
        {
            return true;
        }
        return false;
    }

    int size()
    {
        return this->length;
    }
};

int main()
{
    Stack s;

    s.push(1);
    cout << "top: " << s.top() << endl;
    
    s.push(2);
    cout << "top: " << s.top() << endl;

    s.push(3);
    cout << "top: " << s.top() << endl;

    s.push(4);
    cout << "top: " << s.top() << endl;
    cout << endl;

    Stack s2;
    // cout << "s2.top:" << s2.top() << endl;

    s2.push(10);
    cout << "s2.top: " << s2.top() << endl;

    s2.push(20);
    cout << "s2.top: " << s2.top() << endl;
    cout << "s2.size: " << s2.size() << endl;

    if (s2.empty()) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack s2 is not empty." << endl;
    }

    return 0;
}