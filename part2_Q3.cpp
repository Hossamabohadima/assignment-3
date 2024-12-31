#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int size)
    {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int node)
    {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void unite(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

bool isConnectedDSU(int n, vector<vector<int>> &edges, int source, int destination)
{
    DisjointSet ds(n);
    for (auto &edge : edges)
        ds.unite(edge[0], edge[1]);

    return ds.find(source) == ds.find(destination);
}

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int source = 0, destination = 2;

    if (isConnectedDSU(n, edges, source, destination))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}