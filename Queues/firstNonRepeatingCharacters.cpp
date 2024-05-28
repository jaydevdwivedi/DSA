#include <bits/stdc++.h>
using namespace std;

string findNonRepeatingCharacter(string s)
{
    if (s == "" || s.size() == 1)
        return s;

    map<char, int> m;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        q.push(ch);
        m[ch]++;

        while (!q.empty())
        {
            if (m[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans += q.front();
                break;
            }
        }
        if (q.empty())
        {
            ans += '#';
        }
    }
    return ans;
}

int main()
{
    string s = "aabc";

    s = findNonRepeatingCharacter(s);
    cout << s;
    return 0;
}