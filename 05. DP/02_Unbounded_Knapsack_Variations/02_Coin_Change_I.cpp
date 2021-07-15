// Problem Link:
// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(vector<int> &coins, int amount, int index)
{
    if (amount == 0)
        return 0;
    if (index == 0)
        return -1;

    if (amount - coins[index - 1] >= 0)
    {
        int taken = 1 + helper1(coins, amount - coins[index - 1], index);
        int notTaken = helper1(coins, amount, index - 1);
        if (taken == 0)
            return notTaken;
        if (notTaken == -1)
            return taken;
        return min(taken, notTaken);
    }
    return helper1(coins, amount, index - 1);
}

int coinChange1(vector<int> &coins, int amount)
{
    return helper1(coins, amount, coins.size());
}

// Approach 2:
// Recursion + Memoization
int helper2(vector<int> &coins, int amount, int index, vector<unordered_map<int, int>> &dp)
{
    if (amount == 0)
        return 0;
    if (index == 0)
        return -1;

    if (dp[index].find(amount) != dp[index].end())
        return dp[index][amount];

    if (amount - coins[index - 1] >= 0)
    {
        int taken = 1 + helper2(coins, amount - coins[index - 1], index, dp);
        int notTaken = helper2(coins, amount, index - 1, dp);
        if (taken == 0)
            return dp[index][amount] = notTaken;
        if (notTaken == -1)
            return dp[index][amount] = taken;
        return dp[index][amount] = min(taken, notTaken);
    }
    return dp[index][amount] = helper2(coins, amount, index - 1, dp);
}

int coinChange2(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<unordered_map<int, int>> dp(n + 1);
    return helper2(coins, amount, coins.size(), dp);
}

// Approach 3:
// Tabulation + Iteration
int coinChange3(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // Initialization
    for (int i = 1; i <= amount; ++i)
        dp[0][i] = -1;

    for (int i = 1; i <= n; ++i)
    {
        int curr = coins[i - 1];
        for (int j = 1; j <= amount; ++j)
        {
            if (j - curr >= 0)
            {
                int taken = 1 + dp[i][j - curr];
                int notTaken = dp[i - 1][j];
                if (taken == 0)
                    dp[i][j] = notTaken;
                else if (notTaken == -1)
                    dp[i][j] = taken;
                else
                    dp[i][j] = min(taken, notTaken);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][amount];
}

void solve()
{
    vector<int> coins{2, 5, 10, 1};
    int amount{27};

    // 4
    cout << coinChange1(coins, amount) << endl;
    cout << coinChange2(coins, amount) << endl;
    cout << coinChange3(coins, amount) << endl;
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