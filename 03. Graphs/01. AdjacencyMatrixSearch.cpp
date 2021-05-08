#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<bool>> Matrix;

public:
    Graph(int n);
    void addEdge(int u, int v);
    void displayMatrix();
    vector<int> BFS(int start);
    vector<int> DFS(int start);
    void RDFS(int start, vector<int> &dfs);
};

Graph::Graph(int n)
{
    Matrix.resize(n, vector<bool>(n, 0));
}

void Graph::addEdge(int u, int v)
{
    Matrix[u][v] = Matrix[v][u] = true;
}

void Graph::displayMatrix()
{
    int s = Matrix.size();
    for (int i = 0; i < s; ++i)
    {
        for (int j = 0; j < s; ++j)
            cout << Matrix[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

vector<int> Graph::BFS(int start)
{
    int size = Matrix.size();
    vector<int> bfs{};
    vector<bool> visited(size, false);
    queue<int> qu{};
    qu.push(start);
    visited[start] = true;
    while (!qu.empty())
    {
        int curr = qu.front();
        qu.pop();
        bfs.push_back(curr);
        for (int i = 0; i < size; ++i)
        {
            if (Matrix[curr][i] and !visited[i])
            {
                visited[i] = true;
                qu.push(i);
            }
        }
    }
    return bfs;
}

vector<int> Graph::DFS(int start)
{
    int size = Matrix.size();
    vector<int> dfs{};
    vector<bool> visited(size, false);
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        dfs.push_back(curr);
        for (int i = 0; i < size; ++i)
        {
            if (Matrix[curr][i] and !visited[i])
            {
                visited[i] = true;
                st.push(i);
            }
        }
    }
    return dfs;
}

void Graph::RDFS(int start, vector<int> &dfs)
{
    static int n = Matrix.size();
    static vector<bool> visited(n, false);
    if (!visited[start])
    {
        dfs.push_back(start);
        visited[start] = true;
        for (int i = 1; i < n; ++i)
            if (Matrix[start][i] and !visited[i])
                RDFS(i, dfs);
    }
}

int main()
{
    // 1 Based Indexing
    int n = 7 + 1;
    Graph g(n);
    vector<int> U{1, 2, 2, 3, 5, 4};
    vector<int> V{2, 3, 7, 5, 7, 6};
    for (int i = 0; i < U.size(); ++i)
        g.addEdge(U[i], V[i]);

    // Displays Adjacency Matrix
    cout << "Matrix: \n";
    g.displayMatrix();

    // Breadth First Search (Iterative)
    cout << "BFS: \n";
    vector<int> res = g.BFS(1);
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
    res = g.BFS(4);
    for (auto i : res)
        cout << i << " ";
    cout << "\n\n";

    // Depth First Search (Iterative)
    cout << "DFS: \n";
    res = g.DFS(1);
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
    res = g.DFS(4);
    for (auto i : res)
        cout << i << " ";
    cout << "\n\n";

    // Depth First Search (Recursive)
    cout << "RDFS: \n";
    res = {};
    g.RDFS(1, res);
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
    res = {};
    g.RDFS(4, res);
    for (auto i : res)
        cout << i << " ";
    cout << "\n\n";

    return 0;
}