#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

#define vi vector<int>
#define vb vector<bool>

void dfsAP(vi adj[], vb &visited, vb &isAP, vi &disTime, vi &lowTime, int &timer, int parent, int node)
{
	visited[node] = true;
	disTime[node] = lowTime[node] = timer++;
	int childCount{};

	for (int neighbor : adj[node])
	{
		if (neighbor == parent)
			continue;

		if (!visited[neighbor])
		{
			dfsAP(adj, visited, isAP, disTime, lowTime, timer, node, neighbor);
			lowTime[node] = min(lowTime[node], lowTime[neighbor]);

			if (lowTime[neighbor] >= disTime[node] and parent != -1)
				isAP[node] = true;

			childCount++;
		}
		else
			lowTime[node] = min(lowTime[node], disTime[neighbor]);
	}

	if (parent == -1 and childCount > 1)
		isAP[node] = true;
}

vector<int> articulationPoints(int n, vector<int>adj[])
{
	vb visited(n, false);
	vb isAP(n, false);
	vi disTime(n, -1);     // Discovery Time
	vi lowTime(n, -1);     // Lowest Time that a node's neighbor has
	int timer{};

	for (int i = 0; i < n; ++i)     // For multiple components
		if (!visited[i])
			dfsAP(adj, visited, isAP, disTime, lowTime, timer, -1, i);

	vi res{};
	for (int i = 0; i < n; ++i)
		if (isAP[i])
			res.push_back(i);

	if (res.size())
		return res;
	return {-1};
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

	auto res = articulationPoints(n, adj);
	for (int node : res)
		cout << node << " ";
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
