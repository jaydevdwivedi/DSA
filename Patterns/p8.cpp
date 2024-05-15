/*

      1
    2 3
  4 5 6
7 8 9 10

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n;
  cin >> n;

  int row = 1;
  int col = 1;
  int count = 1;

  while (row <= n)
  {
    int space = n - row;
    while (space > 0)
    {
      cout << "  ";
      space--;
    }

    int col = 1;
    while (col <= row)
    {
      cout << count << " ";
      col++;
      count++;
    }
    cout << endl;
    row++;
  }

  return 0;
}