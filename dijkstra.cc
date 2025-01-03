#include <iostream>
#include <limits.h>

#include "dijkstra.hh"

int Dijkstra::getMinimumDistance()
{
    int min = INT_MAX, minIndex;

    for (int i = 0; i < graph->getOrder(); i++)
    {
        if (!wasSet[i] && distances[i] <= min)
        {
            min = distances[i];
            minIndex = i;
        }
    }

    return minIndex;
}

Dijkstra::Dijkstra(Graph *graph) : wasRun(false), graph(graph) {};

void Dijkstra::run(int sourceVertex)
{
    int order = graph->getOrder();

    if (wasRun)
    {
        wasSet.clear();
        distances.clear();
    }

    wasSet.resize(order, false);
    distances.resize(order, INT_MAX);

    distances[sourceVertex] = 0;

    for (int count = 0; count < order - 1; ++count)
    {
        int u = getMinimumDistance();

        wasSet[u] = true;

        for (int v = 0; v < order; ++v)
        {
            if (!wasSet[v] && graph->getWeight(u, v) && distances[u] != INT_MAX && distances[u] + graph->getWeight(u, v) < distances[v])
            {
                distances[v] = distances[u] + graph->getWeight(u, v);
            }
        }
    }

    wasRun = true;
}

int Dijkstra::getDistance(int destination)
{
    if (!wasRun)
    {
        throw std::invalid_argument("Call run() before getting the distance.");
    }

    return distances[destination];
}

void Dijkstra::printSolution(int sourceVertex)
{
    std::cout << "Vertex\tDistance from source vertex" << std::endl;
    for (int i = 0; i < graph->getOrder(); i++)
    {
        std::cout << i << "\t\t" << distances[i] << std::endl;
    }
}