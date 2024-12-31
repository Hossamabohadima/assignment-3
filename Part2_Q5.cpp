#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct Edge
{
    int to;
    long long weight;
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
long long dijkstra(int start, const vector<vector<Edge>> &graph, vector<vector<long long>> &distances)
{
    vector<long long> dist(graph.size(), LLONG_MAX);
    dist[start] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        long long d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node])
        {
            continue;
        }

        for (const auto &edge : graph[node])
        {
            long long newDist = dist[node] + edge.weight;
            if (newDist < dist[edge.to])
            {
                dist[edge.to] = newDist;
                pq.push({newDist, edge.to});
            }
        }
    }

    // Store the shortest distances from the start node
    for (int i = 0; i < graph.size(); i++)
    {
        distances[start][i] = dist[i];
    }
    return 0;
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
        graph[A - 1].push_back({B - 1, 1ll << C});
        graph[B - 1].push_back({A - 1, 1ll << C});
    }

    vector<vector<long long>> distances(N, vector<long long>(N, LLONG_MAX));

    for (int i = 0; i < N; i++)
    {
        dijkstra(i, graph, distances);
    }
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum += distances[i][j];
        }
    }
    cout << sum;
    return 0;
}