#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

bool bfs(vector<vector<int>> &graph, vector<int> &visited, int start)
{
	queue<int> nodeQu;
	nodeQu.push(start);
	int color = 1;

	while (nodeQu.empty() == false)
	{
		int size = nodeQu.size();
		while (size--)
		{
			int curr = nodeQu.front();
			nodeQu.pop();

			for (int node : graph[curr])
			{
				if (visited[node] == -1)
				{
					visited[node] = color;
					nodeQu.push(node);
				}
				else if (visited[node] != color)
					return false;
			}
		}
		color = (!color);
	}

	return true;
}

bool isBipartite(vector<vector<int>>& graph)
{
	int n = graph.size();
	vector<int> visited(n, -1);

	for (int i = 0; i < n; ++i)
		if (visited[i] == -1)
		{
			visited[i] = 0;
			if (!bfs(graph, visited, i))
				return false;
		}

	return true;
}

void solve()
{
	vector<vector<int>> graph{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

	cout << isBipartite(graph) << endl;
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
