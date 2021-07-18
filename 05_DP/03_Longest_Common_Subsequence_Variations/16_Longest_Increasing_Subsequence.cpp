// Problem Link:
// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// LCS Variant - O(n^2 + n*log(n))
int longestIncreasingSubsequence1(vector<int> &nums1)
{
    // Put nums in set and take it out to get sort single elements
    set<int> temp(nums1.begin(), nums1.end());
    vector<int> nums2(temp.begin(), temp.end());

    // Find LCS
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

// Approach2:
// Recursion
int helper2(vector<int> &nums, int prev, int curr)
{
    if (curr == nums.size())
        return 1;

    int res1{}, res2{};
    if (nums[curr] > nums[prev])
        res1 = 1 + helper2(nums, curr, curr + 1);
    res2 = helper2(nums, prev, curr + 1);

    return max(res1, res2);
}

int longestIncreasingSubsequence2(vector<int> &nums)
{
    int n = nums.size();
    int currLIS{}, maxLen{};

    for (int i = 1; i < nums.size() - 1; ++i)
    {
        currLIS = helper2(nums, i - 1, i);
        maxLen = max(maxLen, currLIS);
    }

    return maxLen;
}

// Approach 3:
// Recursion + Memoization
int helper3(vector<int> &nums, int prev, int curr, vector<vector<int>> &dp)
{
    if (curr == nums.size())
        return 1;

    if (dp[prev][curr] != -1)
        return dp[prev][curr];

    int res1{}, res2{};
    if (nums[curr] > nums[prev])
        res1 = 1 + helper3(nums, curr, curr + 1, dp);
    res2 = helper3(nums, prev, curr + 1, dp);

    return dp[prev][curr] = max(res1, res2);
}

int longestIncreasingSubsequence3(vector<int> &nums)
{
    int n = nums.size();
    int maxLen{}, currLIS{};
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i < n; ++i)
    {
        currLIS = helper3(nums, i - 1, i, dp);
        maxLen = max(maxLen, currLIS);
    }

    return maxLen;
}

// Approach 4:
// Tabulation + Iteration
int longestIncreasingSubsequence4(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLen{1};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                maxLen = max(maxLen, dp[i]);
            }
        }
    }

    return maxLen;
}

void solve()
{
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

    cout << longestIncreasingSubsequence1(nums) << endl;
    cout << longestIncreasingSubsequence2(nums) << endl;
    cout << longestIncreasingSubsequence3(nums) << endl;
    cout << longestIncreasingSubsequence4(nums) << endl;
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