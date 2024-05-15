#include <bits/stdc++.h>
using namespace std;

int findCeleberity(vector<vector<int>> &people, int n);
bool knows (int a, int b, vector<vector<int>> &people);

int main()
{
    vector<vector<int>> people = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    
    cout << findCeleberity(people, 3);
    return 0;
}


int findCeleberity(vector<vector<int>> &people, int n)
{
    stack<int> s;

    // push all elements in stack
    for (int i = 0; i < people.size(); i++)
    {
        s.push(i);
    }

    // step 2: Get two elements and compare them
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(a, b, people))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    // step 3: If single element in stack, it is potential celebrity
    // So, verify it!

    int candidate = s.top();
    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (people[candidate][i] == 0)
        {
            zeroCount++;
        }
    }

    if (zeroCount != n)
    {
        return -1;
    }

    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (people[i][candidate] == 1)
        {
            oneCount++;
        }
    }

    if (oneCount != n - 1)
    {
        return -1;
    }
    return candidate;
}

bool knows (int a, int b, vector<vector<int>> &people) {

    if (people[a][b] == 1) {
        return true;
    }
    return false;
}