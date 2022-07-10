#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

void dfs(vector<int> adj[], vector<bool> &visited, stack<int> &nodeSt, int start)
{
	for (int node : adj[start])
	{
		if (!visited[node])
		{
			visited[node] = true;
			dfs(adj, visited, nodeSt, node);
		}
	}

	nodeSt.push(start);
}

vector<int> topoSort(int n, vector<int> adj[])
{
	vector<bool> visited(n, false);
	stack<int> nodeSt{};

	for (int i = 0; i < n; ++i)
		if (!visited[i])
		{
			visited[i] = true;
			dfs(adj, visited, nodeSt, i);
		}

	vector<int> res{};
	while (!nodeSt.empty())
	{
		res.push_back(nodeSt.top());
		nodeSt.pop();
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
	for(int num: res)
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
