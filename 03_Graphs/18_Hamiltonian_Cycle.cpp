#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

void helper(vector<vector<int>> &adj, int n, int start, int node, vector<bool> &visited, vector<int> &curr, vector<vector<int>> &res)
{
	int count = curr.size();
	if (count == n)
	{
		for (int itr : adj[node])
			if (itr == start)
			{
				curr.push_back(start);
				res.push_back(curr);
				curr.pop_back();
			}

		return;
	}

	for (int itr : adj[node])
	{
		if (!visited[itr])
		{
			visited[itr] = true;
			curr.push_back(itr);
			helper(adj, n, start, itr, visited, curr, res);
			curr.pop_back();
			visited[itr] = false;
		}
	}
}

vector<vector<int>> getCycles(vector<vector<int>> &adj, int n)
{
	vector<vector<int>> res{};
	vector<int> curr{};
	vector<bool> visited(n + 1, false);

	visited[1] = true;
	curr.push_back(1);
	helper(adj, n, 1, 1, visited, curr, res);
	curr.pop_back();
	visited[1] = false;

	return res;
}

void solve()
{
	int n = 6;
	vector<vector<int>> adj(n + 1);
	adj[1] = {2, 3, 6};
	adj[2] = {1, 3, 5, 6};
	adj[3] = {1, 2, 4};
	adj[4] = {3, 5};
	adj[5] = {2, 4, 6};
	adj[6] = {1, 2, 5};

	auto res = getCycles(adj, n);
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
