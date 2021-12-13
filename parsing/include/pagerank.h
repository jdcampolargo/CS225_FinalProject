#pragma once
#include "node.h"
#include "edge.h"
#include "../airport/include/airport.h"
#include <vector>
#include <map>
#include <queue>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class PageRank {
    public:
    PageRank(size_t max, Graph& graph);
    void updateAdjMatrix(double damping);
    vector<double> createInitialVector();
    vector<double> calculateRank(size_t iterations, bool normalize);
    void popularAirports(size_t topNum);
    void printAdjMatrix();
    void printResults();

    unsigned dimension_;
    double damping_factor_;
    unsigned long max_iterations_;
    size_t max_airports_;
    vector<vector<double>> adjacency_matrix_; 
    vector<string> airport_codes_;
    vector<double> initial_;

    vector<string> popular_airports_;
    vector<double> pr_;

};