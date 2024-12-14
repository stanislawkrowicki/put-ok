/**
 * @struct OptimalPairing
 * @brief Represents an optimal pairing of vertices with their corresponding weight.
 *
 * @var OptimalPairing::pairing
 * A vector of pairs of integers representing the optimal pairing of vertices.
 *
 * @var OptimalPairing::weight
 * An integer representing the total weight of the optimal pairing.
 */

/**
 * @class Graph
 * @brief Represents a graph using an adjacency matrix.
 *
 * The Graph class provides methods to manipulate and analyze a graph represented by an adjacency matrix.
 *
 * @var Graph::adjacencyMatrix
 * A 2D vector representing the adjacency matrix of the graph.
 *
 * @var Graph::order
 * An integer representing the number of vertices in the graph.
 *
 * @fn Graph::Graph(int order)
 * @brief Constructs a graph with a specified number of vertices.
 *
 * @param order The number of vertices in the graph.
 *
 * @fn int Graph::getOrder()
 * @brief Returns the number of vertices in the graph.
 *
 * @return The number of vertices in the graph.
 *
 * @fn void Graph::addEdge(int startVertex, int endVertex, int weight)
 * @brief Adds an edge between two vertices with a specified weight.
 *
 * @param startVertex The starting vertex of the edge.
 * @param endVertex The ending vertex of the edge.
 * @param weight The weight of the edge.
 *
 * @fn int Graph::getWeight(int startVertex, int endVertex)
 * @brief Returns the weight of the edge between two vertices.
 *
 * @param startVertex The starting vertex of the edge.
 * @param endVertex The ending vertex of the edge.
 * @return The weight of the edge.
 *
 * @fn int Graph::sumWeight()
 * @brief Returns the sum of all edge weights in the graph.
 *
 * @return The sum of all edge weights.
 *
 * @fn int Graph::degree(int vertex)
 * @brief Returns the degree of a specified vertex.
 *
 * @param vertex The vertex whose degree is to be calculated.
 * @return The degree of the vertex.
 *
 * @fn bool Graph::isOddDegree(int vertex)
 * @brief Checks if a specified vertex has an odd degree.
 *
 * @param vertex The vertex to check.
 * @return True if the vertex has an odd degree, false otherwise.
 *
 * @fn bool Graph::isEvenDegree(int vertex)
 * @brief Checks if a specified vertex has an even degree.
 *
 * @param vertex The vertex to check.
 * @return True if the vertex has an even degree, false otherwise.
 *
 * @fn int Graph::countOddDegrees()
 * @brief Returns the number of vertices with odd degrees.
 *
 * @return The number of vertices with odd degrees.
 *
 * @fn std::vector<int> Graph::getOddDegrees()
 * @brief Returns a vector of vertices with odd degrees.
 *
 * @return A vector of vertices with odd degrees.
 *
 * @fn std::vector<std::vector<std::pair<int, int>>> Graph::getOddPairings()
 * @brief Returns all possible pairings of vertices with odd degrees.
 *
 * @return A vector of vectors of pairs of integers representing all possible pairings of vertices with odd degrees.
 *
 * @fn OptimalPairing Graph::getOptimalPairing()
 * @brief Returns the optimal pairing of vertices with odd degrees.
 *
 * @return An OptimalPairing struct representing the optimal pairing of vertices with odd degrees.
 *
 * @fn void Graph::displayMatrix() const
 * @brief Displays the adjacency matrix of the graph.
 */
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