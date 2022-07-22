#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

// Approach 1:
int helper(int arr[], int n, int index, int prev, vector<vector<int>> &dp)
{
	if (index == n)
		return 0;
	if (dp[index][prev + 1] != -1)
		return dp[index][prev + 1];

	int notTake = helper(arr, n, index + 1, prev, dp);
	int take{};
	if (prev == -1 or arr[prev] < arr[index])
		take = 1 + helper(arr, n, index + 1, index, dp);

	return dp[index][prev + 1] = max(notTake, take);
}

int longestIncreasingSubsequence1(int arr[], int n)
{
	vector<vector<int>> dp(n, vector<int> (n + 1, -1));

	return helper(arr, n, 0, -1, dp);
}

// Approach 2:
int longestIncreasingSubsequence2(int arr[], int n)
{
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

	for (int i = n; i >= 0; --i)
	{
		for (int j = i; j >= 0; --j)
		{
			if (i == n)
				dp[i][j] = 0;
			else
			{
				int notTake = dp[i + 1][j];
				int take{};
				if (j == 0 or arr[j - 1] < arr[i])
					take = 1 + dp[i + 1][i + 1];

				dp[i][j] = max(notTake, take);
			}
		}
	}

	return dp[0][0];
}

// Approach 3:
int longestIncreasingSubsequence3(int arr[], int n)
{
	vector<vector<int>> dp(2, vector<int> (n + 1, 0));

	for (int i = n; i >= 0; --i)
	{
		for (int j = i; j >= 0; --j)
		{
			if (i == n)
				dp[i % 2][j] = 0;
			else
			{
				int notTake = dp[(i + 1) % 2][j];
				int take{};
				if (j == 0 or arr[j - 1] < arr[i])
					take = 1 + dp[(i + 1) % 2][i + 1];

				dp[i % 2][j] = max(notTake, take);
			}
		}
	}

	return dp[0][0];
}

// Approach 4:
int longestIncreasingSubsequence4(int arr[], int n)
{
	vector<int> dp(n, 1);
	int res{};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}

	return res;
}

// Approach 5:
int longestIncreasingSubsequence5(int arr[], int n)
{
	if (n == 0)
		return 0;

	vector<int> sorted{arr[0]};

	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > sorted.back())
			sorted.push_back(arr[i]);
		else
		{
			auto itr = lower_bound(sorted.begin(), sorted.end(), arr[i]);
			*itr = arr[i];
		}
	}

	return sorted.size();
}

void solve()
{
	int arr[] {5, 4, 11, 1, 16, 8};
	int n = 6;

	cout << longestIncreasingSubsequence1(arr, n) << endl;
	cout << longestIncreasingSubsequence2(arr, n) << endl;
	cout << longestIncreasingSubsequence3(arr, n) << endl;
	cout << longestIncreasingSubsequence4(arr, n) << endl;
	cout << longestIncreasingSubsequence5(arr, n) << endl;
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
