// Problem Link:
// https://leetcode.com/problems/permutations/

// TC: O(n * (2^n))
// SC: O(2^n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

void helper(vector<int> &nums, vector<int> &curr, vector<vector<int>> &res)
{
    if (curr.size() == nums.size())
    {
        res.push_back(curr);
        return;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (find(curr.begin(), curr.end(), nums[i]) != curr.end())
            continue;

        curr.push_back(nums[i]);
        helper(nums, curr, res);
        curr.pop_back();
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> curr;
    vector<vector<int>> res;

    helper(nums, curr, res);
    return res;
}

void solve()
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = permute(nums);

    for (auto i : res)
    {
        cout << "[ ";
        for (auto j : i)
            cout << j << " ";
        cout << "]\n";
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