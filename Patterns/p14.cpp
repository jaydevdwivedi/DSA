/*

      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1

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
    // Triangle 1
    int space = n - row;
    while (space > 0)
    {
      cout << "  ";
      space--;
    }

    // Triangle 2
    int col = 1;
    while (col <= row)
    {
      cout << col << " ";
      col++;
    }
    // col--;
    // Triangle 3
    col = row - 1;
    while (col >= 1)
    {
      cout << col << " ";
      col--;
    }
    cout << endl;
    row++;
  }

  return 0;
}