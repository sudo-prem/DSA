#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

vector<int> longestIncreasingSubsequence(int arr[], int n)
{
	vector<int> dp(n, 1), backtrack(n);
	for (int i = 0; i < n; ++i)
		backtrack[i] = i;

	int maxCount{}, index{};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i] and 1 + dp[j] > dp[i])
			{
				dp[i] = 1 + dp[j];
				backtrack[i] = j;

				if (dp[i] > maxCount)
				{
					maxCount = dp[i];
					index = i;
				}
			}
		}

	}

	vector<int> res{};
	while (maxCount)
	{
		res.push_back(arr[index]);
		index = backtrack[index];
		maxCount--;
	}

	reverse(res.begin(), res.end());
	return res;
}

void solve()
{
	int n = 8;
	int arr[] {10, 9, 2, 5, 3, 7, 101, 18};

	auto res = longestIncreasingSubsequence(arr, n);

	for (int num : res)
		cout << num << " ";
	cout << endl;
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
