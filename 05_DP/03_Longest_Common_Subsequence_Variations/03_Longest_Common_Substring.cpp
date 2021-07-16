// Problem Link:
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(vector<int> &nums1, vector<int> &nums2, int l1, int l2, int maxLen)
{
    if (l1 == 0 or l2 == 0)
        return maxLen;

    int res{maxLen};
    if (nums1[l1 - 1] == nums2[l2 - 1])
        res = max(res, helper1(nums1, nums2, l1 - 1, l2 - 1, maxLen + 1));

    res = max(res,
              max(helper1(nums1, nums2, l1 - 1, l2, 0),
                  helper1(nums1, nums2, l1, l2 - 1, 0)));

    return res;
}

int findLength1(vector<int> &nums1, vector<int> &nums2)
{
    int l1 = nums1.size();
    int l2 = nums2.size();

    return helper1(nums1, nums2, l1, l2, 0);
}

// Approach 2:
// Recursion + Memoization
int helper2(vector<int> &nums1, vector<int> &nums2, int l1, int l2, int maxLen, vector<vector<vector<int>>> &dp)
{
    if (l1 == 0 or l2 == 0)
        return maxLen;

    if (dp[l1][l2][maxLen] != -1)
        return dp[l1][l2][maxLen];

    int res{maxLen};
    if (nums1[l1 - 1] == nums2[l2 - 1])
        res = max(res, helper2(nums1, nums2, l1 - 1, l2 - 1, maxLen + 1, dp));

    res = max(res,
              max(helper2(nums1, nums2, l1 - 1, l2, 0, dp),
                  helper2(nums1, nums2, l1, l2 - 1, 0, dp)));

    return dp[l1][l2][maxLen] = res;
}

int findLength2(vector<int> &nums1, vector<int> &nums2)
{
    int l1 = nums1.size();
    int l2 = nums2.size();
    vector<vector<vector<int>>> dp(l1 + 1, vector<vector<int>>(l2 + 1, vector<int>(max(l1, l2) + 1, -1)));

    return helper2(nums1, nums2, l1, l2, 0, dp);
}

// Approach 3:
// Tabulation + Iteration
int findLength3(vector<int> &nums1, vector<int> &nums2)
{
    int l1 = nums1.size();
    int l2 = nums2.size();
    int maxLen{};

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;
            maxLen = max(maxLen, dp[i][j]);
        }
    }

    return maxLen;
}

void solve()
{
    vector<int> nums1{1, 2, 3, 2, 1};
    vector<int> nums2{3, 2, 1, 4, 7};

    cout << findLength1(nums1, nums2) << endl;
    cout << findLength2(nums1, nums2) << endl;
    cout << findLength3(nums1, nums2) << endl;
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