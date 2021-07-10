// Problem Link:
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1

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
    bool isBipartiteHelper(int start, vector<int> &visisted);
    bool isBipartite();
};

Graph::Graph(int n)
{
    List.resize(n + 1);
}

void Graph::addEdge(int u, int v)
{
    List[u].push_back(v);
    List[v].push_back(u);
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

bool Graph::isBipartiteHelper(int start, vector<int> &colors)
{
    queue<int> nodeQu;
    nodeQu.push(start);
    colors[start] = 0;

    while (!nodeQu.empty())
    {
        int curr = nodeQu.front();
        int color = !colors[curr];
        nodeQu.pop();

        for (int i : List[curr])
        {
            if (colors[i] == -1)
            {
                colors[i] = color;
                nodeQu.push(i);
            }
            else if (colors[i] == !color)
                return false;
        }
    }

    return true;
}

bool Graph::isBipartite()
{
    int n = List.size();
    vector<int> colors(n, -1);

    for (int i = 1; i < n; ++i)
    {
        if (colors[i] == -1)
            if (!isBipartiteHelper(i, colors))
                return false;
    }

    return true;
}

void solve()
{
    // 1 Based Indexing
    int n = 5;
    Graph g(n);
    vector<int> U{2, 2, 2, 3, 4};
    vector<int> V{1, 3, 5, 4, 5};

    // int n = 4;
    // Graph g(n);
    // vector<int> U{2, 3};
    // vector<int> V{3, 4};

    // int n = 4;
    // Graph g(n);
    // vector<int> U{1, 2, 3, 1};
    // vector<int> V{2, 3, 4, 3};

    for (int i = 0; i < U.size(); ++i)
        g.addEdge(U[i], V[i]);

    // Displays Adjacency Matrix
    cout << "List: \n";
    g.displayList();

    g.isBipartite() ? cout << "True\n" : cout << "False\n";
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