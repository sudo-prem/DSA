// Problem Link:
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(vector<int> &nums, int i, int j)
{
    if (i >= j)
        return 0;

    int minCost{INT_MAX};
    for (int k = i; k < j; ++k)
    {
        int leftCost = helper1(nums, i, k);
        int rightCost = helper1(nums, k + 1, j);
        int currCost = leftCost + (nums[i - 1] * nums[k] * nums[j]) + rightCost;

        minCost = min(minCost, currCost);
    }

    return minCost;
}

int matrixChainMultiplication1(vector<int> &nums)
{
    return helper1(nums, 1, nums.size() - 1);
}

// Approach 2:
// Recursion + Memoization
int helper2(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int minCost{INT_MAX};
    for (int k = i; k < j; ++k)
    {
        int leftCost = helper2(nums, i, k, dp);
        int rightCost = helper2(nums, k + 1, j, dp);
        int currCost = leftCost + (nums[i - 1] * nums[k] * nums[j]) + rightCost;

        minCost = min(minCost, currCost);
    }

    return dp[i][j] = minCost;
}

int matrixChainMultiplication2(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return helper2(nums, 1, n - 1, dp);
}

// Approach 3:
// Tabulation + Iteration
int matrixChainMultiplication3(vector<int> &nums)
{
    // Data Structures
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

    // Initialization
    // Single Matrix Multilplication would result 0
    for (int i = 1; i <= n; ++i)
        dp[i][i] = 0;

    // Tabulation
    // d - each diagonal after the longest diagonal
    // i - leftside matrix
    // j - rightside matrix
    // k - partition matrix
    for (int d = 1; d < n; ++d)
    {
        for (int i = 1; i <= n - d; ++i)
        {
            int j = d + i - 1;
            for (int k = i; k < j; ++k)
            {
                int currCost = dp[i][k] + dp[k + 1][j] + (nums[i - 1] * nums[k] * nums[j]);
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    return dp[1][n - 1];
}

void solve()
{
    // 30000
    // vector<int> nums{10, 20, 30, 40, 30};
    // 6000
    vector<int> nums{10, 20, 30};

    cout << matrixChainMultiplication1(nums) << endl;
    cout << matrixChainMultiplication2(nums) << endl;
    cout << matrixChainMultiplication3(nums) << endl;
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