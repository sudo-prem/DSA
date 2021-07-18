// Problem Link:
// NA

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(string &word, int low, int high, int maxLen)
{
    if (low > high)
        return maxLen;
    if (low == high)
        return maxLen + 1;

    int res{maxLen};
    if (word[low] == word[high])
        res = max(res, helper1(word, low + 1, high - 1, 2 + maxLen));
    res = max(res,
              max(helper1(word, low, high - 1, 0),
                  helper1(word, low + 1, high, 0)));
    return res;
}

int longestPalindromicSubstring1(string &word)
{
    int n = word.size();

    return helper1(word, 0, n - 1, 0);
}

// Recursion + Memoization
int helper2(string &word, int low, int high, int maxLen, vector<vector<vector<int>>> &dp)
{
    if (low > high)
        return maxLen;
    if (low == high)
        return maxLen + 1;

    if (dp[low][high][maxLen] != -1)
        return dp[low][high][maxLen];

    int res{maxLen};
    if (word[low] == word[high])
        res = max(res, helper2(word, low + 1, high - 1, 2 + maxLen, dp));
    res = max(res,
              max(helper2(word, low, high - 1, 0, dp),
                  helper2(word, low + 1, high, 0, dp)));

    return dp[low][high][maxLen] = res;
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