#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

#include "graph.hh"
#include "dijkstra.hh"

using json = nlohmann ::json;

#define EXTRA_OUTPUT

int solve(Graph graph)
{
    auto oddDegrees = graph.getOddDegrees();

#ifdef EXTRA_OUTPUT
    for (const auto &degree : oddDegrees)
    {
        std::cout << degree << " ";
    }
    std::cout << std::endl;
#endif

    auto oddPairs = graph.getOddPairings();

    if (oddPairs.empty())
    {
        int length = graph.sumWeight();
#ifdef EXTRA_OUTPUT
        std::cout << "No odd pairings found." << std::endl;
#endif
        return length;
    }

#ifdef EXTRA_OUTPUT
    for (const auto &pair : oddPairs)
    {
        for (const auto &p : pair)
        {
            std::cout << "(" << p.first << ", " << p.second << ") ";
        }
        std::cout << std::endl;
    }
#endif

    auto optimalPairing = graph.getOptimalPairing();

#ifdef EXTRA_OUTPUT
    std::cout << "Optimal pairing: " << std::endl;

    for (const auto &pair : optimalPairing.pairing)
    {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }

#endif
    return graph.sumWeight() + optimalPairing.weight;
}

int main()
{
    std::cout << "What file to read graphs from?: ";
    std::string filename;
    std::cin >> filename;

    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "File not found." << std::endl;
        return 1;
    }

    json jsonData = json::parse(file);

    file.close();

    std::cout << "Which graph to use?: ";
    std::string graphName;
    std::cin >> graphName;

    if (!jsonData.contains(graphName))
    {
        std::cerr << "Graph not found in the provided file." << std::endl;
        return 1;
    }

    json graphData = jsonData[graphName];

    if (!graphData.contains("order") || !graphData.contains("matrix"))
    {
        std::cerr << "Graph data is not in the correct format." << std::endl;
        return 1;
    }

    int order = graphData["order"];
    auto matrix = graphData["matrix"];

    Graph graph(order);
    graph.setAdjacencyMatrix(matrix);

    int result = solve(graph);

    std::cout << "Chinese Postman Route is of length " << result << std::endl;
    return 0;
}