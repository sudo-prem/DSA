// Problem Link:
// https://leetcode.com/problems/coin-change-2/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(int amount, vector<int> &coins, int index)
{
    if (amount == 0)
        return 1;
    if (index == 0)
        return 0;

    if (amount - coins[index - 1] >= 0)
        return (helper1(amount - coins[index - 1], coins, index) +
                helper1(amount, coins, index - 1));
    return helper1(amount, coins, index - 1);
}

int change1(int amount, vector<int> &coins)
{
    return helper1(amount, coins, coins.size());
}

// Approach 2:
// Recursion + Memoization
int helper2(int amount, vector<int> &coins, int index, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 1;
    if (index == 0)
        return 0;

    if (dp[index][amount] != -1)
        return dp[index][amount];

    if (amount - coins[index - 1] >= 0)
        return dp[index][amount] = helper2(amount - coins[index - 1], coins, index, dp) +
                                   helper2(amount, coins, index - 1, dp);
    return dp[index][amount] = helper2(amount, coins, index - 1, dp);
}

int change2(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

    return helper2(amount, coins, coins.size(), dp);
}

// Approach 3:
// Tabulation + Iteration
int change3(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= amount; ++j)
        {
            if (j - coins[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][amount];
}

void solve()
{
    vector<int> coins{1, 2, 5};
    int amount{5};

    // 4
    cout << change1(amount, coins) << endl;
    cout << change2(amount, coins) << endl;
    cout << change3(amount, coins) << endl;
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