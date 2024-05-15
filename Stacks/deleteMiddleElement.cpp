#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(6); // delete
    s.push(1);
    s.push(2);
    s.push(7);

    int mid = s.size() / 2;
    stack<int> temp;

    cout << "temp: ";
    for (int i = 0; i < mid; i++)
    {
        temp.push(s.top());
        cout << temp.top() << " ";
        s.pop();
    }
    cout << endl;

    s.pop();
    cout << "s.top(): " << s.top() << endl;
    cout << endl;

    cout << "temp: "; 

    while(!temp.empty())
    {
        cout << temp.top() << " ";
        s.push(temp.top());
        // cout << "s.top: " << s.top() << " ";
        temp.pop();
    }
    cout << endl;

   while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}