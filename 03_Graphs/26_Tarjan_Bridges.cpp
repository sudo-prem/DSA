#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

#define vi vector<int>
#define vb vector<bool>

void dfs(vector<int> adj[], vb &visited, vi &disTime, vi &lowTime, int &timer, vector<vi> &res, int parent, int node)
{
	visited[node] = true;
	lowTime[node] = disTime[node] = timer++;

	for (int neighbor : adj[node])
	{
		if (neighbor == parent)
			continue;

		if (!visited[neighbor])
		{
			dfs(adj, visited, disTime, lowTime, timer, res, node, neighbor);
			lowTime[node] = min(lowTime[node], lowTime[neighbor]);

			if (lowTime[neighbor] > disTime[node])
				res.push_back({node, neighbor});
		}
		else
			lowTime[node] = min(lowTime[node], disTime[neighbor]);
	}
}

vector<vi> getBridges(int n, vector<int> adj[])
{
	vb visited(n, false);
	vi disTime(n);
	vi lowTime(n);
	int timer{};
	vector<vi> res{};

	for (int i = 0; i < n; ++i)
		if (!visited[i])
			dfs(adj, visited, disTime, lowTime, timer, res, -1, i);

	return res;
}

void solve()
{
	int n = 5;
	vector<int> adj[n];
	adj[0] = {1};
	adj[1] = {0, 4};
	adj[2] = {3, 4};
	adj[3] = {2, 4};
	adj[4] = {1, 2, 3};

	auto res = getBridges(n, adj);
	for (auto vec : res)
	{
		for (int num : vec)
			cout << num << " ";
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
