#include <iostream>

#include "graph.hh"
#include "dijkstra.hh"

int main()
{
    Graph graph(9);
    Dijkstra dijkstra(&graph);

    dijkstra.run(0);
    dijkstra.printSolution(0);
    return 0;
}