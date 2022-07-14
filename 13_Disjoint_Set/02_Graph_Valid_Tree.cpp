#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class DisjointSet
{
public:
	vector<int> parent;
	vector<int> weight;
	int componentsCount;

	DisjointSet(int n)
	{
		componentsCount = n;
		parent.resize(n);
		weight.resize(n, 1);

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

	bool weightedUnion(int node1, int node2)
	{
		int parent1 = collapsingFind(node1);
		int parent2 = collapsingFind(node2);

		if (parent1 == parent2)
			return false;

		if (weight[parent1] > weight[parent2])
			parent[parent2] = parent1, weight[parent1]++;
		else
			parent[parent1] = parent2, weight[parent2]++;

		componentsCount--;
		return true;
	}
};

bool validTree(int n, vector<vector<int>> &edges)
{
	if (n == 1)
		return true;
	if (!edges.size())
		return false;

	DisjointSet djs(n);

	for (auto edge : edges)
		if (!(djs.weightedUnion(edge[0], edge[1])))
			return false;

	return djs.componentsCount == 1;
}

void solve()
{
	int n = 10;
	vector<vector<int>> edges{{0, 1}, {5, 6}, {6, 7}, {9, 0}, {3, 7}, {4, 8}, {1, 8}, {5, 2}, {5, 3}};

	cout << validTree(n, edges) << endl;
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
