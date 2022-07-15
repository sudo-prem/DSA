#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

vector<int> topoSort(int n, vector<int> adj[])
{
	vector<int> res{};
	vector<int> inDegree(n, 0);

	for (int i = 0; i < n; ++i)
		for (int node : adj[i])
			inDegree[node]++;

	queue<int> nodeQu;
	for (int i = 0; i < n; ++i)
		if (inDegree[i] == 0)
			nodeQu.push(i);

	while (!nodeQu.empty())
	{
		int curr = nodeQu.front();
		res.push_back(curr);
		nodeQu.pop();

		for (int node : adj[curr])
		{
			inDegree[node]--;
			if (inDegree[node] == 0)
				nodeQu.push(node);
		}
	}

	return res;
}

void solve()
{
	int n = 4;
	vector<int> adj[n];

	adj[1].push_back(0);
	adj[2].push_back(0);
	adj[3].push_back(0);

	auto res = topoSort(n, adj);
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
