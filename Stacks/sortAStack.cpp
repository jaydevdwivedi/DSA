#include<bits/stdc++.h>
using namespace std;

void sort (stack<int> &s);
void sortedInsert(stack<int> &s, int val);

int main() {
    stack<int> s;
    s.push(6);
    s.push(2);
    s.push(9);
    s.push(1);

    sort(s);
    cout << "Sorted" << endl;
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    return 0;
}

void sort (stack<int> &s) {
    // base case
    if (s.empty()) {
        return;
    }

    // Recursive call
    int num = s.top();
    s.pop();
    sort(s);

    sortedInsert(s, num);
}

void sortedInsert(stack<int> &s, int val) {
    // base case
    if ((s.empty()) || (!s.empty() && s.top() < val)) {
        s.push(val);
        return;
    }

    int num = s.top();
    s.pop();

    sortedInsert(s, val);
    s.push(num);
}