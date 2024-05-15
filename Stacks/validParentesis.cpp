#include <bits/stdc++.h>
using namespace std;

bool isValid(string str);

int main()
{
    if (isValid("({]})"))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}

bool isValid(string str)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (!stack.empty())
            {
                if (ch == ')' && s.top() == '(')
                {
                    s.pop();
                }
                else if (ch == '}' && s.top() == '{')
                {
                    s.pop();
                }
                else if (ch == ']' && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    return true;
}