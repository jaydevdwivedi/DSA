#include<bits/stdc++.h>
using namespace std;

void solve (stack<int> &st, int count, int size) {
    // base case
    if (count == size/2) {
        st.pop();
        return;
    }

    // Recursive call
    int num = st.top();
    st.pop();
    solve (st, count+1, size);
    st.push(num);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    solve(s, 0, s.size());

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}