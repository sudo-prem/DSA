#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

bool isPossible(bool graph[101][101], int n, int node, vector<int> &colors, int color)
{
	for (int i = 0; i < n; ++i)
		if (graph[node][i] and colors[i] == color)
			return false;

	return true;
}

bool helper(bool graph[101][101], int m, int n, int node, vector<int> &colors)
{
	if (node == n)
		return true;

	for (int i = 0; i < m; ++i)
	{
		if (isPossible(graph, n, node, colors, i))
		{
			colors[node] = i;
			if (helper(graph, m, n, node + 1, colors))
				return true;
			colors[node] = -1;
		}
	}

	return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
	vector<int> colors(n, -1);

	return helper(graph, m, n, 0, colors);
}

void solve()
{
	bool graph[101][101];

	vector<vector<int>> edges{{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};
	for (auto edge : edges)
		graph[edge[0]][edge[1]] = graph[edge[0]][edge[1]] = true;

	int m = 3;
	int n = 4;

	cout << graphColoring(graph, m, n) << endl;
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
