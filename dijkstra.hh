#pragma once

#include <vector>
#include "graph.hh"

class Dijkstra
{
private:
    std::vector<bool> wasSet;
    std::vector<int> distances;
    Graph *graph;

    // <summary>
    // Get the vertex with the minimum distance from the source vertex
    // from the set of vertices not yet included in the shortest path tree
    // </summary>
    int getMinimumDistance();

    // <summary>
    // Print the distance from the source vertex to the destination vertex
    // </summary>
    int getDistance(int source, int destination);

public:
    bool wasRun;

    Dijkstra(Graph *graph);
    void run(int sourceVertex);

    // <summary>
    // Utility: Print all distances to vertices from the source vertex
    // </summary>
    void printSolution(int sourceVertex);
};
