#pragma once

#include <vector>

class Graph
{
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int order;

public:
    Graph(int order);

    void addEdge(int startVertex, int endVertex, int weight);
    void displayMatrix() const;
};