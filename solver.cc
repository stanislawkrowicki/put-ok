#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

#include "graph.hh"
#include "dijkstra.hh"

using json = nlohmann ::json;

#define EXTRA_OUTPUT

/**
 * @brief Checks the validity of JSON input data.
 *
 * This function checks whether the JSON file contains the necessary fields and has a valid structure.
 * Example of a valid JSON file:
 *
 * @code{.json}
 * [
 *     {
 *         "name": "graph1",
 *         "order": 9,
 *         "matrix": [
 *             [0, 4, 0, 0, 0, 0, 0, 8, 0],
 *             [4, 0, 8, 0, 0, 0, 0, 11, 0],
 *             [0, 8, 0, 7, 0, 4, 0, 0, 2],
 *             [0, 0, 7, 0, 9, 14, 0, 0, 0],
 *             [0, 0, 0, 9, 0, 10, 0, 0, 0],
 *             [0, 0, 4, 14, 10, 0, 2, 0, 0],
 *             [0, 0, 0, 0, 0, 2, 0, 1, 6],
 *             [8, 11, 0, 0, 0, 0, 1, 0, 7],
 *             [0, 0, 2, 0, 0, 0, 6, 7, 0]
 *         ]
 *     },
 *     {
 *         "name": "graph2",
 *         "order": 5,
 *         "matrix": [
 *             [0, 2, 0, 6, 0],
 *             [2, 0, 3, 8, 5],
 *             [0, 3, 0, 0, 7],
 *             [6, 8, 0, 0, 0],
 *             [0, 5, 7, 0, 0]
 *         ]
 *     }
 * ]
 * @endcode
 *
 * @param data The JSON data loaded from the file.
 * @return True if the JSON data is valid, false otherwise.
 */
bool validateInput(const json &data)
{
    if (!data.contains("order") || !data.contains("matrix"))
    {
        return false;
    }

    int order = data["order"];
    auto matrix = data["matrix"];

    if (matrix.size() != order)
    {
        return false;
    }

    for (int i = 0; i < order; ++i)
    {
        if (matrix[i].size() != order)
        {
            return false;
        }
    }

    return true;
}

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

    if (!validateInput(graphData))
    {
        std::cerr << "Invalid JSON data. Refer to documentation." << std::endl;
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