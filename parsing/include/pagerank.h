#pragma once
#include "node.h"
#include "edge.h"
#include "../airport/include/airport.h"
#include <vector>
#include <map>
#include <cmath>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::pair;

class PageRank {
    public:
    PageRank(size_t max, Graph& graph);
    void updateAdjMatrix(double damping);
    void createInitialVector();
    vector<pair<string, double>> calculateRank(size_t iterations);
    void popularAirportHelper(vector<pair<string, double>>& pairVector);
    void getMostPopularAirports(vector<pair<string, double>> list);
    void printMostPopularAirports();

    unsigned dimension_;
    double damping_factor_;
    size_t max_airports_;
    vector<vector<double>> adjacency_matrix_; 
    vector<string> airport_codes_;
    vector<pair<string, double>> initial_;
    vector<pair<string, double>> pr_;
    vector<string> mostPopularAirports;

};