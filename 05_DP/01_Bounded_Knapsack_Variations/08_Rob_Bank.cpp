// Problem Link:
// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(vector<int> &nums, int index)
{
    if (index >= nums.size())
        return 0;

    return max(nums[index] + helper1(nums, index + 2),
               helper1(nums, index + 1));
}

int rob1(vector<int> &nums)
{
    return helper1(nums, 0);
}

// Approach 2:
// Recursion + Memoization
int helper2(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size())
        return 0;

    if (dp[index] != -1)
        return dp[index];

    return dp[index] = max(nums[index] + helper2(nums, index + 2, dp),
                           helper2(nums, index + 1, dp));
}

int rob2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    return helper2(nums, 0, dp);
}

// Approach 3:
// Tabulation + Iteration
int rob3(vector<int> &nums)
{
    int n = nums.size();
    if (!n)
        return 0;
    if (n == 1)
        return nums[0];

    vector<int> dp(n + 1, 0);
    int maxCash = max(nums[0], nums[1]);
    dp[0] = nums[0];
    dp[1] = nums[1];

    for (int i = 2; i < n; ++i)
    {
        maxCash = max(maxCash, nums[i]);
        for (int j = 0; j < i - 1; ++j)
        {
            dp[i] = max(dp[i], dp[j] + nums[i]);
            maxCash = max(maxCash, dp[i]);
        }
    }

    return maxCash;
}

void solve()
{
    vector<int> nums{2, 7, 9, 3, 1};

    cout << rob1(nums) << endl;
    cout << rob2(nums) << endl;
    cout << rob3(nums) << endl;
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