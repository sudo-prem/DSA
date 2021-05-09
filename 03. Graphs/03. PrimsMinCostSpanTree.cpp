#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    // adjacency matrix representation
    vector<vector<int>> Matrix;

public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    void displayMatrix();
    vector<pair<int, int>> Prims();
    void Cost(vector<pair<int, int>>);
};

Graph::Graph(int n)
{
    Matrix.resize(n, vector<int>(n, INT_MAX));
}

void Graph::addEdge(int u, int v, int w)
{
    Matrix[u][v] = Matrix[v][u] = w;
}

void Graph::displayMatrix()
{
    int s = Matrix.size();
    for (int i = 0; i < s; ++i)
    {
        for (int j = 0; j < s; ++j)
        {
            if (Matrix[i][j] != INT_MAX)
                cout << Matrix[i][j] << " ";
            else
                cout << "-- ";
        }
        cout << '\n';
    }
    cout << '\n';
}

vector<pair<int, int>> Graph::Prims()
{
    int size = Matrix.size();
    vector<pair<int, int>> res;
    vector<int> track(size + 1, INT_MAX);
    // Find the Minimum value from lower or upper triangle
    int minValue{INT_MAX};
    pair<int, int> minIndex;
    for (int i = 1; i < size; ++i)
        for (int j = 1; j <= i; ++j)
            if (Matrix[i][j] < minValue)
            {
                minValue = Matrix[i][j];
                minIndex = {i, j};
            }
    // Adding the min value to result
    res.push_back(minIndex);
    // Updating the visited indexes in track vector to 0
    track[minIndex.first] = track[minIndex.second] = 0;
    // Updating the values in track with the least distance
    for (int i = 1; i < size; ++i)
        if (track[i])
            if (Matrix[minIndex.first][i] < Matrix[minIndex.second][i])
                track[i] = minIndex.first;
            else
                track[i] = minIndex.second;
    // since we already added two values into track,
    // we can run the loop only till size-2
    for (int n = 1; n < size - 2; ++n)
    {
        minValue = INT_MAX;
        // finding the next nearest minimum node
        for (int i = 1; i < size; ++i)
            if (track[i])
                if (Matrix[i][track[i]] < minValue)
                {
                    minValue = Matrix[i][track[i]];
                    minIndex = {i, track[i]};
                }
        // marking the node's value in track as 0
        track[minIndex.first] = 0;
        res.push_back(minIndex);
        // Updating the values in track with the least distance
        for (int i = 1; i < size; ++i)
            if (track[i])
                if (Matrix[i][minIndex.first] < Matrix[i][track[i]])
                    track[i] = minIndex.first;
    }
    return res;
}

void Graph::Cost(vector<pair<int, int>> table)
{
    int res{};
    for (auto i : table)
    {
        res += Matrix[i.first][i.second];
        cout << "(" << i.first << ", " << i.second << ") = " << Matrix[i.first][i.second] << "\n";
    }
    cout << "\nTotal Cost: " << res << "\n";
}

int main()
{
    // 1 based indexing
    int n = 7 + 1;
    Graph g(n);

    // Adding edges to graph
    vector<int> U{1, 1, 2, 2, 3, 4, 4, 5, 5};
    vector<int> V{6, 2, 3, 7, 4, 7, 5, 7, 6};
    vector<int> W{5, 25, 12, 10, 8, 14, 16, 18, 20};
    for (int i = 0; i < U.size(); ++i)
        g.addEdge(U[i], V[i], W[i]);

    // // Displaying Matrix
    // cout << "Matrix: \n";
    // g.displayMatrix();

    // calculating minimum cost spanning tree
    vector<pair<int, int>> res = g.Prims();
    g.Cost(res);

    return 0;
}