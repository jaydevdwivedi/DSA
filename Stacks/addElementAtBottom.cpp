#include<bits/stdc++.h>
using namespace std;

void addAtBottom(stack<int> &s, int val) {
    // s: 0, 1, 2, 3, 4 <-top
    // base case
    if(s.empty()){
        s.push(val);
        return;
    }

    int num = s.top();
    s.pop();

    addAtBottom(s, val);
    s.push(num);
}

int main() {

    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    addAtBottom(s, 0);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}