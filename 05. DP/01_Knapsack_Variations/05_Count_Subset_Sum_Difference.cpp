// Problem Link:
// NA

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Brute Force Recursion (Memoization is not feasible)
int helper1(vector<int> &nums, int k, int index, int sum1, int sum2)
{
    if (index == nums.size())
        return (sum1 - sum2) == k;

    return helper1(nums, k, index + 1, sum1 + nums[index], sum2) +
           helper1(nums, k, index + 1, sum1, sum2 + nums[index]);
}

int count1(vector<int> &nums, int k)
{
    return helper1(nums, k, 0, 0, 0);
}

// Approach 2:
// Recursion Optimised
int helper2(vector<int> &nums, int index, int target)
{
    if (index == nums.size())
        return (target == 0);
    if (target < 0)
        return 0;

    return helper2(nums, index + 1, target) +
           helper2(nums, index + 1, target - nums[index]);
}

int count2(vector<int> &nums, int k)
{
    // sum = s1 + s2
    // k = s1 - s2
    // s1 = (sum + k)/2
    // Note: sum + k, should be even
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = (sum + k) / 2;
    return helper2(nums, 0, target);
}

// Approach 3: (Top Down)
// Recursion + Memoization
int helper3(vector<int> &nums, int index, int target, vector<vector<int>> &dp)
{
    if (index == nums.size())
        return (target == 0);
    if (target < 0)
        return 0;

    if (dp[index][target] != -1)
        return dp[index][target];
    return dp[index][target] = helper3(nums, index + 1, target, dp) +
                               helper3(nums, index + 1, target - nums[index], dp);
}

int count3(vector<int> &nums, int k)
{
    // sum = s1 + s2
    // k = s1 - s2
    // s1 = (sum + k)/2
    // Note: sum + k, should be even
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = (sum + k) / 2;

    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
    return helper3(nums, 0, target, dp);
}

// Approach 4: (Bottom Up)
// Tabulation + Iteration
int count4(vector<int> &nums, int k)
{
    // sum = s1 + s2
    // k = s1 - s2
    // s1 = (sum + k)/2
    // Note: sum + k, should be even
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

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
        for (int j = 1; j <= target; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - curr >= 0)
                dp[i][j] += dp[i - 1][j - curr];
        }
    }

    return dp[n][target];
}

void solve()
{
    vector<int> nums{1, 1, 2, 3};
    int k{1};

    cout << count1(nums, k) << endl;
    cout << count2(nums, k) << endl;
    cout << count3(nums, k) << endl;
    cout << count4(nums, k) << endl;
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