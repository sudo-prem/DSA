#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

vector<int> shortestDistance(int n, vector<vector<int>> adj, int src)
{
	vector<int> distance(n, INT_MAX);
	queue<int> nodeQu;

	distance[src] = 0;
	nodeQu.push(src);

	while (!nodeQu.empty())
	{
		int curr = nodeQu.front();
		nodeQu.pop();

		for (int i : adj[curr])
		{
			if (distance[curr] + 1 < distance[i])
			{
				distance[i] = distance[curr] + 1;
				nodeQu.push(i);
			}
		}
	}

	return distance;
}

void solve()
{
	int n = 3;
	vector<vector<int>> adj{{1, 2}, {2, 0}, {1, 0}};

	auto res = shortestDistance(n, adj, 0);

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
