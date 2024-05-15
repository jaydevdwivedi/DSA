/*

1
2 1
3 2 1
4 3 2 1


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

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
        }
        cout << endl;
        row++;
    }
    return 0;
}