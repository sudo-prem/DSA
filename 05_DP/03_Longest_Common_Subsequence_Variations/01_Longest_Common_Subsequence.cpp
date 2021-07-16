// Problem Link:
// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(string &text1, string &text2, int l1, int l2)
{
    if (l1 == 0 or l2 == 0)
        return 0;

    if (text1[l1] == text2[l2])
        return 1 + helper1(text1, text2, l1 - 1, l2 - 1);
    return max(helper1(text1, text2, l1, l2 - 1),
               helper1(text1, text2, l1 - 1, l2));
}

int longestCommonSubsequence1(string text1, string text2)
{
    int l1 = text1.size();
    int l2 = text2.size();

    return helper1(text1, text2, l1, l2);
}

// Approach 2: (Top - Down)
// Recusrsion + Memoization
int helper2(string &text1, string &text2, int l1, int l2, vector<vector<int>> &dp)
{
    if (l1 == 0 or l2 == 0)
        return 0;

    if (dp[l1][l2] != -1)
        return dp[l1][l2];

    if (text1[l1] == text2[l2])
        return dp[l1][l2] = 1 + helper1(text1, text2, l1 - 1, l2 - 1);
    return dp[l1][l2] = max(helper1(text1, text2, l1, l2 - 1),
                            helper1(text1, text2, l1 - 1, l2));
}

int longestCommonSubsequence2(string text1, string text2)
{
    int l1 = text1.size();
    int l2 = text2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));

    return helper2(text1, text2, l1, l2, dp);
}

// Approach 3: (Bottom - Up)
// Tabulation + Iteration
int longestCommonSubsequence3(string text1, string text2)
{
    int l1 = text1.size();
    int l2 = text2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[l1][l2];
}

void solve()
{
    string text1 = "abcde";
    string text2 = "ace";

    // 3
    cout << longestCommonSubsequence1(text1, text2) << endl;
    cout << longestCommonSubsequence2(text1, text2) << endl;
    cout << longestCommonSubsequence3(text1, text2) << endl;
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