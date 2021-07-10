// Problem Link:
// https://practice.geeksforgeeks.org/problems/topological-sort/1#

// Kahn's Algorithm
// TC: O(n)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << ": " << x << "\n"

class Graph
{
private:
    vector<vector<int>> List;

public:
    Graph(int n);
    void addEdge(int u, int v);
    void displayList();
    vector<int> topoSort();
};

Graph::Graph(int n)
{
    List.resize(n + 1);
}

void Graph::addEdge(int u, int v)
{
    List[u].push_back(v);
}

void Graph::displayList()
{
    int size = List.size();
    int count{};
    for (auto i : List)
    {
        cout << count++ << ": ";
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}

vector<int> Graph::topoSort()
{
    int n = List.size();
    vector<int> visisted(n, false);
    vector<int> inDegree(n, 0);
    queue<int> nodeQu;
    vector<int> res;

    for (int i = 1; i < n; ++i)
        for (int j : List[i])
            inDegree[j]++;

    for (int i = 1; i < n; ++i)
        if (inDegree[i] == 0)
            nodeQu.push(i);

    while (!nodeQu.empty())
    {
        int curr = nodeQu.front();
        nodeQu.pop();
        res.push_back(curr);

        for (int i : List[curr])
        {
            inDegree[i]--;
            if (inDegree[i] == 0)
                nodeQu.push(i);
        }
    }

    return res;
}

void solve()
{
    // 1 Based Indexing
    int n = 4;
    Graph g(n);
    vector<int> U{2, 4, 3};
    vector<int> V{1, 1, 1};

    for (int i = 0; i < U.size(); ++i)
        g.addEdge(U[i], V[i]);

    // Displays Adjacency Matrix
    cout << "List: \n";
    g.displayList();

    vector<int> res = g.topoSort();

    for (int i : res)
        cout << i << " ";
    cout << endl;
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