#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<int> &weight, vector<int> &value, int pos, int capacity, vector<vector<int>> &dp)
{
	int n = weight.size();
	if (pos == n)
		return 0;
	if (dp[pos][capacity] != -1)
		return dp[pos][capacity];

	int take{}, notTake{};
	notTake = helper(weight, value, pos + 1, capacity, dp);
	if (capacity >= weight[pos])
		take = value[pos] + helper(weight, value, pos + 1, capacity - weight[pos], dp);

	return dp[pos][capacity] = max(take, notTake);
}

int knapsack1(vector<int> weight, vector<int> value, int n, int capacity)
{
	vector<vector<int>> dp(n, vector<int> (capacity + 1, -1));

	return helper(weight, value, 0, capacity, dp);
}

// Approach 2:
int knapsack2(vector<int> weight, vector<int> value, int n, int capacity)
{
	vector<vector<int>> dp(n, vector<int> (capacity + 1, 0));
	for (int i = weight[0]; i <= capacity; ++i)
		dp[0][i] = value[0];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= capacity; ++j)
		{
			if (j >= weight[i])
				dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n - 1][capacity];
}

// Approach 3:
int knapsack3(vector<int> weight, vector<int> value, int n, int capacity)
{
	vector<vector<int>> dp(2, vector<int> (capacity + 1, 0));
	for (int i = weight[0]; i <= capacity; ++i)
		dp[0][i] = value[0];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= capacity; ++j)
		{
			if (j >= weight[i])
				dp[i % 2][j] = max(dp[(i - 1) % 2][j], value[i] + dp[(i - 1) % 2][j - weight[i]]);
			else
				dp[i % 2][j] = dp[(i - 1) % 2][j];
		}
	}

	return dp[(n - 1) % 2][capacity];
}

void solve()
{
	int n = 4, capacity = 5;
	vector<int> weight{1, 2, 4, 5};
	vector<int> value{5, 4, 8, 6};

	cout << knapsack1(weight, value, n, capacity) << endl;
	cout << knapsack2(weight, value, n, capacity) << endl;
	cout << knapsack3(weight, value, n, capacity) << endl;
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
