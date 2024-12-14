#include <iostream>

#include "graph.hh"
#include "dijkstra.hh"

int main()
{
    Graph graph(5);

    auto oddDegrees = graph.getOddDegrees();

    for (const auto &degree : oddDegrees)
    {
        std::cout << degree << " ";
    }
    std::cout << std::endl;

    auto oddPairs = graph.getOddPairings();

    if (oddPairs.empty())
    {
        std::cout << "No odd pairings found." << std::endl;
        std::cout << "Chinese Postman Route is of length " << graph.sumWeight() << std::endl;
        return 0;
    }

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

    for (const auto &pair : optimalPairing.pairing)
    {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }

    std::cout << std::endl;

    std::cout << "Chinese Postman Route is of length " << graph.sumWeight() + optimalPairing.weight << std::endl;

    return 0;
}