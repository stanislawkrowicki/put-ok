#include <stdexcept>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stack>
#include <limits.h>

#include "graph.hh"
#include "dijkstra.hh"

void Graph::_getOddPairings(std::vector<int> &oddDegrees, std::vector<std::vector<std::pair<int, int>>> &allPairs)
{
    struct State
    {
        std::vector<std::pair<int, int>> currentPairing;
        std::vector<int> remainingOdds;
    };

    std::stack<State> stack;
    stack.push({{}, oddDegrees});

    while (!stack.empty())
    {
        State state = stack.top();
        stack.pop();

        if (state.remainingOdds.empty())
        {
            allPairs.push_back(state.currentPairing);
            continue;
        }

        int first = state.remainingOdds.back();
        state.remainingOdds.pop_back();

        for (size_t i = 0; i < state.remainingOdds.size(); ++i)
        {
            int second = state.remainingOdds[i];
            std::vector<std::pair<int, int>> newPairing = state.currentPairing;
            newPairing.push_back({first, second});

            std::vector<int> newRemainingOdds = state.remainingOdds;
            newRemainingOdds.erase(newRemainingOdds.begin() + i);

            stack.push({newPairing, newRemainingOdds});
        }
    }
}

Graph::Graph(int order) : order(order)
{
    adjacencyMatrix.resize(order, std::vector<int>(order, 0));
}

int Graph::getOrder()
{
    return order;
}

void Graph::addEdge(int startVertex, int endVertex, int weight)
{
    std::stringstream errorMessageStream;
    if (weight <= 0)
    {
        errorMessageStream << "Weight must be greater than zero.";
        throw std::invalid_argument(errorMessageStream.str());
    }

    if (startVertex >= 0 && startVertex < order && endVertex >= 0 && endVertex < order)
    {
        adjacencyMatrix[startVertex][endVertex] = weight;
    }
    else
    {
        errorMessageStream << "Cannot put vertex " << startVertex << " " << endVertex << " "
                           << weight << " into graph of order " << order;

        throw std::invalid_argument(errorMessageStream.str());
    }
}

void Graph::setAdjacencyMatrix(std::vector<std::vector<int>> matrix)
{
    if (matrix.size() != order)
    {
        throw std::invalid_argument("Matrix size does not match the order of the graph.");
    }

    for (int i = 0; i < order; ++i)
    {
        if (matrix[i].size() != order)
        {
            throw std::invalid_argument("Matrix size does not match the order of the graph.");
        }
    }

    adjacencyMatrix = matrix;
}

int Graph::degree(int vertex)
{
    int degree = 0;

    for (int i = 0; i < order; ++i)
    {
        if (adjacencyMatrix[vertex][i] > 0)
            degree++;
    }

    return degree;
}

int Graph::getWeight(int startVertex, int endVertex)
{
    return adjacencyMatrix[startVertex][endVertex];
}

int Graph::sumWeight()
{
    int sum = 0;

    for (int i = 0; i < order; ++i)
    {
        for (int j = i; j < order; ++j)
        {
            sum += adjacencyMatrix[i][j];
        }
    }

    return sum;
}

bool Graph::isOddDegree(int vertex)
{
    return degree(vertex) % 2 == 1;
}

bool Graph::isEvenDegree(int vertex)
{
    return degree(vertex) % 2 == 0;
}

int Graph::countOddDegrees()
{
    int count = 0;

    for (int i = 0; i < order; ++i)
    {
        if (isOddDegree(i))
        {
            count++;
        }
    }

    return count;
}

std::vector<int> Graph::getOddDegrees()
{
    std::vector<int> oddDegrees;

    for (int i = 0; i < order; ++i)
    {
        if (isOddDegree(i))
        {
            oddDegrees.push_back(i);
        }
    }

    return oddDegrees;
}

std::vector<std::vector<std::pair<int, int>>> Graph::getOddPairings()
{
    std::vector<int> oddDegrees = getOddDegrees();
    int n = oddDegrees.size();

    if (n == 0)
        return {};

    if (n % 2 != 0)
        throw std::invalid_argument("Number of odd degrees must be even.");

    std::vector<std::vector<std::pair<int, int>>> allPairs;
    _getOddPairings(oddDegrees, allPairs);

    return allPairs;
}

OptimalPairing Graph::getOptimalPairing()
{
    Dijkstra dijkstra(this);

    std::vector<std::vector<std::pair<int, int>>> allPairs = getOddPairings();

    int minWeight = INT_MAX;

    std::vector<std::pair<int, int>> optimalPairing;

    OptimalPairing optimalPairingStruct;

    for (const auto &pairing : allPairs)
    {
        int weight = 0;

        for (const auto &pair : pairing)
        {
            dijkstra.run(pair.first);
            weight += dijkstra.getDistance(pair.second);
        }

        if (weight < minWeight)
        {
            minWeight = weight;
            optimalPairing = pairing;
            optimalPairingStruct.pairing = pairing;
            optimalPairingStruct.weight = weight;
        }
    }

    return optimalPairingStruct;
}

void Graph::displayMatrix() const
{
    for (int i = 0; i < order; ++i)
    {
        for (int j = 0; j < order; ++j)
        {
            std::cout << std::setw(3) << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}