#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

bool dfs(vector<int> adj[], vector<bool> &visited, int start, int prev)
{
	for (int node : adj[start])
	{
		if (!visited[node])
		{
			visited[node] = true;
			if (dfs(adj, visited, node, start))
				return true;
		}
		else if (node != prev)
			return true;
	}

	return false;
}

bool isCycle(int n, vector<int> adj[])
{
	vector<bool> visited(n, false);

	for (int i = 0; i < n; ++i)
		if (!visited[i])
		{
			visited[i] = true;
			if (dfs(adj, visited, i, -1))
				return true;
		}

	return false;
}

void solve()
{
	int n = 4;
	vector<int> adj[n];
	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(2);
	adj[3].push_back(1);
	adj[1].push_back(3);

	cout << isCycle(n, adj) << endl;
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
