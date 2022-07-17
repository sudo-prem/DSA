#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(int m, int n, int row, int col, vector<vector<int>> &dp)
{
	if (row == m - 1 and col == n - 1)
		return 1;
	if (row == m or col == n)
		return 0;
	if (dp[row][col] != -1)
		return dp[row][col];

	return dp[row][col] = helper(m, n, row + 1, col, dp) + helper(m, n, row, col + 1, dp);
}

int uniquePaths1(int m, int n)
{
	vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));

	return helper(m, n, 0, 0, dp);
}

// Approach 2:
int uniquePaths2(int m, int n)
{
	vector<vector<int>> dp(m, vector<int> (n, -1));
	for (int i = 0; i < m; ++i)
		dp[i][0] = 1;
	for (int i = 0; i < n; ++i)
		dp[0][i] = 1;

	for (int i = 1; i < m; ++i)
		for (int j = 1; j < n; ++j)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

	return dp[m - 1][n - 1];
}

// Approach 3:
int uniquePaths3(int m, int n)
{
	vector<vector<int>> dp(2, vector<int> (n));
	for (int i = 0; i < 2; ++i)
		dp[i % 2][0] = 1;
	for (int i = 0; i < n; ++i)
		dp[0][i] = 1;

	for (int i = 1; i < m; ++i)
		for (int j = 1; j < n; ++j)
			dp[i % 2][j] = dp[(i - 1) % 2][j] + dp[i % 2][j - 1];

	return dp[(m - 1) % 2][n - 1];
}

void solve()
{
	cout << uniquePaths1(3, 7) << endl;
	cout << uniquePaths2(3, 7) << endl;
	cout << uniquePaths3(3, 7) << endl;
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
