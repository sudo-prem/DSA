// Problem Link:
// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define deb(x) cout << #x << ": " << x << "\n"

void helper(int a[], int n, int index, unordered_map<int, string> &hash, string &curr, vector<string> &res)
{
	if (index == n)
	{
		res.push_back(curr);
		return;
	}

	int currSize = hash[a[index]].size();
	for (int i = 0; i < currSize; ++i)
	{
		curr.push_back(hash[a[index]][i]);
		helper(a, n, index + 1, hash, curr, res);
		curr.pop_back();
	}
}

vector<string> possibleWords(int a[], int n)
{
	vector<string> res{};
	string curr{};
	unordered_map<int, string> hash{};
	hash[2] = {"abc"};
	hash[3] = {"def"};
	hash[4] = {"ghi"};
	hash[5] = {"jkl"};
	hash[6] = {"mno"};
	hash[7] = {"pqrs"};
	hash[8] = {"tuv"};
	hash[9] = {"wxyz"};

	helper(a, n, 0, hash, curr, res);

	return res;
}

void solve()
{
	int n = 3;
	int a[] {2, 3, 4};

	auto res = possibleWords(a, n);
	for (auto s : res)
		cout << s << " ";
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
