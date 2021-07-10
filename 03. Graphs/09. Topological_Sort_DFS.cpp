// Problem Link:
// https://practice.geeksforgeeks.org/problems/topological-sort/1#

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
    void topoHelper(int start, vector<bool> &visited, stack<int> &nodeSt);
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

void Graph::topoHelper(int start, vector<bool> &visited, stack<int> &nodeSt)
{
    visited[start] = true;

    for (int i : List[start])
    {
        if (!visited[i])
            topoHelper(i, visited, nodeSt);
    }

    nodeSt.push(start);
}

vector<int> Graph::topoSort()
{
    int n = List.size();
    vector<bool> visited(n, false);
    stack<int> nodeSt;
    vector<int> res;

    for (int i = 1; i < n; ++i)
        if (!visited[i])
            topoHelper(i, visited, nodeSt);

    while (!nodeSt.empty())
    {
        res.push_back(nodeSt.top());
        nodeSt.pop();
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

    // Displays Adjacency List
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