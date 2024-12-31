#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;
struct Binary
{
    set<long long> powers;
    Binary() {};
    Binary(long long power)
    {
        powers.insert(power);
    }
    void add(long long power)
    {
        if (!powers.insert(power).second) // If `power` already exists
        {
            powers.erase(power); // Remove the existing power
            add(power + 1);      // Add the next power
        }
    }
    void add(Binary binary)
    {
        for (long long power : binary.powers)
        {
            add(power); // Use the existing add method to handle each power
        }
    }
    void print() const
    {
        int maxPower = *powers.rbegin(); // Get the largest power
        for (int i = maxPower; i >= 0; i--)
        {
            if (powers.find(i) != powers.end())
            {
                cout << '1';
            }
            else
            {
                cout << '0';
            }
        }
        cout << endl;
    }
    Binary operator+(const Binary &other) const
    {
        Binary result;
        for (long long power : powers)
        {
            result.powers.insert(power);
        }
        result.add(other);
        return result;
    }
    bool operator<(const Binary &other) const
    {

        // Compare the sets from largest element to smallest element
        auto it1 = powers.rbegin();       // Reverse iterator for current object's powers
        auto it2 = other.powers.rbegin(); // Reverse iterator for other object's powers

        // Compare the sets element by element
        while (it1 != powers.rend() && it2 != other.powers.rend())
        {
            if (*it1 < *it2)
                return true;
            else if (*it1 > *it2)
                return false;
            ++it1;
            ++it2;
        }

        // If one set is a prefix of the other, the larger set is "greater"
        return it1 == powers.rend() && it2 != other.powers.rend(); // Empty set is considered less than non-empty set
    }
    bool operator>(const Binary &other) const
    {
        // Compare the sets from largest element to smallest element
        auto it1 = powers.rbegin();       // Reverse iterator for current object's powers
        auto it2 = other.powers.rbegin(); // Reverse iterator for other object's powers

        // Compare the sets element by element
        while (it1 != powers.rend() && it2 != other.powers.rend())
        {
            if (*it1 > *it2)
                return true;
            else if (*it1 < *it2)
                return false;
            ++it1;
            ++it2;
        }

        // If one set is a prefix of the other, the larger set is "greater"
        return it1 != powers.rend() && it2 == other.powers.rend(); // Non-empty set is greater than an empty set
    }
};

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
template <typename T>
void dijkstra(int start, const vector<vector<Edge>> &graph, vector<vector<T>> &distances, T max, T zero)
{
    vector<T> dist(graph.size(), max);
    dist[start] = zero;

    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
    pq.push({zero, start});

    while (!pq.empty())
    {
        T d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node])
        {
            continue;
        }

        for (const auto &edge : graph[node])
        {
            T newDist = dist[node] + edge.weight;
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
    const Binary zero;
    const Binary max(LLONG_MAX);
    vector<vector<Binary>> distances(N, vector<Binary>(N, max));

    for (int i = 0; i < N; i++)
    {
        dijkstra(i, graph, distances, max, zero);
    }
    Binary sum = zero;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum.add(distances[i][j]);
        }
    }
    sum.print();
    return 0;
}