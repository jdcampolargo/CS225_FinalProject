#include "../include/graph.h"
#include "../include/node.h"
#include "../src/node.cpp"
#include "../airport/include/airport.h"
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <string>
#include <exception>

#define pi 3.14159265358979323846

Graph::Graph(std::vector<Node<Airport>>& nodes, std::vector<Edge>& edges) {
    adjacencyMatrix_.resize(nodes.size(), std::vector<std::vector<double>>(nodes.size()));
    for (int i = 0; i < nodes.size(); i++) {
        airportToIndexMap.insert(std::pair<std::string, int>(nodes[i].getData().airportCode_, i));
    }
    for (Edge edge : edges) {
        int nodeIdx1;
        int nodeIdx2;
        bool failed = false;

        try {
            nodeIdx1 = airportToIndexMap.at(edge.node1_);
        } catch (const std::exception& ex) {
            failed = true;
            std::cout<<"Couldn't find "<< edge.node1_ <<std::endl;
        }

        try {
            nodeIdx2 = airportToIndexMap.at(edge.node2_);
        } catch (const std::exception& ex) {
            failed = true;
            std::cout<<"Couldn't find "<< edge.node2_ <<std::endl;
        }
        if (!failed) {
            double lat1 = std::stod(nodes[nodeIdx1].getData().latitude_);
            double long1 = std::stod(nodes[nodeIdx1].getData().longitude_);
            double lat2 = std::stod(nodes[nodeIdx2].getData().latitude_);
            double long2 = std::stod(nodes[nodeIdx2].getData().longitude_);
            double flightDistance = calculateDistance(lat1, long1, lat2, long2);

            adjacencyMatrix_[nodeIdx1][nodeIdx2].push_back(flightDistance);
        }
    }
}

double Graph::calculateDistance(double lat1, double long1, double lat2, double long2) {
    double dist;
    dist = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2);
    dist = acos(dist);
    dist = (6371 * pi * dist) / 180;
    return dist;
}

int Graph::findNumberOfConnections(std::string airportCode) {
    int connections = 0;
    for (int i = 0; i < adjacencyMatrix_[airportToIndexMap[airportCode]].size(); i++) {
        if (adjacencyMatrix_[airportToIndexMap[airportCode]][i].size() != 0) {
            connections += adjacencyMatrix_[airportToIndexMap[airportCode]][i].size();
        }
    }
    return connections;
}