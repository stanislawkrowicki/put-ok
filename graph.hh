#pragma once

#include <vector>

struct OptimalPairing
{
    std::vector<std::pair<int, int>> pairing;
    int weight;
};

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
    int sumWeight();

    int degree(int vertex);
    bool isOddDegree(int vertex);
    bool isEvenDegree(int vertex);

    int countOddDegrees();
    std::vector<int> getOddDegrees();

    std::vector<std::vector<std::pair<int, int>>> getOddPairings();

    OptimalPairing getOptimalPairing();

    void displayMatrix() const;
};