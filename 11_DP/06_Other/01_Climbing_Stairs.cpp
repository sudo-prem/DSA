// Same as Fibonacci
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int helper(int n, vector<int> &dp)
{
	if (!n)
		return 1;
	if (n < 0)
		return 0;
	if (dp[n] != -1)
		return dp[n];

	return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
}

int climbStairs(int n)
{
	vector<int> dp(n + 1, -1);
	return helper(n, dp);
}

void solve()
{
	cout << climbStairs(5) << endl;
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
