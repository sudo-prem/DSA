// Problem Link:
// NA

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursive (String concatenation overhead)
string helper1(string &text1, string &text2, int l1, int l2)
{
    if (l1 == 0 or l2 == 0)
        return "";

    if (text1[l1 - 1] == text2[l2 - 1])
        return text1[l1 - 1] + helper1(text1, text2, l1 - 1, l2 - 1);

    string res1 = helper1(text1, text2, l1, l2 - 1);
    string res2 = helper1(text1, text2, l1 - 1, l2);
    if (res1.size() > res2.size())
        return res1;
    return res2;
}

string printLCS1(string &text1, string &text2)
{
    int l1 = text1.size();
    int l2 = text2.size();

    return helper1(text1, text2, l1, l2);
}

// Approach 2:
// Recursion + Memoization (String concatenation overhead)
string helper2(string text1, string text2, int l1, int l2, vector<vector<string>> &dp)
{
    if (l1 == 0 or l2 == 0)
        return "";

    if (dp[l1][l2] != "")
        return dp[l1][l2];

    if (text1[l1 - 1] == text2[l2 - 1])
        return dp[l1][l2] = text1[l1 - 1] + helper2(text1, text2, l1 - 1, l2 - 1, dp);

    string res1 = dp[l1][l2 - 1] = helper2(text1, text2, l1, l2 - 1, dp);
    string res2 = dp[l1 - 1][l2] = helper2(text1, text2, l1 - 1, l2, dp);
    if (res1.size() > res2.size())
        return dp[l1][l2] = res1;
    return dp[l1][l2] = res2;
}

string printLCS2(string &text1, string &text2)
{
    int l1 = text1.size();
    int l2 = text2.size();
    vector<vector<string>> dp(l1 + 1, vector<string>(l2 + 1, ""));

    return helper2(text1, text2, l1, l2, dp);
}

// Approach 3:
// Tabulation + Iteration (String concatenation overhead)
string printLCS3(string &text1, string &text2)
{
    int l1 = text1.size();
    int l2 = text2.size();
    vector<vector<string>> dp(l1 + 1, vector<string>(l2 + 1));

    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = text1[i - 1] + dp[i - 1][j - 1];
            else
            {
                if (dp[i - 1][j].size() > dp[i][j - 1].size())
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[l1][l2];
}

// Approach 4:
// Tabulation + Iteration
string printLCS4(string text1, string text2)
{
    int l1 = text1.size();
    int l2 = text2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    // Find LCS
    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    // Find string from LCS
    string lcs{};
    int i = l1, j = l2;
    while (i > 0 and j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            lcs += text1[i - 1];
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

    return lcs;
}

void solve()
{
    string text1 = "acbcf";
    string text2 = "abcdaf";

    // The returned strings are not reversed, we may reverse it if need be
    cout << printLCS1(text1, text2) << endl;
    cout << printLCS2(text1, text2) << endl;
    cout << printLCS3(text1, text2) << endl;
    cout << printLCS4(text1, text2) << endl;
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