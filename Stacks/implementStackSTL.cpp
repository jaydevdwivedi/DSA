#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;

    s.push(1);
    cout << "top: " << s.top() << endl;

    s.push(2);
    cout << "top: " << s.top() << endl;

    s.pop();
    cout << "top: " << s.top() << endl;

    // s.pop();

    // Give error as no element is present
    // cout << "top: " << s.top() << endl;

    if (s.empty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Stack is not empty with size " << s.size() << ", top " << s.top() << endl;
    }

    return 0;
}