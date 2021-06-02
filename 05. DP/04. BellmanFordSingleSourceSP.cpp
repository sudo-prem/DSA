#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> Matrix;

public:
    void addEdge(int u, int v, int w);
    void Display();
    void displayDist(vector<int> res, int source);
    vector<int> bellmanFord(int source, int vertices, int edges);
};

// Note: Matrix in this algo is a vector of (vector of (vertex, vertex, weight))
void Graph::addEdge(int u, int v, int w)
{
    vector<int> temp{u, v, w};
    Matrix.push_back(temp);
}

void Graph::Display()
{
    for (auto i : Matrix)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

void Graph::displayDist(vector<int> res, int source)
{
    for (int i = 0; i < res.size(); ++i)
        cout << "SP from " << source << " to " << i << " is " << res[i] << endl;
}

vector<int> Graph::bellmanFord(int source, int vertices, int edges)
{
    vector<int> res(vertices, INT_MAX);

    res[source] = 0;

    for (int i = 0; i < vertices - 1; i++)
        for (int j = 0; j < edges; j++)
            if (res[Matrix[j][0]] != INT_MAX && res[Matrix[j][0]] + Matrix[j][2] < res[Matrix[j][1]])
                res[Matrix[j][1]] = res[Matrix[j][0]] + Matrix[j][2];

    return res;
}

int main()
{
    int vertices = 7, edges = 10;
    vector<int> U{0, 0, 0, 1, 2, 2, 3, 3, 4, 5};
    vector<int> V{1, 2, 3, 4, 1, 4, 5, 2, 6, 6};
    vector<int> W{6, 5, 5, -1, 2, 1, -1, -2, 3, 3};

    Graph G;

    for (int i = 0; i < U.size(); ++i)
        G.addEdge(U[i], V[i], W[i]);

    int source = 0;
    vector<int> res = G.bellmanFord(source, vertices, edges);
    G.displayDist(res, source);

    return 0;
}