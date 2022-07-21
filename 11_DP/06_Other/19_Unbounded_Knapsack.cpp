#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &profit, vector<int> &weight, int pos, int target, vector<vector<int>> &dp)
{
	if (pos == 0)
	{
		if (target >= weight[0])
			return (target / weight[0]) * profit[0];
		return 0;
	}
	if (dp[pos][target] != -1)
		return dp[pos][target];

	int notTake = helper(profit, weight, pos - 1, target, dp);
	int take{};
	if (target >= weight[pos])
		take = profit[pos] + helper(profit, weight, pos, target - weight[pos], dp);

	return dp[pos][target] = max(take, notTake);
}

int unboundedKnapsack1(int n, int target, vector<int> &profit, vector<int> &weight)
{
	vector<vector<int>> dp(n, vector<int> (target + 1, -1));

	return helper(profit, weight, n - 1, target, dp);
}

// Approach 2:
int unboundedKnapsack2(int n, int target, vector<int> &profit, vector<int> &weight)
{
	vector<vector<int>> dp(n, vector<int> (target + 1, 0));
	for (int i = 0; i <= target; ++i)
		if (i >= weight[0])
			dp[0][i] = (i / weight[0]) * profit[0];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			int notTake = dp[i - 1][j];
			int take{};
			if (j >= weight[i])
				take = profit[i] + dp[i][j - weight[i]];

			dp[i][j] = max(take, notTake);
		}
	}

	return dp[n - 1][target];
}

// Approach 3:
int unboundedKnapsack3(int n, int target, vector<int> &profit, vector<int> &weight)
{
	vector<vector<int>> dp(2, vector<int> (target + 1, 0));

	for (int i = 0; i <= target; ++i)
		if (i >= weight[0])
			dp[0][i] = (i / weight[0]) * profit[0];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			int notTake = dp[(i - 1) % 2][j];
			int take{};
			if (j >= weight[i])
				take = profit[i] + dp[i % 2][j - weight[i]];

			dp[i % 2][j] = max(take, notTake);
		}
	}

	return dp[(n - 1) % 2][target];
}

void solve()
{
	vector<int> profit{5, 11, 13}, weight{2, 4, 6};
	int n{3}, target{10};

	cout << unboundedKnapsack1(n, target, profit, weight) << endl;
	cout << unboundedKnapsack2(n, target, profit, weight) << endl;
	cout << unboundedKnapsack3(n, target, profit, weight) << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	freopen("input.txt", "r", stdin);
#endif
	int t {1};
	/* int i {1}; cin >> t; */
	while (t--)
	{
		/* cout << "Case #" << i++ << ": "; */
		solve();
	}
	return 0;
}
