#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class disjointSet
{
private:
    vector<int> parent;
    vector<int> weight;

public:
    disjointSet(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent.push_back(i);
            weight.push_back(0);
        }
    }

    int collapsingFind(int node)
    {
        if (parent[node] == node)
            return node;
        parent[node] = collapsingFind(parent[node]);
        return parent[node];
    }

    void weightedUnion(int node1, int node2)
    {
        int parent1 = collapsingFind(node1);
        int parent2 = collapsingFind(node2);

        if (parent[parent1] > parent[parent2])
            parent[parent2] = parent1;
        else if (parent[parent2] > parent[parent2])
            parent[parent1] = parent2;
        else
        {
            parent[parent2] = parent1;
            weight[parent1]++;
        }
    }
};

void solve()
{
    int n = 3;
    disjointSet ds = disjointSet(n);

    if (ds.collapsingFind(2) == ds.collapsingFind(3))
        cout << "Same Parent\n";
    else
        cout << "Different Parent\n";

    ds.weightedUnion(2, 3);

    if (ds.collapsingFind(2) == ds.collapsingFind(3))
        cout << "Same Parent\n";
    else
        cout << "Different Parent\n";

    if (ds.collapsingFind(1) == ds.collapsingFind(2))
        cout << "Same Parent\n";
    else
        cout << "Different Parent\n";

    ds.weightedUnion(1, 2);

    if (ds.collapsingFind(1) == ds.collapsingFind(2))
        cout << "Same Parent\n";
    else
        cout << "Different Parent\n";
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