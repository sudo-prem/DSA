// Problem Link:
// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(string s, int start, int end)
{
    if (start == end)
        return 1;
    if (start > end)
        return 0;

    if (s[start] == s[end])
        return 2 + helper1(s, start + 1, end - 1);
    return max(helper1(s, start, end - 1),
               helper1(s, start + 1, end));
}

int longestPalindromicSubsequence1(string s)
{
    return helper1(s, 0, s.size() - 1);
}

// Approach 2:
// Recursion + Memoization
int helper2(string s, int start, int end, vector<vector<int>> &dp)
{
    if (start == end)
        return 1;
    if (start > end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    if (s[start] == s[end])
        return dp[start][end] = 2 + helper2(s, start + 1, end - 1, dp);
    return dp[start][end] = max(helper2(s, start, end - 1, dp),
                                helper2(s, start + 1, end, dp));
}

int longestPalindromicSubsequence2(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper2(s, 0, n - 1, dp);
}

// Approach 3:
// Tabulation + Iteration
int longestPalindromicSubsequence3(string s1)
{
    // Data Structures and Preprocessing
    int n = s1.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    string s2(s1.rbegin(), s1.rend());

    // Tabulate
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

void solve()
{
    string s{"bbbabsdfdfdfv"};

    cout << longestPalindromicSubsequence1(s) << endl;
    cout << longestPalindromicSubsequence2(s) << endl;
    cout << longestPalindromicSubsequence3(s) << endl;
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