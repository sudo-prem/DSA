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

    string res1{}, res2{}, res3{};
    if (s1[l1] == s2[l2])
        res1 = helper1(s1, s2, l1 - 1, l2 - 1, s1[l1] + maxString);
    res2 = helper1(s1, s2, l1, l2 - 1, "");
    res3 = helper1(s1, s2, l1 - 1, l2, "");

    if (res1.size() > res2.size())
        return (res1.size() > res3.size()) ? res1 : res3;
    return (res2.size() > res3.size()) ? res2 : res3;
}

string longestCommonSubstring1(string s1, string s2)
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

    string res1{}, res2{}, res3{};
    if (s1[l1] == s2[l2])
        res1 = dp[l1][l2] = helper2(s1, s2, l1 - 1, l2 - 1, s1[l1] + maxString, dp);
    res2 = helper2(s1, s2, l1, l2 - 1, "", dp);
    res3 = helper2(s1, s2, l1 - 1, l2, "", dp);

    if (res1.size() > res2.size())
        return dp[l1][l2] = (res1.size() > res3.size()) ? res1 : res3;
    return dp[l1][l2] = (res2.size() > res3.size()) ? res2 : res3;
}

string longestCommonSubstring2(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<string>> dp(l1 + 1, vector<string>(l2 + 1, ""));

    return helper2(s1, s2, l1, l2, "", dp);
}

// Approach 3:
// Tabulation + Iteration
string longestCommonSubstring3(string s1, string s2)
{
    // Data Structures
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    int maxLen{}, row{}, col{};

    // Tabulation
    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;

            if (dp[i][j] > maxLen)
            {
                maxLen = dp[i][j];
                row = i;
                col = j;
            }
        }
    }

    // String Retreival
    string res;
    while (dp[row][col] != 0)
    {
        res.push_back(s1[row - 1]);
        row--;
        col--;
    }

    reverse(res.begin(), res.end());
    return res;
}

void solve()
{
    string s1{"ABCDGH"};
    string s2{"ACDGHR"};

    // CDGH
    cout << longestCommonSubstring1(s1, s2) << endl;
    cout << longestCommonSubstring2(s1, s2) << endl;
    cout << longestCommonSubstring3(s1, s2) << endl;
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