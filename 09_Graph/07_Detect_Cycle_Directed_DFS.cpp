#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

bool dfs(vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis, int start)
{
	for (int node : adj[start])
	{
		if (dfsVis[node])
			return true;
		if (!vis[node])
		{
			vis[node] = dfsVis[node] = true;
			if (dfs(adj, vis, dfsVis, node))
				return true;
			dfsVis[node] = false;
		}
	}

	return false;
}

bool isCyclic(int n, vector<int> adj[])
{
	vector<bool> vis(n, false), dfsVis(n, false);

	for (int i = 0; i < n; ++i)
		if (vis[i] == false)
		{
			vis[i] = true, dfsVis[i] = true;
			if (dfs(adj, vis, dfsVis, i))
				return true;
			dfsVis[i] = false;
		}

	return false;
}

void solve()
{
	int n = 4;
	vector<int> adj[n];
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(1);

	cout << isCyclic(n, adj) << endl;
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
