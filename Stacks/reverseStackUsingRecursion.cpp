#include<bits/stdc++.h>
using namespace std;

void insertAtBottom (stack<int> &s, int val){
    // base case
    if (s.empty()) {
        s.push(val);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom(s, val);
    s.push(num);
}

void reverse (stack<int>& s) {
    // base case
    if (s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    reverse(s);
    insertAtBottom(s, num);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    stack<int> org = s;

    cout << "Original:";
    while(!org.empty()){
        cout << org.top() << " ";
        org.pop();
    }   
    cout << endl;

    reverse(s);
    cout << "Reversed:";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}