// Problem Link:
// https://leetcode.com/problems/shortest-common-supersequence/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

string shortestCommonSupersequence(string str1, string str2)
{
    // Data Structures
    int l1 = str1.size();
    int l2 = str2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    // Tabulate
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

    // Retreive SCS from table
    int i = l1, j = l2;
    string lcs{};
    while (i > 0 and j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                lcs.push_back(str1[i - 1]);
                i--;
            }
            else
            {
                lcs.push_back(str2[j - 1]);
                j--;
            }
        }
    }

    // Take remaining characters from strings
    while (i > 0)
    {
        lcs.push_back(str1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        lcs.push_back(str2[j - 1]);
        j--;
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

void solve()
{
    string str1{"AGGTAB"};
    string str2{"GXTXAYB"};

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