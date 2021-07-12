#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<pair<int, int>>> List;

public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    void displayDist(vector<int> res, int source);
    vector<int> bellmanFord(int source);
};

Graph::Graph(int n)
{
    List.resize(n);
}

void Graph::addEdge(int u, int v, int w)
{
    List[u].push_back({v, w});
}

void Graph::displayDist(vector<int> res, int source)
{
    for (int i = 0; i < res.size(); ++i)
        cout << "SP from " << source << " to " << i << " is " << res[i] << endl;
}

vector<int> Graph::bellmanFord(int source)
{
    // Vertices
    int n = List.size();

    // Creates a vector of edges with its weight
    vector<pair<int, pair<int, int>>> edgeList;
    for (int i = 0; i < n; ++i)
        for (auto j : List[i])
            edgeList.push_back({j.second, {i, j.first}});

    // Edges
    int m = edgeList.size();

    vector<int> distance(n, INT_MAX);
    distance[source] = 0;

    for (int i = 0; i < n - 1; ++i)
        for (auto edge : edgeList)
        {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;
            if (distance[u] != INT_MAX and distance[u] + w < distance[v])
                distance[v] = distance[u] + w;
        }

    return distance;
}

int main()
{
    int n = 7;
    vector<int> U{0, 0, 0, 1, 2, 2, 3, 3, 4, 5};
    vector<int> V{1, 2, 3, 4, 1, 4, 5, 2, 6, 6};
    vector<int> W{6, 5, 5, -1, 2, 1, -1, -2, 3, 3};

    Graph G(n);

    for (int i = 0; i < U.size(); ++i)
        G.addEdge(U[i], V[i], W[i]);

    int source = 0;
    vector<int> res = G.bellmanFord(source);
    G.displayDist(res, source);

    return 0;
}