#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

vector<int> nextGreaterElements(vector<int>& nums)
{
	int n = nums.size();
	stack<int> numSt{};
	vector<int> res(n);

	for (int i = (2 * n) - 1; i >= 0; --i)
	{
		while (!numSt.empty() and numSt.top() <= nums[i % n])
			numSt.pop();

		if (numSt.empty())
			res[i % n] = -1;
		else
			res[i % n] = numSt.top();
		numSt.push(nums[i % n]);
	}

	return res;
}

void solve()
{
	vector<int> nums{1, 2, 1};

	auto res = nextGreaterElements(nums);
	for (auto itr : res)
		cout << itr << " ";
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
