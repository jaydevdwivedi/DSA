#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q) {

    if (q.empty()) {
        return;
    }

    int front = q.front();
    q.pop();
    reverse(q);
    q.push (front);
}

void print (queue<int> q) {
    if (q.empty()) cout << "Queue is empty.";
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