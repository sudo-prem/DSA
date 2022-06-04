#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

long long toh(int n, int from, int to, int aux)
{
	if (n == 0)
		return 0;

	long long res = 1;
	res += toh(n - 1, from, aux, to);
	cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
	res += toh(n - 1, aux, to, from);

	return res;
}

void solve()
{
	cout << toh(3, 1, 3, 2) << endl;
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
