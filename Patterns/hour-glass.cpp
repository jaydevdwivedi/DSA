#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "n: ";
    cin >> n;

    int i_pos = 0, j_pos = 0;
    int row = 0;
    int col = 0;
    int count = 1;
    int space = 0;
    int i = 0;
    int j = 0;

    // Printing top of the pattern
    while (row < n)
    {
        // Printing first triangle
        space = 0;
        while (space < row)
        {
            cout << "  ";
            space++;
        }

        // Printing second triangle
        col = 0;
        j = 0;
        while (col < n - row)
        {

            if (count == 9)
            {
                cout << 9;
                count = 0;
            }
            else if (count == 0)
            {
                cout << 0;
                count = 9;
            }
            else if (count < 9)
            {
                cout << count++;
                j_pos = j;
                i_pos = i;
            }
            cout << "   ";
            col++; j++;
        }
        row++; i++;
        cout << endl;
    }

    row--;
    i = i - 2;
    space = 0;
    col = 0;
    j_pos++;

    // Printing bottom of the pattern
    while (row > 0) {

        // Printing third triangle
        space = 0;
        while(space < row - 1) {
            cout << "  ";
            space++;
        }

        // Printing fourth triangle
        col = 0;
        j = n - row;
        while (col < n - row + 1) {
            if (i == i_pos && j == j_pos) {
                cout << count--;
            }
            else if (count == 0) {
                cout << 0;
                count = 9;
            }
            else if (count < 9) {
                cout << count--;
            }
            else if (count == 9) {
                cout << 9;
                count = 0;
            }
            
            cout << "   ";
            col++;
            j--;
        }
        i--;
        row--;
        cout << endl;
    }
    return 0;
}