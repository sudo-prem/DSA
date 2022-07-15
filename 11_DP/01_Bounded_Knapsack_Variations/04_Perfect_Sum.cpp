// Problem Link:
// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1
// Recursion
int helper1(vector<int> &nums, int target, int index)
{
    if (target == 0)
        return 1;
    if (index == nums.size())
        return 0;

    return helper1(nums, target, index + 1) + helper1(nums, target - nums[index], index + 1);
}

int perfectSum1(vector<int> &nums, int target)
{
    return helper1(nums, target, 0);
}

// Approach 2: (Top Down)
// Recursion + Memoization
int helper2(vector<int> &nums, int target, int index, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (index == nums.size() or target < 0)
        return 0;

    if (dp[index][target] != -1)
        return dp[index][target];
    return dp[index][target] = helper2(nums, target, index + 1, dp) +
                               helper2(nums, target - nums[index], index + 1, dp);
}

int perfectSum2(vector<int> &nums, int target)
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));

    return helper2(nums, target, 0, dp);
}

// Approach 3: (Bottom Up)
// Tabulation + Iteration
int mod = 1e9 + 7;
int perfectSum3(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= target; ++j)
        {
            if (j - nums[i - 1] >= 0)
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]) % mod;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][target];
}

void solve()
{
    vector<int> nums{2, 3, 5, 6, 8, 10};
    int target{10};

    cout << perfectSum1(nums, target) << endl;
    cout << perfectSum2(nums, target) << endl;
    cout << perfectSum3(nums, target) << endl;
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