#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

void dfs(vector<int> adj[], vector<bool> &visited, vector<int> &res, int start)
{
	for (int node : adj[start])
	{
		if (!visited[node])
		{
			visited[node] = true;
			res.push_back(node);
			dfs(adj, visited, res, node);
		}
	}
}

vector<int> dfsOfGraph(int n, vector<int> adj[])
{
	vector<int> res{};
	vector<bool> visited(n, false);

	visited[0] = true;
	res.push_back(0);
	dfs(adj, visited, res, 0);
	return res;
}

void solve()
{
	int n = 4;
	vector<int> adj[n];

	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[0].push_back(3);
	adj[3].push_back(0);
	adj[1].push_back(2);
	adj[2].push_back(1);

	auto res = dfsOfGraph(n, adj);
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
