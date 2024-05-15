#include <bits/stdc++.h>
using namespace std;

vector<string> findPath(vector<vector<int>> &m, int n);
void solve (vector<vector<int>> &m, int n, vector<string>& ans, int x, int y, vector<vector<int>> visited, string path);
bool isSafe (int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> m);
void printStringVector(vector<string> &arr);
void printIntVector(vector<int> &arr);
void print2DIntVector(vector<vector<int>> &arr);

int main()
{
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    vector<string> result = findPath(m, m.size());
    printStringVector(result);

    return 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0) {
        return ans;
    }

    vector<vector<int>> visited = m;
    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited[i].size(); j++)
        {
            visited[i][j] = 0;
        }
    }    
    print2DIntVector(visited);
    solve(m, n, ans, 0, 0, visited, "");
    return ans;
}

void solve (vector<vector<int>> &m, int n, vector<string>& ans, int x, int y, vector<vector<int>> visited, string path) {
    // We have reached at x, y here
    // base case
    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Recurrence Relation
    // 4 choices - D, L, R, U

    // 1. Down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('D');
        solve (m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // 2. Left
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('L');
        solve (m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // 3. Right
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('R');
        solve (m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // 4. Up
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('U');
        solve (m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

bool isSafe (int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> m) {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0 && m[x][y] == 1)){
        return true;
    }
    return false;
}

void printStringVector(vector<string> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void printIntVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void print2DIntVector(vector<vector<int>> &arr) {
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}