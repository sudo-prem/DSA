// Problem Link:
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

int longestCommonSubsequence(string word1, string word2)
{
    int l1 = word1.size();
    int l2 = word2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[l1][l2];
}

int minInsertions(string word1)
{
    string word2(word1.rbegin(), word1.rend());
    int stringSize = word1.size();

    int lcs = longestCommonSubsequence(word1, word2);
    return stringSize - lcs;
}

void solve()
{
    string word{"mbadm"};

    cout << minInsertions(word) << endl;
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