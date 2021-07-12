// TC: O(n^3)
// SC: O(n^2)

#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> Matrix;

public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    void Display(vector<vector<int>> mat);
    void Display() { Display(Matrix); }
    vector<vector<int>> allPairSP();
};

Graph::Graph(int n)
{
    Matrix.resize(n, vector<int>(n, INT_MAX));
}

void Graph::addEdge(int u, int v, int w)
{
    Matrix[u][v] = w;
}

void Graph::Display(vector<vector<int>> mat)
{
    for (auto i : mat)
    {
        for (auto j : i)
            if (j == INT_MAX)
                cout << "~ ";
            else
                cout << j << " ";
        cout << endl;
    }
}

vector<vector<int>> Graph::allPairSP()
{
    int n = Matrix.size();
    vector<vector<int>> temp = Matrix;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (temp[i][k] == INT_MAX or temp[k][j] == INT_MAX)
                    continue;
                else
                    temp[i][j] = min(temp[i][j], temp[i][k] + temp[k][j]);
            }
    return temp;
}

int main()
{
    int n = 3 + 1;
    Graph G(n);

    vector<int> U{0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3};
    vector<int> V{0, 1, 3, 0, 1, 2, 0, 2, 3, 0, 3};
    vector<int> W{0, 3, 7, 8, 0, 2, 5, 0, 1, 2, 0};

    for (int i = 0; i < U.size(); ++i)
        G.addEdge(U[i], V[i], W[i]);

    cout << "Original Matrix: " << endl;
    G.Display();
    cout << endl;

    cout << "APSP Matrix: " << endl;
    vector<vector<int>> APSP = G.allPairSP();
    G.Display(APSP);

    return 0;
}