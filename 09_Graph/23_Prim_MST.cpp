#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

vector<vector<vector<int>>> getMST(vector<int> &parent, vector<int> &key)
{
	int n = parent.size();
	vector<vector<vector<int>>> adj(n);

	for (int i = 1; i < n; ++i)
		adj[i].push_back({parent[i], key[i]}), adj[parent[i]].push_back({i, key[i]});

	return adj;
}

vector<vector<vector<int>>> prims(vector<vector<vector<int>>> &adj)
{
	int n = adj.size();
	vector<bool> visited(n, false);
	vector<int> parent(n);
	vector<int> key(n, INT_MAX);
	priority_queue<pii, vector<pii>, greater<pii>> minHeap;

	parent[0] = -1;
	key[0] = 0;
	minHeap.push({0, 0});

	while (!minHeap.empty())
	{
		int minNode = minHeap.top().second;
		minHeap.pop();

		visited[minNode] = true;

		for (auto edges : adj[minNode])
		{
			int currNode = edges[0];
			int currWeight = edges[1];
			if (visited[currNode] == false and currWeight < key[currNode])
			{
				parent[currNode] = minNode;
				key[currNode] = currWeight;
				minHeap.push({currWeight, currNode});
			}
		}
	}

	return getMST(parent, key);
}

void solve()
{
	int n = 5;
	vector<vector<vector<int>>> adj(n);
	adj[0] = {{1, 2}, {3, 6}};
	adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
	adj[2] = {{1, 3}, {4, 7}};
	adj[3] = {{0, 6}, {1, 8}};
	adj[4] = {{1, 5}, {2, 7}};

	vector<vector<vector<int>>> mst = prims(adj);

	// Skip (i = 0) - root of MST
	for (int i = 1; i < n; ++i)
	{
		cout << i << " - ";
		int m = mst[i].size();
		for (int j = 0; j < m; ++j)
			cout << "[" << mst[i][j].front() << " " << mst[i][j].back() << "] ";
		cout << endl;
	}
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
