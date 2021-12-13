#pragma once
#include "../airport/include/airport.h"
#include "include/node.h"
#include "include/parser.h"
#include "include/graph.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Dijkstra {
    public:
        Dijkstra(Graph& graph, string StartAirport, string DestinationAirport);
        map<string, double> distances;
        map<string, string> previous_nodes;
        vector<string> path;
        double path_distance = 0;
};