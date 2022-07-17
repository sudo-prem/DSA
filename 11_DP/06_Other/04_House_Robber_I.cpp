// Problem Link:
// https://leetcode.com/problems/house-robber
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(int *arr, int n, int pos, vector<int> &dp)
{
	if (pos >= n)
		return 0;
	if (dp[pos] != -1)
		return dp[pos];

	return dp[pos] = max(helper(arr, n, pos + 1, dp), arr[pos] + helper(arr, n, pos + 2, dp));
}

int findMaxSum1(int *arr, int n)
{
	vector<int> dp(n, -1);
	return helper(arr, n, 0, dp);
}

// Approach 2:
int findMaxSum2(int *arr, int n)
{
	vector<int> dp(n);
	dp[0] = arr[0];
	dp[1] = max(arr[1], arr[0]);

	for (int i = 2; i < n; ++i)
		dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);

	return dp[n - 1];
}

// Approach 3:
int findMaxSum3(int *arr, int n)
{
	if (n == 1)
		return arr[0];

	vector<int> dp(n);
	int prevBefore = arr[0],
	    prev = max(arr[1], arr[0]),
	    curr = max(prevBefore, prev);

	for (int i = 2; i < n; ++i)
	{
		curr = max(prev, arr[i] + prevBefore);
		prevBefore = prev;
		prev = curr;
	}

	return curr;
}

void solve()
{
	int arr[] {5, 5, 10, 100, 10, 5};
	int n = 6;

	cout << findMaxSum1(arr, n) << endl;
	cout << findMaxSum2(arr, n) << endl;
	cout << findMaxSum3(arr, n) << endl;
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
