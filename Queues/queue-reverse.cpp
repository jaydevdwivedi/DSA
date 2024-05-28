#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q) {
    stack<int> s;

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

void print (queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(6);
    q.push(2);
    q.push(1);
    q.push(3);
    q.push(4);

    print(q);
    reverse(q);
    print(q);
    
    return 0;
}