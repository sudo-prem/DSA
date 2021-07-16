// Problem Link:
// NA

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
string helper1(string s1, string s2, int l1, int l2, string maxString)
{
    if (l1 == 0 or l2 == 0)
        return maxString;

    if (s1[l1] == s2[l2])
        return helper1(s1, s2, l1 - 1, l2 - 1, s1[l1] + maxString);

    string res1 = helper1(s1, s2, l1, l2 - 1, "");
    string res2 = helper1(s1, s2, l1 - 1, l2, "");
    if (res1.size() > res2.size())
        return res1;
    return res2;
}

string longestCommonSubstr1(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();

    return helper1(s1, s2, l1, l2, "");
}

// Approach 2:
// Recursion + Memoization
string helper2(string s1, string s2, int l1, int l2, string maxString, vector<vector<string>> &dp)
{
    if (l1 == 0 or l2 == 0)
        return maxString;

    if (dp[l1][l2] != "")
        return dp[l1][l2];

    if (s1[l1] == s2[l2])
        return dp[l1][l2] = helper2(s1, s2, l1 - 1, l2 - 1, s1[l1] + maxString, dp);

    string res1 = helper2(s1, s2, l1, l2 - 1, "", dp);
    string res2 = helper2(s1, s2, l1 - 1, l2, "", dp);
    if (res1.size() > res2.size())
        return dp[l1][l2] = res1;
    return dp[l1][l2] = res2;
}

string longestCommonSubstr2(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<string>> dp(l1 + 1, vector<string>(l2 + 1, ""));

    return helper2(s1, s2, l1, l2, "", dp);
}

// Approach 3:
// Tabulation + Iteration
string longestCommonSubstr3(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<string>> dp(l1 + 1, vector<string>(l2 + 1, ""));
    string res{};

    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
            else
                dp[i][j] = "";
            if (dp[i][j].size() > res.size())
                res = dp[i][j];
        }
    }

    return res;
}

void solve()
{
    string s1{"ABCDGH"};
    string s2{"ACDGHR"};

    // CDGH
    cout << longestCommonSubstr1(s1, s2) << endl;
    cout << longestCommonSubstr2(s1, s2) << endl;
    cout << longestCommonSubstr3(s1, s2) << endl;
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