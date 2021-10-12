// Problem Link:
// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

int shortestCommonSupersequence(string str1, string str2)
{
    // Data structures needed
    int l1 = str1.size();
    int l2 = str2.size();
    int res{};
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    // Tabulate LCS
    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    res = l1 + l2 - dp[l1][l2];
    return res;
}

void solve()
{
    string str1{"abac"};
    string str2{"cab"};

    cout << shortestCommonSupersequence(str1, str2) << endl;
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