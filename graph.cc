#include <stdexcept>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "graph.hh"

Graph::Graph(int order) : order(order)
{
    adjacencyMatrix.resize(order, std::vector<int>(order, 0));
}

void Graph::addEdge(int startVertex, int endVertex, int weight)
{
    if (startVertex >= 0 && startVertex < order && endVertex >= 0 && endVertex < order)
    {
        adjacencyMatrix[startVertex][endVertex] = weight;
    }
    else
    {
        std::stringstream errorMessageStream;
        errorMessageStream << "Cannot put vertex " << startVertex << " " << endVertex << " "
                           << weight << " into graph of order " << order;

        throw std::invalid_argument(errorMessageStream.str());
    }
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