#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
{
	int m = grid.size(), n = grid[0].size();
	if (row == m - 1 and col == n - 1)
		return 1;
	if (row == m or col == n)
		return 0;
	if (dp[row][col] != -1)
		return dp[row][col];

	int res{};
	vector<int> dRow{0, 1}, dCol{1, 0};
	for (int i = 0; i < 2; ++i)
	{
		int x = dRow[i] + row;
		int y = dCol[i] + col;
		if (x < m and y < n and grid[x][y] != -1)
			res = (res + helper(grid, x, y, dp)) % 1000000007;
	}

	return dp[row][col] = res;
}

int mazeObstacles1(int m, int n, vector<vector<int>> &grid)
{
	vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
	return helper(grid, 0, 0, dp);
}

// Approach 2:
int mazeObstacles2(int m, int n, vector<vector<int>> &grid)
{
	int MOD = 1e9 + 7;
	vector<vector<int>> dp(m, vector<int> (n, 0));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 and j == 0)
				dp[i][j] = 1;
			else if (grid[i][j] == -1)
				dp[i][j] = 0;
			else
			{
				if (i - 1 >= 0)
					dp[i][j] = dp[i - 1][j];
				if (j - 1 >= 0)
					dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
			}
		}
	}

	return dp[m - 1][n - 1];
}

// Approach 3:
int mazeObstacles3(int m, int n, vector<vector<int>> &grid)
{
	int MOD = 1e9 + 7;
	vector<vector<int>> dp(2, vector<int> (n, 0));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 and j == 0)
				dp[i % 2][j] = 1;
			else if (grid[i][j] == -1)
				dp[i % 2][j] = 0;
			else
			{
				if (i - 1 >= 0)
					dp[i % 2][j] = dp[(i - 1) % 2][j];
				if (j - 1 >= 0)
					dp[i % 2][j] = (dp[i % 2][j] + dp[i % 2][j - 1]) % MOD;
			}
		}
	}

	return dp[(m - 1) % 2][n - 1];
}

void solve()
{
	int n = 3, m = 3;
	vector<vector<int>> grid(m, vector<int> (n, 0));
	grid[1][1] = -1;

	cout << mazeObstacles1(m, n, grid) << endl;
	cout << mazeObstacles2(m, n, grid) << endl;
	cout << mazeObstacles3(m, n, grid) << endl;
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
