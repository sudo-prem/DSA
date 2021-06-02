#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> Matrix;

public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    void Display();
    void displayDist(vector<int> res, int source);
    int minDist(vector<int> vec, vector<bool> visited);
    vector<int> Dijkstra(int source);
};

Graph::Graph(int n)
{
    Matrix.resize(n, vector<int>(n, 0));
}

// assuming that the graph is undirected
void Graph::addEdge(int u, int v, int w)
{
    Matrix[u][v] = Matrix[v][u] = w;
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

int Graph::minDist(vector<int> vec, vector<bool> visited)
{
    int minVal{INT_MAX}, minIndex{};
    for (int i = 0; i < vec.size(); ++i)
        if (!visited[i] and vec[i] < minVal)
        {
            minVal = vec[i];
            minIndex = i;
        }
    return minIndex;
}

vector<int> Graph::Dijkstra(int source)
{
    int n = Matrix.size();
    vector<int> res(n, INT_MAX);
    vector<bool> visited(n, false);
    int visitedCount{};

    res[source] = 0;

    while (visitedCount != n)
    {
        int curr = minDist(res, visited);
        for (int i = 0; i < n; ++i)
            // Here we neglect the case of negative edges
            // Dijkstra may or may not work for negative edges
            if (Matrix[curr][i] > 0)
            {
                int temp = res[curr] + Matrix[curr][i];
                if (res[i] > temp)
                    res[i] = temp;
            }
        visited[curr] = true;
        visitedCount++;
    }

    return res;
}

int main()
{
    int n = 9;
    vector<int> U{1, 2, 3, 4, 5, 5, 5, 6, 7, 7, 7, 8, 8, 8};
    vector<int> V{0, 1, 2, 3, 2, 3, 4, 5, 0, 1, 6, 2, 6, 7};
    vector<int> W{4, 8, 7, 9, 4, 14, 10, 2, 8, 11, 1, 2, 6, 7};

    Graph G(n);

    for (int i = 0; i < U.size(); ++i)
        G.addEdge(U[i], V[i], W[i]);

    int source = 0;
    vector<int> res = G.Dijkstra(source);
    G.displayDist(res, source);

    return 0;
}