// Problem Link:
// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1
// Recursion
bool helper1(vector<int> &nums, int index, int target)
{
    if (target == 0)
        return true;
    if (index == nums.size() or target < 0)
        return false;
    return helper1(nums, index + 1, target - nums[index]) or
           helper1(nums, index + 1, target);
}

bool canPartition1(vector<int> &nums)
{
    int target = accumulate(nums.begin(), nums.end(), 0);
    if (target % 2)
        return false;
    target /= 2;

    return helper1(nums, 0, target);
}

// Approach 2: (Top Down)
// Recursion + Memoization
bool helper2(vector<int> &nums, int index, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == nums.size() or target < 0)
        return false;

    if (dp[index][target] != -1)
        return dp[index][target];

    return dp[index][target] = helper2(nums, index + 1, target - nums[index], dp) or
                               helper2(nums, index + 1, target, dp);
}

bool canPartition2(vector<int> &nums)
{
    int target = accumulate(nums.begin(), nums.end(), 0);
    if (target % 2)
        return false;
    target /= 2;

    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));

    return helper2(nums, 0, target, dp);
}

// Approach 3: (Bottom Up)
// Tabulation + Iteration
bool canPartition3(vector<int> &nums)
{
    int target = accumulate(nums.begin(), nums.end(), 0);
    if (target % 2)
        return false;
    target /= 2;

    int n = nums.size();
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));

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
                dp[i][j] = true;
        }
    }

    return dp[n][target];
}

void solve()
{
    vector<int> nums{1, 5, 11, 5};

    cout << canPartition1(nums) << endl;
    cout << canPartition2(nums) << endl;
    cout << canPartition3(nums) << endl;
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