#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct Edge
{
    int to, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
    bool operator>(const Edge &other) const
    {
        return weight > other.weight;
    }
};
struct UnionFind
{
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    // return parent of x and ensure it is stored correctly
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return false;

        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};
long long bfs(int start, const vector<vector<Edge>> &graph)
{
    vector<long long> dist(graph.size(), LLONG_MAX);
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (const auto &edge : graph[node])
        {
            if (dist[node] + (1LL << edge.weight) < dist[edge.to])
            {
                dist[edge.to] = dist[node] + (1LL << edge.weight);
                q.push(edge.to);
            }
        }
    }

    long long sum = 0;
    for (auto d : dist)
    {
        if (d != LLONG_MAX)
        {
            sum += d;
        }
    }
    return sum;
}
int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A - 1].push_back({B - 1, C});
        graph[B - 1].push_back({A - 1, C});
    }
    long long result = 0;
    for (int i = 0; i < N; i++)
    {
        long long totalCost = bfs(i, graph);
        result += totalCost;
    }
    cout << result;
}