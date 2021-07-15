// Problem Link:
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&page=4&query=category[]Dynamic%20Programmingpage4category[]Dynamic%20Programming

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1
// Recursion
bool helper1(vector<int> &nums, int target, int index)
{
    if (target == 0)
        return true;
    if (index == nums.size())
        return false;
    return helper1(nums, target, index + 1) or
           helper1(nums, target - nums[index], index + 1);
}

bool isSubsetSum1(vector<int> &nums, int target)
{
    return helper1(nums, target, 0);
}

// Approach 2: (Top Down)
// Recursion + Memoization
bool helper2(vector<int> &nums, int target, int index, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == nums.size())
        return false;

    if (dp[index][target] != -1)
        return dp[index][target];
    return dp[index][target] = helper2(nums, target - nums[index], index + 1, dp) or
                               helper2(nums, target, index + 1, dp);
}

bool isSubsetSum2(vector<int> &nums, int target)
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
    return helper2(nums, target, 0, dp);
}

// Approach 3: (Bottom Up)
// Tabulation + Iteration
bool isSubsetSum3(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Initialization
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    for (int i = 1; i <= n; ++i)
    {
        int curr = nums[i - 1];
        for (int j = 1; j <= target; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - curr >= 0 and dp[i - 1][j - curr])
                dp[i][j] = 1;
        }
    }

    return dp[n][target];
}

void solve()
{
    vector<int> nums{3, 34, 4, 12, 5, 2};
    int target{9};

    cout << isSubsetSum1(nums, target) << endl;
    cout << isSubsetSum2(nums, target) << endl;
    cout << isSubsetSum3(nums, target) << endl;
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