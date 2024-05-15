#include <bits/stdc++.h>
using namespace std;

int findMaxRectangle(vector<vector<int>> &matrix);
int findLargestAreaInHistogram(vector<int> &heights);
vector<int> nextSmaller(vector<int> &arr, int n);
vector<int> prevSmaller(vector<int> &arr, int n);

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    cout << findMaxRectangle(matrix);
    return 0;
}

int findMaxRectangle(vector<vector<int>> &matrix)
{
    // vector<int> temp(matrix[0].size());
    int area = findLargestAreaInHistogram(matrix[0]);

    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            // if (matrix[i][j] == 0) {
            //     temp[j] = 0;
            // }
            // else {
            //     temp[j] += matrix[i][j];
            // }
            if (matrix[i][j] != 0) {
                matrix[i][j] += matrix[i-1][j];
            }
            else {
                matrix[i][j] = 0;
            }
        }
        int currArea = findLargestAreaInHistogram(matrix[i]);
        area = max(area, currArea);
    }
    return area;
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

    for (int i = n - 1; i >= 0; i--)
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