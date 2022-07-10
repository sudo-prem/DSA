#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

vector<int> shortestDistance(int n, vector<vector<int>> adj[], int src)
{
	vector<int> distance(n, INT_MAX);
	distance[src] = 0;

	queue<pair<int, int>> nodeQu;
	nodeQu.push({src, 0});

	while (!nodeQu.empty())
	{
		int currNode = nodeQu.front().first;
		int currDistance = nodeQu.front().second;
		nodeQu.pop();

		for (auto node : adj[currNode])
		{
			int neighbor = node[0];
			int edgeDistance = node[1];
			if (currDistance + edgeDistance < distance[neighbor])
			{
				distance[neighbor] = currDistance + edgeDistance;
				nodeQu.push({neighbor, distance[neighbor]});
			}
		}
	}

	return distance;
}

void solve()
{
	int n = 3;
	vector<vector<int>> adj[] {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
	int src = 2;

	auto res = shortestDistance(n, adj, src);

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
