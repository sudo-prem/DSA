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
			parent[parent2] = parent1;  // weight[parent1] += weight[parent2];
		else if (weight[parent2] > weight[parent1])
			parent[parent1] = parent2;  // weight[parent2] += weight[parent1];
		else
		{
			parent[parent2] = parent1;  // weight[parent1] += weight[parent2];
			weight[parent1]++;
		}
	}
};

void solve()
{
	int n = 3;
	DisjointSet djs(n);

	if (djs.collapsingFind(2) == djs.collapsingFind(3))
		cout << "Same Parent\n";
	else
		cout << "Different Parent\n";

	djs.weightedUnion(2, 3);

	if (djs.collapsingFind(2) == djs.collapsingFind(3))
		cout << "Same Parent\n";
	else
		cout << "Different Parent\n";

	if (djs.collapsingFind(1) == djs.collapsingFind(2))
		cout << "Same Parent\n";
	else
		cout << "Different Parent\n";

	djs.weightedUnion(1, 2);

	if (djs.collapsingFind(1) == djs.collapsingFind(2))
		cout << "Same Parent\n";
	else
		cout << "Different Parent\n";
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
