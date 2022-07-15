#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

void helper(vector<vector<int>> &adj, int n, int node, vector<bool> &visited, vector<int> &curr, vector<vector<int>> &res)
{
	int count = curr.size();
	if (count == n)
	{
		res.push_back(curr);
		return;
	}

	for (int itr : adj[node])
	{
		if (!visited[itr])
		{
			visited[itr] = true;
			curr.push_back(itr);
			helper(adj, n, itr, visited, curr, res);
			curr.pop_back();
			visited[itr] = false;
		}
	}
}

vector<vector<int>> getPaths(vector<vector<int>> &adj, int n)
{
	vector<vector<int>> res{};
	vector<int> curr{};
	vector<bool> visited(n + 1, false);

	for (int i = 1; i <= n; ++i)
	{
		visited[i] = true;
		curr.push_back(i);
		helper(adj, n, i, visited, curr, res);
		curr.pop_back();
		visited[i] = false;
	}

	return res;
}

void solve()
{
	int n = 4;
	vector<vector<int>> adj(n + 1);
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[2].push_back(4);
	adj[2].push_back(1);
	adj[3].push_back(2);
	adj[4].push_back(3);
	adj[4].push_back(2);

	auto res = getPaths(adj, n);
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
