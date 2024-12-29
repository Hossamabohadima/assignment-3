#include <iostream>
#include "Prim.cpp"
using namespace std;

int main()
{
    int numberOfVertices = 5;
    int **graph = new int *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        graph[i] = new int[numberOfVertices];
    }

    // Example graph as adjacency matrix
    int exampleGraph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            graph[i][j] = exampleGraph[i][j];
        }
    }

    cout << "Cost of Minimum Spanning Tree: " << getMstCost(graph, numberOfVertices) << endl;

    for (int i = 0; i < numberOfVertices; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
