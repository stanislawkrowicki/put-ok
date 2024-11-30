#include <iostream>

#include "graph.hh"

int main()
{
    Graph graph(5);

    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 5, 2);
    graph.addEdge(2, 3, 7);

    graph.displayMatrix();

    return 0;
}