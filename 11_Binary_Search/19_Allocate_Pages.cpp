// Problem Link:
// https://www.interviewbit.com/problems/allocate-books/

// TC: O(log(sum(books)))
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

bool isPossible(vector<int> &books, int students, int currLimit)
{
	int currStudents{};
	int pages{};

	for (int i : books)
	{
		if (i > currLimit)
			return false;
		if (pages + i > currLimit)
		{
			pages = i;
			currStudents++;
		}
		else
			pages += i;
	}

	if (currStudents < students)
		return true;
	return false;
}

int booksMax(vector<int> &books, int students)
{
	int n = books.size();
	// We cannot allocate books, if number
	// of books is lesser than students
	if (students > n)
		return -1;

	// Defining the search space for binary search
	int low = 0, high = INT_MAX;
	int res{-1}, currLimit;

	while (low <= high)
	{
		currLimit = low + (high - low) / 2;
		if (isPossible(books, students, currLimit))
		{
			res = currLimit;
			high = currLimit - 1;
		}
		else
			low = currLimit + 1;
	}

	return res;
}

void solve()
{
	vector<int> books{12, 34, 67, 90};
	int students = 2;

	cout << booksMax(books, students) << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t{1};
	// cin >> t;
	while (t--)
		solve();
	return 0;
}
