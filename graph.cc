#include <stdexcept>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "graph.hh"

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

bool Graph::isOddDegree(int vertex)
{
    return degree(vertex) % 2 == 1;
}

bool Graph::isEvenDegree(int vertex)
{
    return degree(vertex) % 2 == 0;
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