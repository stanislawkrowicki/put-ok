#pragma once

#include <vector>
#include "graph.hh"

/**
 * @class Dijkstra
 * @brief Implements Dijkstra's algorithm for finding the shortest paths from a source vertex to all other vertices in a given graph.
 *
 * This class provides methods to run Dijkstra's algorithm, retrieve the shortest distance to a specific vertex, and print the solution.
 *
 * @note The graph is represented using an adjacency list.
 *
 * @private
 * @var std::vector<bool> wasSet
 * A vector to keep track of vertices for which the shortest path has been found.
 *
 * @private
 * @var std::vector<int> distances
 * A vector to store the shortest distance from the source vertex to each vertex.
 *
 * @private
 * @var Graph* graph
 * A pointer to the graph on which Dijkstra's algorithm will be run.
 *
 * @private
 * @fn int getMinimumDistance()
 * Get the vertex with the minimum distance from the source vertex from the set of vertices not yet included in the shortest path tree.
 *
 * @public
 * @var bool wasRun
 * Flag to check if Dijkstra's algorithm was run.
 *
 * @public
 * @fn Dijkstra(Graph* graph)
 * Constructor to initialize the Dijkstra object with a given graph.
 *
 * @public
 * @fn void run(int sourceVertex)
 * Run Dijkstra's algorithm from the source vertex.
 *
 * @public
 * @fn int getDistance(int destination)
 * Get the distance from the source vertex to the destination vertex.
 *
 * @public
 * @fn void printSolution(int sourceVertex)
 * Utility function to print all distances to vertices from the source vertex.
 */
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
