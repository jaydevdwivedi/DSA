#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str);

int main()
{
    string str = "{{{{{}}}}}";
    cout << findMinimumCost(str);
    return 0;
}

int findMinimumCost(string str)
{
    // Impossible in odd length
    if (str.size() % 2 != 0)
    {
        return -1;
    }

    stack<char> s;

    // Find valid braces and remove it from the string
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (ch == '{')
        {
            s.push(ch);
        }
        else
        {
            // ch is a closed brace
            if (!s.empty() && s.top() == '{')
            {
                // valid pair of braces
                s.pop();
            }
            else
            {
                // invalid pair of braces
                s.push(ch);
            }
        }
    }

    // stack contains invalid expression
    int closed = 0;
    int open = 0;

    while (!s.empty())
    {
        if (s.top() == '{')
        {
            open++;
        }
        else
        {
            closed++;
        }
        s.pop();
    }
    int ans = (closed + 1) / 2 + (open + 1) / 2;
    return ans;
}