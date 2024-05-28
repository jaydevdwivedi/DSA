#include<bits/stdc++.h>
using namespace std;

void reverseFirstKElements (queue<int> &q, int k) {
    stack<int> s;

    // add first k elements of queue in stack
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // push stack elements at the last of queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }    

    for (int i = 0; i < q.size()-k; i++) {
        q.push(q.front());
        q.pop();
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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseFirstKElements(q, 3);
    print(q);
    
    return 0;
}