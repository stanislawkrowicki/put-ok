#pragma once

#include <vector>

class Graph
{
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int order;

    void _getOddPairings(std::vector<int> &oddDegrees, std::vector<std::vector<std::pair<int, int>>> &allPairs);

public:
    Graph(int order);

    int getOrder();
    void addEdge(int startVertex, int endVertex, int weight);

    int getWeight(int startVertex, int endVertex);

    int degree(int vertex);
    bool isOddDegree(int vertex);
    bool isEvenDegree(int vertex);

    int countOddDegrees();
    std::vector<int> getOddDegrees();

    std::vector<std::vector<std::pair<int, int>>> getOddPairings();

    std::vector<std::pair<int, int>> getOptimalPairing();

    void displayMatrix() const;
};