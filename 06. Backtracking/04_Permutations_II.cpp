// Problem Link:
// https://leetcode.com/problems/permutations-ii/

// TC: O(n!)
// SC: O(2^n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

void helper(vector<int> &nums, vector<bool> &used, vector<int> &curr, vector<vector<int>> &res)
{
    if (curr.size() == nums.size())
    {
        res.push_back(curr);
        return;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (used[i])
            continue;
        used[i] = true;
        curr.push_back(nums[i]);
        helper(nums, used, curr, res);
        curr.pop_back();
        used[i] = false;

        while (i + 1 < nums.size() and nums[i] == nums[i + 1])
            i++;
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    vector<int> curr;
    vector<vector<int>> res;

    helper(nums, used, curr, res);
    return res;
}

void solve()
{
    vector<int> nums{1, 1, 2};
    vector<vector<int>> res = permuteUnique(nums);

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