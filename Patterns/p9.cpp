/*

1
2 3
3 4 5
4 5 6 7

*/ 

#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    int row = 1;
    int col = 1;

    while (row <= n)
    {
        int value = row;
        int col = 1;
        while (col <= row)
        {
            cout << value << " ";
            col++;
            value++;
        }
        cout << endl;
        row++;
    }

    return 0;
}