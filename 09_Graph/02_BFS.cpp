#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

void bfs(vector<int> adj[], vector<bool> &visited, vector<int> &res)
{
	queue<int> nodeQu;
	nodeQu.push(0);
	visited[0] = true;

	while (nodeQu.empty() == false)
	{
		int size = nodeQu.size();
		while (size--)
		{
			int curr = nodeQu.front();
			res.push_back(curr);
			nodeQu.pop();

			for (int node : adj[curr])
			{
				if (!visited[node])
				{
					nodeQu.push(node);
					visited[node] = true;
				}
			}
		}
	}
}

vector<int> bfsOfGraph(int n, vector<int> adj[])
{
	vector<int> res{};
	vector<bool> visited(n, false);

	bfs(adj, visited, res);

	return res;
}

void solve()
{
	vector<int> adj[5];
	adj[0] = {1, 2, 3};
	adj[2] = {4};
	
	auto res = bfsOfGraph(5, adj);
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
