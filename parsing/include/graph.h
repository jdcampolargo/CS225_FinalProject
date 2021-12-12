#pragma once
#include "node.h"
#include "edge.h"
#include "../airport/include/airport.h"
#include <vector>
#include <map>
#include <queue>

using std::vector;
using std::map;
using std::queue;
using std::cout;
using std::end;

class Graph {
    public:
    vector<Node> nodes_;
    vector<vector<double>> adjacencyMatrix_;
    map<std::string, int> airportToIndexMap;
    int nodeCount = 0;
    int edgesCount = 0;

    Graph();

    Graph(vector<Node>& nodes, vector<Edge>& edges);

    void insertNode(Node& node);

    void insertEdge(Edge& edge);

    queue<Node> BFS(std::string startPosition);

    int findNumberOfConnections(std::string airportCode);

    private:
    double calculateDistance(double lat1, double long1, double lat2, double long2);
    
};