#include<bits/stdc++.h>
using namespace std;
// Find first negative number from the window

vector<int> findFirstNegative(vector<int> &nums, int k) {
    
    if (k == 1) {
        return nums;
    }

    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < k; i++) {
        if (nums[i] < 0) {
            dq.push_back(i);
        }
    }

    if (!dq.empty()) {
        ans.push_back(nums[dq.front()]);
    }
    else {
        ans.push_back(0);
    }

    for (int i = k; i < nums.size(); i++) {

        // remove
        if (!dq.empty() && (i - dq.front() >= k)) {
            dq.pop_front();
        }
        
        // add
        if (nums[i] < 0) {
            dq.push_back(i);
        }
        if (dq.empty()) {
            ans.push_back(0);
        }
        else {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

void print (vector<int> arr) {
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr = {-8, 2, 3, -6, 10};
    
    print(findFirstNegative(arr, 2));
    return 0;
}