// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int helper(vector<int> &heights, int pos, vector<int> &dp)
{
	int n = heights.size();
	if (pos == n - 1)
		return 0;
	if (pos + 1 == n - 1)
		return dp[pos] = abs(heights[pos] - heights[pos + 1]) + helper(heights, pos + 1, dp);
	if (dp[pos] != -1)
		return dp[pos];

	int res1 = abs(heights[pos] - heights[pos + 2]) + helper(heights, pos + 2, dp);
	int res2 = abs(heights[pos] - heights[pos + 1]) + helper(heights, pos + 1, dp);

	return dp[pos] = min(res1, res2);
}

int frogJump1(int n, vector<int> &heights)
{
	vector<int> dp(n, -1);
	return helper(heights, 0, dp);
}

int frogJump2(int n, vector<int> &heights)
{
	vector<int> dp(n, 0);
	dp[1] = abs(heights[1] - heights[0]);

	for (int i = 2; i < n; ++i)
	{
		dp[i] = min(
		            dp[i - 1] + abs(heights[i - 1] - heights[i]),
		            dp[i - 2] + abs(heights[i - 2] - heights[i])
		        );
	}

	return dp[n - 1];
}

int frogJump3(int n, vector<int> &heights)
{
	vector<int> dp(n, 0);
	int curr, prev, prevBefore{};
	prev = curr = abs(heights[1] - heights[0]);

	for (int i = 2; i < n; ++i)
	{
		curr = min (
		           prev + abs(heights[i - 1] - heights[i]),
		           prevBefore + abs(heights[i - 2] - heights[i])
		       );

		prevBefore = prev;
		prev = curr;
	}

	return curr;
}

void solve()
{
	vector<int> heights{10, 20, 30, 10};

	cout << frogJump1(4, heights) << endl;
	cout << frogJump2(4, heights) << endl;
	cout << frogJump3(4, heights) << endl;
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
