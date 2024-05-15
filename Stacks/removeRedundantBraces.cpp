#include <bits/stdc++.h>
using namespace std;

bool findRedundantBraces(string &str);
int main();

int main()
{
    string str = "(a/b)/a";
    if (findRedundantBraces(str))
    {
        cout << "Redundant beackets are present" << endl;
    }
    else
    {
        cout << "No redundant brackets" << endl;
    }
    return 0;
}

bool findRedundantBraces(string &str)
{

    if (str == "")
    {
        return false;
    }

    stack<char> s;
    bool isRedundant = false;
    
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == '\\' || ch == '*' || ch == '+' || ch == '-' || ch == '%')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (s.top() != '(')
            {
                char top = s.top();
                if (top != '\\' && top != '*' && top != '+' && top != '-' && top != '%')
                {
                    s.pop();
                    continue;
                }
                s.pop();
            }
            else if (top == '(')
            {
                return true;
            }
        }
    }
    return false;
}