#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int maximumProfit(vector<int> &prices)
{
	int n = prices.size();
	int currMin = prices[0], res{};

	for (int i = 1; i < n; ++i)
	{
		res = max(res, prices[i] - currMin);
		currMin = min(currMin, prices[i]);
	}

	return res;
}

void solve()
{
	vector<int> prices{1, 2, 3, 4};

	cout << maximumProfit(prices) << endl;
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
