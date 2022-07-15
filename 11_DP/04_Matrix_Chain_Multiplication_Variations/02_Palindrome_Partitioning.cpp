// Problem Link:
// https://leetcode.com/problems/palindrome-partitioning-ii/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

bool isPalindrome(string &word, int i, int j)
{
    while (i < j)
        if (word[i++] != word[j--])
            return false;
    return true;
}

// Approach 1:
// TLE on leetcode
int helper1(string &word, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (isPalindrome(word, i, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int minPart{INT_MAX};
    for (int k = i; k < j; ++k)
    {
        int curr = helper1(word, i, k, dp) + 1 + helper1(word, k + 1, j, dp);
        minPart = min(minPart, curr);
    }

    return dp[i][j] = minPart;
}

int palindromicPartition1(string word)
{
    int n = word.size();
    int i = 0, j = n - 1;
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return helper1(word, i, j, dp);
}

// Approach 2:
// Works on all online judge
int helper2(string &word, int i, int j, vector<int> &dp)
{
    if (i > j)
        return 0;

    if (isPalindrome(word, i, j))
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int minPart{INT_MAX};
    for (int k = i; k < j; ++k)
    {
        if (isPalindrome(word, i, k))
            minPart = min(minPart, 1 + helper2(word, k + 1, j, dp));
    }

    return dp[i] = minPart;
}

int palindromicPartition2(string word)
{
    int n = word.size();
    int i = 0, j = n - 1;
    vector<int> dp(word.size(), -1);

    return helper2(word, i, j, dp);
}

void solve()
{
    string word{"aaabba"};

    cout << palindromicPartition1(word) << endl;
    cout << palindromicPartition2(word) << endl;
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