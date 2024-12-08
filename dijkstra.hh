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

public:
    // <summary>
    // Flag to check if Dijkstra's algorithm was run
    // </summary>
    bool wasRun;

    Dijkstra(Graph *graph);

    // <summary>
    // Run Dijkstra's algorithm from the source vertex
    // </summary>
    void run(int sourceVertex);

    // <summary>
    // Print the distance from the source vertex to the destination vertex
    // </summary>
    int getDistance(int destination);

    // <summary>
    // Utility: Print all distances to vertices from the source vertex
    // </summary>
    void printSolution(int sourceVertex);
};
