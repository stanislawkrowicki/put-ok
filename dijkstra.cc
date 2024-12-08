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

int Dijkstra::getDistance(int source, int destination)
{
    return distances[destination];
}

Dijkstra::Dijkstra(Graph *graph) : wasRun(false), graph(graph) {};

void Dijkstra::run(int sourceVertex)
{
    int order = graph->getOrder();

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

void Dijkstra::printSolution(int sourceVertex)
{
    std::cout << "Vertex\tDistance from source vertex" << std::endl;
    for (int i = 0; i < graph->getOrder(); i++)
    {
        std::cout << i << "\t\t" << distances[i] << std::endl;
    }
}