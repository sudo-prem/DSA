#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

ll sumBetweenTwoKth(ll nums[], ll n, ll k1, ll k2)
{
	priority_queue<int> maxHeap;
	for (ll i = 0; i < k2 - 1; ++i)
		maxHeap.push(nums[i]);

	for (ll i = k2 - 1; i < n; ++i)
	{
		if (nums[i] < maxHeap.top())
		{
			maxHeap.pop();
			maxHeap.push(nums[i]);
		}
	}

	ll t = k2 - k1 - 1, res{};
	while (t--)
	{
		res += maxHeap.top();
		maxHeap.pop();
	}

	return res;
}

void solve()
{
	ll nums[] = {20, 8, 22, 4, 12, 10, 14};
	ll k1 = 3, k2 = 6, n = 7;

	cout << sumBetweenTwoKth(nums, n, k1, k2) << endl;
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
