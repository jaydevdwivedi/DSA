#include <bits/stdc++.h>
using namespace std;

int findLargestAreaInHistogram(vector<int> &heights);
vector<int> nextSmaller(vector<int> &arr, int n);
vector<int> prevSmaller(vector<int> &arr, int n);

int main()
{
    vector<int> arr = {2, 4};

    cout << findLargestAreaInHistogram(arr);
    return 0;
}

int findLargestAreaInHistogram(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmaller(heights, n);

    vector<int> prev(n);
    prev = prevSmaller(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(newArea, area);
    }

    return area;
}

vector<int> nextSmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}