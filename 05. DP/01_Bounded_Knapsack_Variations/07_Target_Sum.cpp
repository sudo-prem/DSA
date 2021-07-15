// Problem Link:
// https://leetcode.com/problems/target-sum/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Brute Force Recursion
int helper1(vector<int> &nums, int k, int index, int currSum)
{
    if (index == nums.size())
        return (currSum == k);
    return helper1(nums, k, index + 1, currSum - nums[index]) +
           helper1(nums, k, index + 1, currSum + nums[index]);
}

int findTargetSumWays1(vector<int> &nums, int k)
{
    return helper1(nums, k, 0, 0);
}

// Approach 2: (Top Down)
// Brute Force Recursion + Memoization
int helper2(vector<int> &nums, int k, int index, int currSum, vector<unordered_map<int, int>> &dp)
{
    if (index == nums.size())
        return (currSum == k);
    if (dp[index].find(currSum) != dp[index].end())
        return dp[index][currSum];

    return dp[index][currSum] = helper2(nums, k, index + 1, currSum + nums[index], dp) +
                                helper2(nums, k, index + 1, currSum - nums[index], dp);
}

int findTargetSumWays2(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<unordered_map<int, int>> dp(n + 1);

    return helper2(nums, k, 0, 0, dp);
}

// Approach 3:
// Optimised Recursion
int helper3(vector<int> &nums, int target, int index)
{
    if (index == nums.size())
        return (target == 0);

    return helper3(nums, target, index + 1) +
           helper3(nums, target - nums[index], index + 1);
}

int findTargetSumWays3(vector<int> &nums, int k)
{
    // sum = s1 + s2
    // k = s1 - s2
    // s1 = (sum + target)/2
    // Note: sum + k, should be even
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = (sum + k) / 2;

    return helper3(nums, target, 0);
}

// Approach 4: (Top Down)
// Optimised Recusion + Memoization
int helper4(vector<int> &nums, int target, int index, vector<vector<int>> &dp)
{
    if (index == nums.size())
        return (target == 0);

    if (dp[index][target] != -1)
        return dp[index][target];

    return dp[index][target] = helper4(nums, target, index + 1, dp) +
                               helper4(nums, target - nums[index], index + 1, dp);
}

int findTargetSumWays4(vector<int> &nums, int k)
{
    // sum = s1 + s2
    // k = s1 - s2
    // s1 = (sum + target)/2
    // Note: sum + k, should be even
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = (sum + k) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return helper4(nums, target, 0, dp);
}

// Approach 5: (Bottom Up)
// Tabulation + Iteration
int findTargetSumWays5(vector<int> &nums, int k)
{
    // sum = s1 + s2
    // k = s1 - s2
    // s1 = (sum + target)/2
    // Note: sum + k, should be even
    int n = nums.size();
    int sum{}, zeroCount{};
    for (int i : nums)
    {
        sum += i;
        if (!i)
            zeroCount++;
    }

    if ((sum + k) % 2 or k > sum or k < -sum)
        return 0;
    int target = (sum + k) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    // Initialization
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        int curr = nums[i - 1];
        for (int j = 1; j <= sum; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - curr >= 0 and curr != 0)
                dp[i][j] += dp[i - 1][j - curr];
        }
    }

    return pow(2, zeroCount) * dp[n][target];
}

void solve()
{
    vector<int> nums{0, 0, 0, 1, 1, 1, 1, 1};
    int k{3};

    cout << findTargetSumWays1(nums, k) << endl;
    cout << findTargetSumWays2(nums, k) << endl;
    cout << findTargetSumWays3(nums, k) << endl;
    cout << findTargetSumWays4(nums, k) << endl;
    cout << findTargetSumWays5(nums, k) << endl;
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