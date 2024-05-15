#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr);
vector<int> findNextSmaller (vector<int> &arr);

int main() {
    vector<int> arr = {2, 1, 4, 3};
    // printArray(arr);

    vector<int> ans;
    ans = findNextSmaller(arr); 

    printArray(ans);

    return 0;
}

vector<int> findNextSmaller (vector<int> &arr) {

    stack<int> s;
    s.push(-1);
    vector<int> ans(arr.size());
    int n = arr.size() - 1;

    for (int i = n; i >= 0; i--)
    {
        int curr = arr[i]; 

        while (s.top() >= curr) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

void printArray(vector<int> &arr){

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}