#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

bool isCyclic(int n, vector<int> adj[])
{
	queue<int> nodeQu;
	vector<int> inDegree(n, 0);

	for (int i = 0; i < n; ++i)
		for (int &node : adj[i])
			inDegree[node]++;

	for (int i = 0; i < n; ++i)
		if (inDegree[i] == 0)
			nodeQu.push(i);

	int count{};
	while (!nodeQu.empty())
	{
		count++;
		int curr = nodeQu.front();
		nodeQu.pop();

		for (int node : adj[curr])
		{
			inDegree[node]--;
			if (inDegree[node] == 0)
				nodeQu.push(node);
		}
	}

	return count != n;
}

void solve()
{
	int n = 4;
	vector<int> adj[n];
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(1);

	cout << isCyclic(n, adj) << endl;
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
