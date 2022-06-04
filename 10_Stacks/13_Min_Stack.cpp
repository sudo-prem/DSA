#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

class MinStack
{
private:
	ll minVal;
	stack<ll> numSt;

public:
	MinStack()
	{
		minVal = 0;
	}

	void push(ll val)
	{
		if (numSt.empty())
		{
			numSt.push(val);
			minVal = val;
			return;
		}

		ll curr = val;
		if (val < minVal)
		{
			curr = (2 * val) - minVal;
			minVal = val;
		}

		numSt.push(curr);
	}

	void pop()
	{
		if (numSt.top() < minVal)
			minVal = (2 * minVal) - numSt.top();
		numSt.pop();
	}

	int top()
	{
		if (numSt.top() < minVal)
			return minVal;
		return numSt.top();
	}

	int getMin()
	{
		return minVal;
	}
};

void solve()
{
	MinStack ms;
	vector<int> nums{-2, 0, -3};

	for (int i : nums)
		ms.push(i);

	cout << ms.getMin() << endl;
	ms.pop();
	cout << ms.top() << endl;
	cout << ms.getMin() << endl;
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
