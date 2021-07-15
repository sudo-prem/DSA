// Problem Link:
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
// Recursion
int helper1(vector<int> &weight, vector<int> &profit, int capacity, int index)
{
    if (capacity == 0 or index == 0)
        return 0;

    if (capacity - weight[index - 1] >= 0)
        return max(helper1(weight, profit, capacity - weight[index - 1], index - 1) + profit[index - 1],
                   helper1(weight, profit, capacity, index - 1));
    else
        return helper1(weight, profit, capacity, index - 1);
}

int knapsack1(vector<int> &weight, vector<int> &profit, int capacity)
{
    return helper1(weight, profit, capacity, weight.size());
}

// Approach 2:
// Recursion + Memoization (Top - Down)
int helper2(vector<int> &weight, vector<int> &profit, int capacity, int index, vector<vector<int>> &dp)
{
    if (capacity == 0 or index == 0)
        return 0;

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    if (capacity - weight[index - 1] >= 0)
        return dp[index][capacity] = max(helper2(weight, profit, capacity - weight[index - 1], index - 1, dp) + profit[index - 1],
                                         helper2(weight, profit, capacity, index - 1, dp));
    else
        return dp[index][capacity] = helper2(weight, profit, capacity, index - 1, dp);
}

int knapsack2(vector<int> &weight, vector<int> &profit, int capacity)
{
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    return helper2(weight, profit, capacity, weight.size(), dp);
}

// Approach 3:
// Iteration + Tabulation (Bottom - Up)
int knapsack3(vector<int> &weight, vector<int> &profit, int capacity)
{
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= capacity; ++j)
        {
            if (j - weight[i - 1] >= 0)
                dp[i][j] = max(dp[i - 1][j], profit[i - 1] + dp[i - 1][j - weight[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][capacity];
}

void solve()
{
    vector<int> weight{4, 5, 1};
    vector<int> profit{1, 2, 3};
    int capacity{4};

    // 3
    cout << knapsack1(weight, profit, capacity) << endl;
    cout << knapsack2(weight, profit, capacity) << endl;
    cout << knapsack3(weight, profit, capacity) << endl;
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