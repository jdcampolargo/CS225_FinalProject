#include "../airport/include/airport.h"
#include "../include/graph.h"
#include "../include/node.h"
#include "../include/pagerank.h"
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

PageRank::PageRank(size_t max, Graph& graph) {
    max_airports_ = max;
    auto airports = graph.nodes_;
    dimension_ = graph.nodes_.size();
    adjacency_matrix_.resize(dimension_, vector<double>(dimension_));
    airport_codes_.resize(dimension_);

    // populate adjacency matrix with placeholder values
    for (int i = 0; i < dimension_; i++) {
        for (int j = 0; j < dimension_; j++) {
            adjacency_matrix_[i][j] = 0.0;
        }        
    }

    // create the list of airport codes
    int x = 0;
    for (auto it = airports.begin(); it != airports.end(); ++it) {
        airport_codes_[x] = (it->getData().airportCode_);
        x++;     
    }
    

    // update matrix with routes
    x = 0;
    for (auto it = airports.begin(); it != airports.end(); ++it) {
        if (x == dimension_) {
            break;
        }
        for (auto routes = it->edges.begin(); routes != it->edges.end(); ++routes) {
            int y = 0;
            for (auto code = airport_codes_.begin(); code != airport_codes_.end(); ++code) {
                if (*code == routes->nodeTwoCode) { 
                    break;
                }
                y++;
            } 
            if (y == dimension_) {
                break;
            }
            adjacency_matrix_[y][x] = 1;
        }
        x++;
    }
    createInitialVector();
}

void PageRank::updateAdjMatrix(double damping) {
    damping_factor_ = (1 - damping) / dimension_;

    // apply pagerank algorithm to matrix
    for (int i = 0; i < dimension_; i++) {
        double sum = 0;
        for(int j = 0; j < dimension_; j++) {
            sum += adjacency_matrix_[j][i];
        }     
        if (sum == 0){
            for (int j = 0; j < dimension_; j++){
                adjacency_matrix_[j][i] = 1 / (double)dimension_;
            }
        } else {
            for (int j = 0; j < dimension_; j++){
                adjacency_matrix_[j][i] = (adjacency_matrix_[j][i] / sum) * damping + damping_factor_;
            }
        }
    }
}

void PageRank::createInitialVector() {
    vector<pair<string, double>> initial;
    initial.resize(dimension_);
    for (unsigned i = 0; i < dimension_; i++) {
       initial[i].second = 1;
       initial[i].first = airport_codes_[i];
    }
    initial_ = initial;
}

vector<pair<string, double>> PageRank::calculateRank(size_t iterations) {
    // vectors to hold values as calculated
    vector<pair<string, double>> holder1 = initial_;
    vector<pair<string, double>> holder2 = initial_;
    for (int t = 0; t < iterations; t++) {
        for (int i = 0; i < dimension_; i++) {
            holder2[i].second = 0;

            //calculate product of matrix and vector 
            for (int j = 0; j < dimension_; j++){
                holder2[i].second += (adjacency_matrix_[i][j] * holder1[j].second);
            }     
        }
        holder1 = holder2;
    }
    pr_ = holder1;
    return pr_;
}

void PageRank::getMostPopularAirports(vector<pair<string, double>> list) {
    vector<pair<string, double>> pairVector = list;
    popularAirportHelper(pairVector);
}

void PageRank::popularAirportHelper(vector<pair<string, double>>& pairVector) {
    int max = 0;
    string airport;
    int idx = 0;
    for (int i = 0; i < pairVector.size(); i++) {
        if (pairVector[i].second > max) {
            max = pairVector[i].second;
            airport = pairVector[i].first;
            idx = i;
        }
    }
    mostPopularAirports.push_back(airport);
    pairVector.erase(pairVector.begin() + idx);
    if (mostPopularAirports.size() < max_airports_) {
        popularAirportHelper(pairVector);
    } else  {
        return;
    }
}

void PageRank::printMostPopularAirports() {
    for (int i = 0; i < mostPopularAirports.size(); i++) {
        cout<<mostPopularAirports[i]<<endl;
    }
}