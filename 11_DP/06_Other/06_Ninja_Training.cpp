#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<vector<int>> &points, int pos, int prev, vector<vector<int>> &dp)
{
	int n = points.size();
	if (pos == n)
		return 0;
	if (dp[pos][prev + 1] != -1)
		return dp[pos][prev + 1];

	int res{};
	for (int i = 0; i < 3; ++i)
	{
		if (i == prev)
			continue;
		res = max(res, points[pos][i] + helper(points, pos + 1, i, dp));
	}

	return dp[pos][prev + 1] = res;
}

int ninjaTraining1(int n, vector<vector<int>> &points)
{
	vector<vector<int>> dp(n, vector<int> (4, -1));
	return helper(points, 0, -1, dp);
}

// Approach 2:
int ninjaTraining2(int n, vector<vector<int>> &points)
{
	vector<vector<int>> dp(n, vector<int> (3, -1));
	dp[0][0] = points[0][0], dp[0][1] = points[0][1], dp[0][2] = points[0][2];

	int res{};
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				if (k == j)
					continue;
				dp[i][j] = max(dp[i][j], points[i][j] + dp[i - 1][k]);
			}
			res = max(res, dp[i][j]);
		}
	}

	return res;
}

// Approach 3:
int ninjaTraining3(int n, vector<vector<int>> &points)
{
	vector<vector<int>> dp(2, vector<int> (3, -1));
	dp[0][0] = points[0][0], dp[0][1] = points[0][1], dp[0][2] = points[0][2];

	int res{};
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				if (k == j)
					continue;
				dp[1][j] = max(dp[1][j], points[i][j] + dp[0][k]);
			}
			res = max(res, dp[1][j]);
		}

		dp[0] = dp[1];
		fill(dp[1].begin(), dp[1].end(), 0);
	}

	return res;
}

void solve()
{
	int n = 3;
	vector<vector<int>> points{{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};

	cout << ninjaTraining1(n, points) << endl;
	cout << ninjaTraining2(n, points) << endl;
	cout << ninjaTraining3(n, points) << endl;
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
