// Problem Link:
// https://leetcode.com/problems/combination-sum/

// TC: O(2^n)
// SC: O(2^n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

void helper(vector<int> &nums, int index, vector<int> &curr, vector<vector<int>> &res)
{
    res.push_back(curr);
    for (int i = index; i < nums.size(); ++i)
    {
        curr.push_back(nums[i]);
        helper(nums, i + 1, curr, res);
        curr.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> curr;
    helper(nums, 0, curr, res);
    return res;
}

void solve()
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = subsets(nums);

    for (auto i : res)
    {
        cout << "[ ";
        for (auto j : i)
            cout << j << " ";
        cout << "]" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t{1};
    // cin >> t;
    while (t--)
        solve();
    return 0;
}