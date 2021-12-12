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

class PageRank {
    public:
    void makeAdjMatrix(unsigned dim, double damping);
    vector<double> makeVector();
    vector<double> calculaterRank(vector<double> initial, size_t iterations, bool normalize);
    void popularAirports(size_t topNum);
    void printAdjMatrix();
    void printResults();

    private: 
    unsigned dimension_;
    double damping_factor_;
    unsigned long max_iterations_;
    vector<vector<double>> adjacency_matrix_; 
    vector<string> popular_airports;
    vector<double> pr_;

};