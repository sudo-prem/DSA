#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class StockSpanner
{
private:
	stack<pii> numSt{};
	int index{};

public:
	StockSpanner()
	{
		index = 0;
	}

	int next(int price)
	{
		while (!numSt.empty() and numSt.top().first <= price)
			numSt.pop();

		int res{index + 1};
		if (!numSt.empty())
			res = index - numSt.top().second;
		numSt.push({price, index});

		index++;
		return res;
	}
};

void solve()
{
	StockSpanner stockSpanner;

	vector<int> questions{100, 80, 60, 70, 60, 75};
	for (int que : questions)
		cout << stockSpanner.next(que) << " ";
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
