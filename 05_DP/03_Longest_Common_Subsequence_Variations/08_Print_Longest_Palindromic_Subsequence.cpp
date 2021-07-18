// Problem Link:
// NA

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
string helper1(string word, int low, int high)
{
    if (low > high)
        return "";
    if (low == high)
        return {word[low]};

    if (word[low] == word[high])
        return word[low] + helper1(word, low + 1, high - 1) + word[high];

    string res1 = helper1(word, low, high - 1);
    string res2 = helper1(word, low + 1, high);
    if (res1.size() > res2.size())
        return res1;
    return res2;
}

string longestPalindromicSubsequence1(string s)
{
    return helper1(s, 0, s.size() - 1);
}

// Approach 2:
// Recursion + Memoization
string helper2(string word, int low, int high, vector<vector<string>> &dp)
{
    if (low > high)
        return "";
    if (low == high)
        return {word[low]};

    if (dp[low][high] != "")
        return dp[low][high];

    if (word[low] == word[high])
        return dp[low][high] = word[low] + helper1(word, low + 1, high - 1) + word[high];

    string res1 = dp[low][high - 1] = helper1(word, low, high - 1);
    string res2 = dp[low + 1][high] = helper1(word, low + 1, high);
    if (res1.size() > res2.size())
        return dp[low][high] = res1;
    return dp[low][high] = res2;
}

string longestPalindromicSubsequence2(string s)
{
    int n = s.size();
    vector<vector<string>> dp(n, vector<string>(n, ""));

    return helper2(s, 0, n - 1, dp);
}

// Approach 3:
// Tabulation + Iteration
string longestPalindromicSubsequence3(string s1)
{
    // Data structures + Preprocessing
    int n = s1.size();
    string s2(s1.rbegin(), s1.rend());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Tabulation
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

    // Retreive String
    int i = n, j = n;
    string res{};
    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    return res;
}

void solve()
{
    string s{"bbbsdfbtrbab"};

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