// Problem Link:
// NA

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(string &word, int left, int right, int maxLen)
{
    if (left > right)
        return maxLen;
    if (left == right)
        return maxLen + 1;

    int res{maxLen};
    if (word[left] == word[right])
        res = max(res, helper1(word, left + 1, right - 1, 2 + maxLen));
    res = max(res,
              max(helper1(word, left, right - 1, 0),
                  helper1(word, left + 1, right, 0)));
    return res;
}

int longestPalindromicSubstring1(string &word)
{
    int n = word.size();

    return helper1(word, 0, n - 1, 0);
}

// Recursion + Memoization
int helper2(string &word, int left, int right, int maxLen, vector<vector<vector<int>>> &dp)
{
    if (left > right)
        return maxLen;
    if (left == right)
        return maxLen + 1;

    if (dp[left][right][maxLen] != -1)
        return dp[left][right][maxLen];

    int res{maxLen};
    if (word[left] == word[right])
        res = max(res, helper2(word, left + 1, right - 1, 2 + maxLen, dp));
    res = max(res,
              max(helper2(word, left, right - 1, 0, dp),
                  helper2(word, left + 1, right, 0, dp)));

    return dp[left][right][maxLen] = res;
}

int longestPalindromicSubstring2(string &word)
{
    int n = word.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

    return helper2(word, 0, n - 1, 0, dp);
}

// Approach 3:
// Tabulation + Iteration
int longestPalindromicSubstring3(string &word1)
{
    int n = word1.size();
    string word2(word1.rbegin(), word1.rend());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int maxLen{};

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
            maxLen = max(maxLen, dp[i][j]);
        }
    }

    return maxLen;
}

void solve()
{
    // string word{"abcbab"};
    string word{"abcdaa"};

    cout << longestPalindromicSubstring1(word) << endl;
    cout << longestPalindromicSubstring2(word) << endl;
    cout << longestPalindromicSubstring3(word) << endl;
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