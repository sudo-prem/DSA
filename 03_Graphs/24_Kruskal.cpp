#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class DisjointSet
{
private:
	vector<int> parent;
	vector<int> weight;

public:
	DisjointSet(int n)
	{
		parent.resize(n);
		weight.resize(n);

		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int collapsingFind(int node)
	{
		if (parent[node] == node)
			return node;

		parent[node] = collapsingFind(parent[node]);
		return parent[node];
	}

	void weightedUnion(int node1, int node2)
	{
		int parent1 = collapsingFind(node1);
		int parent2 = collapsingFind(node2);

		if (weight[parent1] > weight[parent2])
			parent[parent2] = parent1;
		else if (weight[parent2] > weight[parent1])
			parent[parent1] = parent2;
		else
		{
			parent[parent2] = parent1;
			weight[parent1]++;
		}
	}
};

vector<vector<vector<int>>> kruskal(vector<vector<vector<int>>> &adj)
{
	int n = adj.size();
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> minHeap;
	vector<vector<vector<int>>> res(n);

	for (int i = 0; i < n; ++i)
		for (auto &itr : adj[i])
			minHeap.push({itr[1], {i, itr[0]}});

	DisjointSet djs(n);

	while (!minHeap.empty())
	{
		int edgeWeight = minHeap.top().first;
		int node1 = minHeap.top().second.first;
		int node2 = minHeap.top().second.second;
		minHeap.pop();

		if (djs.collapsingFind(node1) != djs.collapsingFind(node2))
		{
			djs.weightedUnion(node1, node2);
			res[node1].push_back({node2, edgeWeight});
			res[node2].push_back({node1, edgeWeight});
		}
	}

	return res;
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

	vector<vector<vector<int>>> mst = kruskal(adj);

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
