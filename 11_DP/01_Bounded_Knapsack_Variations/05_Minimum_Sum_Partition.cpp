// Problem Link:
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Brute Force Recursion (Memoization is not feasible)
int helper1(vector<int> &nums, int index, int sum1, int sum2)
{
    if (index == nums.size())
        return abs(sum1 - sum2);

    return min(helper1(nums, index + 1, sum1 + nums[index], sum2),
               helper1(nums, index + 1, sum1, sum2 + nums[index]));
}

int minDifference1(vector<int> &nums)
{
    return helper1(nums, 0, 0, 0);
}

// Approach 2:
// Recursion Optimised
int helper2(vector<int> &nums, int index, int currSum, int sum)
{
    if (index == nums.size())
        return abs((sum - currSum) - currSum);
    return min(helper2(nums, index + 1, currSum, sum),
               helper2(nums, index + 1, currSum + nums[index], sum));
}

int minDifference2(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    return helper2(nums, 0, 0, sum);
}

// Approach 3: (Top Down)
// Recursion + Memoization
int helper3(vector<int> &nums, int index, int currSum, int sum, vector<vector<int>> &dp)
{
    if (index == nums.size())
        return abs((sum - currSum) - currSum);

    if (dp[index][currSum] != -1)
        return dp[index][currSum];

    return dp[index][currSum] = min(helper3(nums, index + 1, currSum, sum, dp),
                                    helper3(nums, index + 1, currSum + nums[index], sum, dp));
}

int minDifference3(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));

    return helper3(nums, 0, 0, sum, dp);
}

// Approach 4: (Bottom Up)
// Tabulation + Iteration
int minDifference4(vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int minDiff{sum};
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    // Initialization
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    for (int i = 1; i <= n; ++i)
    {
        int curr = nums[i - 1];
        for (int j = 1; j <= sum; ++j)
        {
            if (j - curr >= 0 and dp[i - 1][j - curr])
                dp[i][j] = true;
            else
                dp[i][j] = dp[i - 1][j];

            if (dp[i][j])
                minDiff = min(minDiff, abs((sum - j) - j));
        }
    }

    return minDiff;
}

void solve()
{
    vector<int> nums{1, 6, 11, 5};
    cout << minDifference1(nums) << endl;
    cout << minDifference2(nums) << endl;
    cout << minDifference3(nums) << endl;
    cout << minDifference4(nums) << endl;
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