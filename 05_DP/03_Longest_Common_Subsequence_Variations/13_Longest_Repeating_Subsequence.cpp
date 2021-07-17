// Problem Link:
// https://www.interviewbit.com/problems/repeating-subsequence/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

int longestRepeatingSubsequence(string &word)
{
    // Data Structures
    int n = word.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Tabulation
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i != j and word[i - 1] == word[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

void solve()
{
    string word{"aabebcdd"};

    cout << longestRepeatingSubsequence(word) << endl;
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