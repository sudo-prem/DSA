// Problem Link:
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(int price[], int n, int rod)
{
    if (rod == 0 or n == 0)
        return 0;

    if (rod - n >= 0)
        return max(helper1(price, n - 1, rod),
                   helper1(price, n, rod - n) + price[n - 1]);
    return helper1(price, n - 1, rod);
}

int cutRod1(int price[], int n)
{
    return helper1(price, n, n);
}

// Approach 2:
// Recursion + Memoization
int helper2(int price[], int n, int rod, vector<vector<int>> &dp)
{
    if (rod == 0 or n == 0)
        return 0;

    if (dp[n][rod] != -1)
        return dp[n][rod];

    if (rod - n >= 0)
        return dp[n][rod] = max(helper2(price, n, rod - n, dp) + price[n - 1],
                                helper2(price, n - 1, rod, dp));
    return dp[n][rod] = helper2(price, n - 1, rod, dp);
}

int cutRod2(int price[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return helper2(price, n, n, dp);
}

// Approach 3:
// Tabulation + Iteration
int cutRod3(int price[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j - i >= 0)
                dp[i][j] = max(dp[i][j], price[i - 1] + dp[i][j - i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][n];
}

void solve()
{
    // int price[]{3, 9, 13, 12, 8, 12, 8, 8, 3, 10, 13};
    int price[]{10, 12, 13, 3, 3, 6, 1, 6, 1, 2, 11, 10};
    int n = sizeof(price) / sizeof(price[0]);

    cout << cutRod1(price, n) << endl;
    cout << cutRod2(price, n) << endl;
    cout << cutRod3(price, n) << endl;
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