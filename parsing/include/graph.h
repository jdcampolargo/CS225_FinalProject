#pragma once
#include "node.h"
#include "edge.h"
#include "../airport/include/airport.h"
#include <vector>
#include <map>

class Graph {
    public:
    Graph(std::vector<Node<Airport>>& nodes, std::vector<Edge>& edges);
    std::vector<std::vector<std::vector<double>>> adjacencyMatrix_;
    std::map<std::string, int> airportToIndexMap;
    double calculateDistance(double lat1, double long1, double lat2, double long2);
    int findNumberOfConnections(std::string airportCode);
    //std::vector<double> getDistanceList(std::string airportCode);
};