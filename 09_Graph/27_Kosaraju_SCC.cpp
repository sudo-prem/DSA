#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

void topoHelper(vector<vector<int>> &adj, int node, vector<bool> &visited, stack<int> &nodeSt)
{
	visited[node] = true;

	for (auto i : adj[node])
		if (!visited[i])
			topoHelper(adj, i, visited, nodeSt);

	nodeSt.push(node);
}

stack<int> topoSort(vector<vector<int>> &adj)
{
	int n = adj.size();
	stack<int> nodeSt{};
	vector<bool> visited(n, false);

	for (int i = 1; i < n; ++i)
		if (!visited[i])
			topoHelper(adj, i, visited, nodeSt);

	return nodeSt;
}

void dfs(vector<vector<int>> &adj, int node, vector<bool> &visited, vector<int> &currComponent)
{
	visited[node] = true;
	currComponent.push_back(node);

	for (int i : adj[node])
		if (!visited[i])
			dfs(adj, i, visited, currComponent);
}

vector<vector<int>> kosaraju(vector<vector<int>>&adj)
{
	int n = adj.size();
	vector<vector<int>> SCC;

	// Get the topological order of graph
	stack<int> nodeSt = topoSort(adj);

	// Create Transpose of the Graph
	vector<vector<int>> transpose(n);
	for (int i = 0; i < n; ++i)
		for (int j : adj[i])
			transpose[j].push_back(i);

	// DFS the transpose graph
	vector<bool> visited(n, false);
	while (!nodeSt.empty())
	{
		int curr = nodeSt.top();
		nodeSt.pop();

		if (!visited[curr])
		{
			vector<int> currComponent;
			dfs(transpose, curr, visited, currComponent);
			SCC.push_back(currComponent);
		}
	}

	return SCC;
}


void solve()
{
	int n = 5;
	vector<vector<int>> adj(n);
	adj[0] = {1};
	adj[1] = {2, 3};
	adj[2] = {0};
	adj[3] = {4};

	vector<vector<int>> SCC = kosaraju(adj);
	for (int i = 0; i < SCC.size(); ++i)
	{
		for (int j : SCC[i])
			cout << j << " ";
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
