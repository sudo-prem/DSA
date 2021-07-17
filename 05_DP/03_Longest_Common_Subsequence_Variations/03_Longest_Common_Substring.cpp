// Problem Link:
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(string &str1, string &str2, int l1, int l2, int maxLen)
{
    if (l1 == 0 or l2 == 0)
        return maxLen;

    int res{maxLen};
    if (str1[l1 - 1] == str2[l2 - 1])
        res = max(res, helper1(str1, str2, l1 - 1, l2 - 1, maxLen + 1));

    res = max(res,
              max(helper1(str1, str2, l1 - 1, l2, 0),
                  helper1(str1, str2, l1, l2 - 1, 0)));

    return res;
}

int longestCommonSubstring1(string &str1, string &str2)
{
    int l1 = str1.size();
    int l2 = str2.size();

    return helper1(str1, str2, l1, l2, 0);
}

// Approach 2:
// Recursion + Memoization
int helper2(string &str1, string &str2, int l1, int l2, int maxLen, vector<vector<string>> &dp)
{
    if (l1 == 0 or l2 == 0)
        return maxLen;

    if (dp[l1][l2][maxLen] != -1)
        return dp[l1][l2][maxLen];

    int res{maxLen};
    if (str1[l1 - 1] == str2[l2 - 1])
        res = max(res, helper2(str1, str2, l1 - 1, l2 - 1, maxLen + 1, dp));

    res = max(res,
              max(helper2(str1, str2, l1 - 1, l2, 0, dp),
                  helper2(str1, str2, l1, l2 - 1, 0, dp)));

    return dp[l1][l2][maxLen] = res;
}

int longestCommonSubstring2(string &str1, string &str2)
{
    int l1 = str1.size();
    int l2 = str2.size();
    vector<vector<string>> dp(l1 + 1, vector<string>(l2 + 1, string(max(l1, l2) + 1, -1)));

    return helper2(str1, str2, l1, l2, 0, dp);
}

// Approach 3:
// Tabulation + Iteration
int longestCommonSubstring3(string &str1, string &str2)
{
    int l1 = str1.size();
    int l2 = str2.size();
    int maxLen{};

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
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
    string str1{"zxabcdezy"};
    string str2{"yzabcdezx"};

    // string str1{"abcdxyz"};
    // string str2{"xyzabcd"};

    cout << longestCommonSubstring1(str1, str2) << endl;
    cout << longestCommonSubstring2(str1, str2) << endl;
    cout << longestCommonSubstring3(str1, str2) << endl;
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