/*

1 2 3 4
  2 3 4
    3 4
      4

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
      cout << " ";
      space++;
    }

    int col = n - row  + 1;
    int value = row;

    while (col >= row)
    {
      cout << value << " ";
      col--;
      value++;
    }
    cout << endl;
    row++;
  }

  return 0;
}