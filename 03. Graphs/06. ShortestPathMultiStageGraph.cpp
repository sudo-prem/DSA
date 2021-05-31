#include <bits/stdc++.h>
using namespace std;

class MultiStageGraph
{
private:
    vector<vector<int>> Matrix;
    int stages;

public:
    MultiStageGraph(int n, int s);
    void addEdge(int u, int v, int w);
    void Display();
    void displayPath(vector<int> res);
    pair<int, int> findMin(int curr, vector<int> cost);
    vector<int> shortestPath();
};

MultiStageGraph::MultiStageGraph(int n, int s)
{
    Matrix.resize(n, vector<int>(n, 0));
    stages = s;
}

// MultiStagegraph is Always directed
void MultiStageGraph::addEdge(int u, int v, int w)
{
    Matrix[u][v] = w;
}

void MultiStageGraph::Display()
{
    for (auto i : Matrix)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

void MultiStageGraph::displayPath(vector<int> res)
{
    int i = 0, counter{1}, sum{};
    for (int j = 1; j < res.size(); ++j)
    {
        cout << "Path " << counter++ << ": " << i << " to " << res[j] << ", distance = " << Matrix[i][res[j]] << endl;
        sum += Matrix[i][res[j]];
        i = res[j];
    }
    cout << "Total Sum: " << sum << endl;
}

pair<int, int> MultiStageGraph::findMin(int curr, vector<int> cost)
{
    int n = Matrix.size(), minValue = INT_MAX, minIndex{};
    // i starts from curr + 1
    // because the next stage indices are always higher than itself.
    for (int i = curr + 1; i < n; ++i)
    {
        if (Matrix[curr][i] != 0 and Matrix[curr][i] + cost[i] < minValue)
        {
            minValue = Matrix[curr][i] + cost[i];
            minIndex = i;
        }
    }
    return {minValue, minIndex};
}

vector<int> MultiStageGraph::shortestPath()
{
    int source = 0, sink = Matrix.size(), n = Matrix.size();
    vector<int> parent(n, 0);
    vector<int> cost(n, 0);
    vector<int> res(stages, 0);

    cost[sink] = 0;
    parent[sink] = sink;

    // we want this for loop to execute (sink - 1) times
    for (int i = sink - 1; i >= 0; i--)
    {
        pair<int, int> curr = findMin(i, cost);
        cost[i] = curr.first;
        parent[i] = curr.second;
    }

    res[0] = 0;
    for (int i = 1; i < stages; ++i)
        res[i] = parent[res[i - 1]];

    return res;
}

int main()
{
    int n = 9, stages = 4;
    vector<int> U{0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 5, 6};
    vector<int> V{1, 2, 3, 4, 5, 4, 5, 4, 5, 6, 7, 7, 7};
    vector<int> W{2, 1, 3, 2, 3, 6, 7, 6, 8, 9, 6, 4, 5};

    MultiStageGraph G(n, stages);

    for (int i = 0; i < U.size(); ++i)
        G.addEdge(U[i], V[i], W[i]);

    int source = 0;
    vector<int> res = G.shortestPath();
    G.displayPath(res);

    return 0;
}