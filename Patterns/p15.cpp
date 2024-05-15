/*

1 2 3 4 5 5 4 3 2 1
1 2 3 4 * * 4 3 2 1
1 2 3 * * * * 3 2 1
1 2 * * * * * * 2 1
1 * * * * * * * * 1

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int row = 1;

    // while (row <= n)
    // {
    // // Triangle 1
    // int col = 1;
    // while (col <= n - row + 1)
    // {
    //     cout << col << " ";
    //     col++;
    // }

    // // Triangle 2
    // int i =
    // while ((row-1) * 2) {

    // }
    // while (col <= row)
    // {
    //     cout << "* ";
    //     col++;
    // }
    // cout << endl;
    // row++;

    for (int i = 0; i < n; i++)
    {

        for (int j = n; j > i; j--)
        {
            cout << (n - j + 1) << " ";
        }

        for (int k = 0; k < i; k++)
        {
            cout << "* * ";
        }

        for (int j = n - i; j >= 1; j--)
        {
            cout << (j) << " ";
        }
        cout << endl;
    }

    return 0;
}