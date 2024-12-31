#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
struct Edge
{
    int x;
    int y;
    int gold;
    int silver;
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

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        // x and y are in the same set
        if (rootX == rootY)
        {
            return;
        }
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

bool isConnected(int n, const vector<Edge> &edges, int maxSilver)
{
    UnionFind uf(n);

    for (const auto &edge : edges)
    {
        if (edge.silver <= maxSilver)
        {
            uf.unite(edge.x, edge.y);
        }
    }

    // Check if all cities are connected (all nodes have the same root)
    int root = uf.find(0); // Find the root of the first city
    for (int i = 1; i < n; i++)
    {
        if (uf.find(i) != root)
            return false;
    }

    return true;
}
int main()
{
    int cityCount, roadCount;
    cin >> cityCount >> roadCount;
    int goldPrice, silverPrice;
    cin >> goldPrice >> silverPrice;
    vector<Edge> edges;
    for (int i = 0; i < roadCount; i++)
    {
        Edge edge;
        cin >> edge.x >> edge.y >> edge.gold >> edge.silver;
        edge.x--;
        edge.y--;
        edges.push_back(edge);
    }
    // sort edges on gold
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.gold < b.gold; });
    long long minCost = LLONG_MAX;
    for (int i = 0; i < edges.size(); i++)
    {
        const long long maxGold = edges[i].gold;
        // edges with gold <= maxGold
        vector<Edge> validEdges(edges.begin(), edges.begin() + i + 1);
        // sort edges on silver
        sort(validEdges.begin(), validEdges.end(), [](const Edge &a, const Edge &b)
             { return a.silver < b.silver; });
        // binary search to find optimal amount of silver to choose for i gold
        // (minimum silver to pay for the graph to be connected)
        long long left = 0, right = validEdges.back().silver;
        while (left <= right)
        {
            const long long mid = (left + right) / 2;
            if (isConnected(cityCount, validEdges, mid))
            {
                const long long cost = maxGold * goldPrice + mid * silverPrice;
                minCost = min(cost, minCost);
                // the graph is connected only check for edges with less silver
                // if it will be connected with lower cost
                right = mid - 1;
            }
            else
            {
                // the graph is not connected
                // check for edges with more silver
                left = mid + 1;
            }
        }
    }

    if (minCost == LLONG_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << minCost;
    }
}