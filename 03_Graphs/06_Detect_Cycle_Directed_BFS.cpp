// Problem Link:
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

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
    bool isCyclic();
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

bool Graph::isCyclic()
{
    int n = List.size();
    vector<int> inDegree(n, 0);
    vector<bool> visited(n, false);
    queue<int> nodeQu;

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

        for (int i : List[curr])
        {
            inDegree[i]--;
            if (inDegree[i] == 0)
                nodeQu.push(i);
        }
    }

    for (int i : inDegree)
        if (i != 0)
            return true;
    return false;
}

void solve()
{
    // 1 Based Indexing
    // int n = 5;
    // Graph g(n);
    // vector<int> U{2, 2, 2, 3, 4};
    // vector<int> V{1, 3, 5, 4, 5};

    int n = 4;
    Graph g(n);
    vector<int> U{2, 3};
    vector<int> V{3, 4};

    // int n = 4;
    // Graph g(n);
    // vector<int> U{1, 2, 3, 1};
    // vector<int> V{2, 3, 4, 3};

    for (int i = 0; i < U.size(); ++i)
        g.addEdge(U[i], V[i]);

    // Displays Adjacency List
    cout << "List: \n";
    g.displayList();

    g.isCyclic() ? cout << "True\n" : cout << "False\n";
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