#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

int getDistance(vector<int> &point)
{
	return (point[0] * point[0]) + (point[1] * point[1]);
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
	int n = points.size();
	priority_queue<pii> maxHeap{};

	for (int i = 0; i < k; ++i)
		maxHeap.push({getDistance(points[i]), i});

	for (int i = k; i < n; ++i)
	{
		pii curr = {getDistance(points[i]), i};
		if (maxHeap.top() > curr)
		{
			maxHeap.pop();
			maxHeap.push(curr);
		}
	}

	vector<vector<int>> res{};
	while (!maxHeap.empty())
	{
		res.push_back(points[maxHeap.top().second]);
		maxHeap.pop();
	}

	return res;
}

void solve()
{
	vector<vector<int>> points{{3, 3}, {5, -1}, {-2, 4}};
	int k = 2;

	auto res = kClosest(points, k);
	for (auto itr : res)
	{
		for (int num : itr)
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
