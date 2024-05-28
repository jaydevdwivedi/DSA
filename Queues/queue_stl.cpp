#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;

    q.push(2);
    cout << q.back() << endl;

    q.push(3);
    cout << q.back() << endl;

    q.push(4);
    cout << q.back() << endl;

    q.push(1);
    cout << q.back() << endl, cout << endl;
    cout << "Size: " << q.size() << endl;

    q.pop();
    cout << q.front() << endl, cout << endl;
    cout << "Size: " << q.size() << endl;

    if (q.empty()) {
        cout << "Queue is empty." << endl;
    }
    else {
        cout << "Queue is not empty." << endl;
    }
    return 0;
}