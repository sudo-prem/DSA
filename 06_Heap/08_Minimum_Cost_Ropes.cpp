#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class Comparator
{
public:
	bool operator()(const ll &a, const ll &b)
	{
		return a > b;
	}
};

ll minCost(ll arr[], ll n)
{
	priority_queue<ll, vector<ll>, Comparator> minHeap{};
	ll res{};

	for (ll i = 0; i < n; ++i)
		minHeap.push(arr[i]);

	while (minHeap.size() >= 2)
	{
		ll first = minHeap.top();
		minHeap.pop();
		ll second = minHeap.top();
		minHeap.pop();
		minHeap.push(first + second);

		res += (first + second);
	}

	return res;
}

void solve()
{
	ll arr[] = {4, 3, 2, 6};
	int n = 4;

	cout << minCost(arr, n) << endl;
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
