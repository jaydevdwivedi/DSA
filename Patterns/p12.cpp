/*

A
B C
D E F
G H I J

*/ 
#include<bits/stdc++.h>
using namespace std;

int main() {
    
     int n;
    cin >> n;

    int row = 1;
    int col = 1;
    char ch = 'A';

    while (row <= n)
    {

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