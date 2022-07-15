#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int getHours(vector<int> &piles, int k)
{
	int res{}, n = piles.size();

	for (int i = 0; i < n; ++i)
	{
		res += piles[i] / k;
		res += piles[i] % k == 0 ? 0 : 1;
	}

	return res;
}

int minEatingSpeed(vector<int> &piles, int h)
{
	int low = 1, high = 1e9;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		int curr = getHours(piles, mid);

		if (curr <= h)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return low;
}

void solve()
{
	vector<int> piles{3, 6, 7, 11};
	int h = 8;

	cout << minEatingSpeed(piles, h) << endl;
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
