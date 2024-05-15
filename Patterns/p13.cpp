/*

A
B C
C D E
D E F G

*/ 

#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    int row = 1;
    // int col = 1;

    while (row <= n)
    {
        char ch = 'A' + row - 1;
        int col = 1;
        while (col <= row)
        {
            cout << ch << " ";
            col++;
            ch++;
        }
        cout << endl;
        row++;
    }

    return 0;
}