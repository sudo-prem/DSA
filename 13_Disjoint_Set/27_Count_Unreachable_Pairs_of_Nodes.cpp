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

long long countPairs(int n, vector<vector<int>>& edges)
{
	DisjointSet djs(n);
	for (auto edge : edges)
		djs.weightedUnion(edge[0], edge[1]);

	unordered_map<int, int> count{};
	for (int i = 0; i < n; ++i)
		count[djs.collapsingFind(i)]++;

	long long res{}, sum{};
	for (auto itr : count)
	{
		res += (itr.second * sum);
		sum += itr.second;
	}

	return res;
}

void solve()
{
	int n = 7;
	vector<vector<int>> edges{{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};

	cout << countPairs(n, edges) << endl;
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
