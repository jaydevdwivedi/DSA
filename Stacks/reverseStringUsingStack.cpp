#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<char> s;
    string str = "Dwivedi";

    for (int i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }

    str = "";

    while(!s.empty()) {
        str += s.top();
        s.pop();
    }
    cout << "Reversed string: " << str << endl;

    return 0;
}