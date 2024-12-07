#pragma once

#include <vector>

class Graph
{
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int order;

public:
    Graph(int order);

    int getOrder();
    void addEdge(int startVertex, int endVertex, int weight);

    int degree(int vertex);
    int getWeight(int startVertex, int endVertex);
    bool isOddDegree(int vertex);
    bool isEvenDegree(int vertex);
    void displayMatrix() const;
};