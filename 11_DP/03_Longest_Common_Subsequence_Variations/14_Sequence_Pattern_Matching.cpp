// Problem Link:
// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// DP
int lcs(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[l1][l2];
}

bool isSubsequence1(string s, string t)
{
    if (lcs(s, t) == s.size())
        return true;
    return false;
}

// Approach 2:
// Two Pointers
bool isSubsequence2(string s, string t)
{
    int i = 0, j = 0;
    int l1 = s.size();
    int l2 = t.size();

    while (i < l1 and j < l2)
    {
        if (s[i] == t[j])
            i++;
        j++;
    }

    if (i == l1)
        return true;
    return false;
}

void solve()
{
    string s{"abc"};
    string t{"ahbgdc"};

    cout << isSubsequence1(s, t) << endl;
    cout << isSubsequence2(s, t) << endl;
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