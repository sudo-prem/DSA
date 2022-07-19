#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<vector<int>> &triangle, int row, int col, vector<vector<int>> &dp)
{
	int n = triangle.size();
	if (row == n)
		return 0;
	if (dp[row][col] != -1)
		return dp[row][col];

	int res1 = helper(triangle, row + 1, col + 1, dp);
	int res2 = helper(triangle, row + 1, col, dp);

	return dp[row][col] = triangle[row][col] + min(res1, res2);
}

int minimumPathSum1(vector<vector<int>>& triangle, int n)
{
	vector<vector<int>> dp(n, vector<int> (n, -1));

	return helper(triangle, 0, 0, dp);
}

// Approach 2:
int minimumPathSum2(vector<vector<int>>& triangle, int n)
{
	vector<vector<int>> dp(n, vector<int> (n, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (i == 0)
				dp[i][j] = triangle[i][j];
			else if (j == 0)
				dp[i][j] = triangle[i][j] + dp[i - 1][j];
			else if (j == i)
				dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
			else
				dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}

	return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

// Approach 3:
int minimumPathSum3(vector<vector<int>>& triangle, int n)
{
	vector<vector<int>> dp(2, vector<int> (n, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (i == 0)
				dp[i % 2][j] = triangle[i][j];
			else if (j == 0)
				dp[i % 2][j] = triangle[i][j] + dp[(i - 1) % 2][j];
			else if (j == i)
				dp[i % 2][j] = triangle[i][j] + dp[(i - 1) % 2][j - 1];
			else
				dp[i % 2][j] = triangle[i][j] + min(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - 1]);
		}
	}

	return *min_element(dp[(n - 1) % 2].begin(), dp[(n - 1) % 2].end());
}

void solve()
{
	int n = 4;
	vector<vector<int>> triangle{{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 1}};

	cout << minimumPathSum1(triangle, n) << endl;
	cout << minimumPathSum2(triangle, n) << endl;
	cout << minimumPathSum3(triangle, n) << endl;
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
