/*

* * * * *
  * * * *
    * * *
      * *
        *

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
    int space = 1;

    while (space < row)
    {
      cout << "  ";
      space++;
    }

    int col = n - row + 1;
    while (col > 0)
    {
      cout << "* ";
      col--;
    }
    cout << endl;
    row++;
  }
  return 0;
}