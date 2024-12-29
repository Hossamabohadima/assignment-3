#include <iostream>
#include "Prim.cpp"
using namespace std;
void test1()
{
    cout << "Test 1" << endl;
    int numberOfVertices = 5;

    // Dynamically allocate memory for a 5x5 graph
    int **graph = new int *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        graph[i] = new int[numberOfVertices];
    }

    // Initialize graph
    int exampleGraph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    // Copy data to the dynamically allocated graph
    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            graph[i][j] = exampleGraph[i][j];
        }
    }

    // Call the function
    int mstCost = getMstCost(graph, numberOfVertices);

    if (mstCost == -1)
        cout << "Graph is not fully connected!" << endl;
    else
        cout << "MST Cost: " << mstCost << endl;

    // Free the dynamically allocated memory
    for (int i = 0; i < numberOfVertices; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}
void test2()
{
    cout << "Test 2" << endl;
    int numberOfVertices = 3;

    // Dynamically allocate memory for a 5x5 graph
    int **graph = new int *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        graph[i] = new int[numberOfVertices];
    }
    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    graph[0][1] = 1;
    graph[1][0] = 1;

    // Call the function
    int mstCost = getMstCost(graph, numberOfVertices);

    if (mstCost == -1)
        cout << "Graph is not fully connected!" << endl;
    else
        cout << "MST Cost: " << mstCost << endl;

    // Free the dynamically allocated memory
    for (int i = 0; i < numberOfVertices; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}
void test3()
{
    cout << "Test 3" << endl;
    int numberOfVertices = 5;

    // Dynamically allocate memory for a 5x5 graph
    int **graph = new int *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        graph[i] = new int[numberOfVertices];
    }

    // Initialize graph
    int exampleGraph[5][5] = {
        {0, 2, 0, 3, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {3, 8, 0, 0, 5},
        {0, 5, 7, 5, 0}};

    // Copy data to the dynamically allocated graph
    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            graph[i][j] = exampleGraph[i][j];
        }
    }

    // Call the function
    int mstCost = getMstCost(graph, numberOfVertices);

    if (mstCost == -1)
        cout << "Graph is not fully connected!" << endl;
    else
        cout << "MST Cost: " << mstCost << endl;

    // Free the dynamically allocated memory
    for (int i = 0; i < numberOfVertices; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}
void test4()
{
    cout << "Test 4" << endl;
    int numberOfVertices = 4;

    // Dynamically allocate memory for a 5x5 graph
    int **graph = new int *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        graph[i] = new int[numberOfVertices];
    }
    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[2][3] = 5;
    graph[3][2] = 5;

    // Call the function
    int mstCost = getMstCost(graph, numberOfVertices);

    if (mstCost == -1)
        cout << "Graph is not fully connected!" << endl;
    else
        cout << "MST Cost: " << mstCost << endl;

    // Free the dynamically allocated memory
    for (int i = 0; i < numberOfVertices; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}