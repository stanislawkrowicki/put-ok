#include <iostream>

#include "graph.hh"
#include "dijkstra.hh"

int main()
{
    Graph graph(9);

    auto oddDegrees = graph.getOddDegrees();

    for (const auto &degree : oddDegrees)
    {
        std::cout << degree << " ";
    }
    std::cout << std::endl;

    auto oddPairs = graph.getOddPairings();

    for (const auto &pair : oddPairs)
    {
        for (const auto &p : pair)
        {
            std::cout << "(" << p.first << ", " << p.second << ") ";
        }
        std::cout << std::endl;
    }

    auto optimalPairing = graph.getOptimalPairing();

    std::cout << "Optimal pairing: " << std::endl;

    for (const auto &pair : optimalPairing)
    {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }

    return 0;
}