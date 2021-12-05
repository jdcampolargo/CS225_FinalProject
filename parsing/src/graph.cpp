#include "../airport/include/airport.h"
#include "../include/graph.h"
#include "../include/node.h"
#include "../src/node.cpp"
#include <cmath>
#include <exception>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define pi 3.14159265358979323846

using std::vector;

<<<<<<< HEAD
Graph::Graph(vector<Node<Airport>> &nodes, vector<Edge> &edges) {
  adjacencyMatrix_.resize(nodes.size(), vector<vector<double>>(nodes.size()));
  nodes_ = nodes;
  for (int i = 0; i < nodes.size(); i++) {
    airportToIndexMap.insert(
        std::pair<std::string, int>(nodes[i].getData().airportCode_, i));
  }
  for (Edge edge : edges) {
    int nodeIdx1;
    int nodeIdx2;
    bool failed = false;

    try {
      nodeIdx1 = airportToIndexMap.at(edge.node1_);
    } catch (const std::exception &ex) {
      failed = true;
      // std::cout << "Couldn't find " << edge.node1_ << std::endl;
    }

    try {
      nodeIdx2 = airportToIndexMap.at(edge.node2_);
    } catch (const std::exception &ex) {
      failed = true;
      // std::cout << "Couldn't find " << edge.node2_ << std::endl;
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
=======
Graph::Graph(vector<Node<Airport>>& nodes, vector<Edge>& edges) {
    adjacencyMatrix_.resize(nodes.size(), vector<vector<double>>(nodes.size()));
    nodes_ = nodes;
    for (int i = 0; i < nodes_.size(); i++) {
        airportToIndexMap.insert(std::pair<std::string, int>(nodes_[i].getData().airportCode_, i));
    }
    int count = 0;
    for (Edge edge : edges) {
        int nodeIdx1;
        int nodeIdx2;
        bool failed = false;

        try {
            nodeIdx1 = airportToIndexMap.at(edge.node1_);
        } catch (const std::exception& ex) {
            failed = true;
            //std::cout<<"Couldn't find "<< edge.node1_ <<std::endl;
        }

        try {
            nodeIdx2 = airportToIndexMap.at(edge.node2_);
        } catch (const std::exception& ex) {
            failed = true;
            //std::cout<<"Couldn't find "<< edge.node2_ <<std::endl;
        }
        if (!failed) {
            double lat1 = std::stod(nodes[nodeIdx1].getData().latitude_);
            double long1 = std::stod(nodes[nodeIdx1].getData().longitude_);
            double lat2 = std::stod(nodes[nodeIdx2].getData().latitude_);
            double long2 = std::stod(nodes[nodeIdx2].getData().longitude_);
            double flightDistance = calculateDistance(lat1, long1, lat2, long2);
            adjacencyMatrix_[nodeIdx1][nodeIdx2].push_back(flightDistance);
            count++;
        }
    }
    std::cout<<count<<std::endl;
>>>>>>> e178c44ef25e4cb957c8c83f79ae7dcea5180e39
}

double Graph::calculateDistance(double lat1, double long1, double lat2,
                                double long2) {
  double dist;
  dist = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2);
  dist = acos(dist);
  dist = (6371 * pi * dist) / 180; // formula for calculalting distance
  return dist;
}

int Graph::findNumberOfConnections(std::string airportCode) {
  int connections = 0;
  for (int i = 0; i < adjacencyMatrix_[airportToIndexMap[airportCode]].size();
       i++) {
    if (adjacencyMatrix_[airportToIndexMap[airportCode]][i].size() != 0) {
      connections += adjacencyMatrix_[airportToIndexMap[airportCode]][i].size();
    }
  }
  return connections;
}

std::queue<Node<Airport>> Graph::BFS(std::string startPosition) {
<<<<<<< HEAD
  std::queue<Node<Airport>> visiting;
  Node<Airport> startingNode =
      nodes_[airportToIndexMap[startPosition]]; // position you want to start
                                                // with (airport)
  visiting.push(startingNode);                  // a queque of visited nodes
  int count = 0;
  while (!visiting.empty()) {
    Node<Airport> currentNode = visiting.front();
    currentNode.setVisited(true);

    std::cout << visiting.front().getData().name_ << std::endl;
    visiting.pop();
    startingNode.setVisited(true); // set to visited because we start here
    vector<vector<double>> currentList =
        adjacencyMatrix_[airportToIndexMap[currentNode.getData().airportCode_]];
    for (int i = 0; i < currentList.size(); i++) {
      if (currentList[i].size() != 0 && !nodes_[i].isVisited()) {
        visiting.push(nodes_[i]);
      }
    }
  }
}

//either the path or the distance to get there
=======
    std::queue<Node<Airport>> path;
    std::queue<Node<Airport>> visiting;
    Node<Airport> startingNode = nodes_[airportToIndexMap[startPosition]];
    startingNode.visited_ = true;
    visiting.push(startingNode);
    path.push(startingNode);

    while(!visiting.empty()) {
        Node<Airport> currentNode = visiting.front();
        std::cout<<currentNode.getData().name_<<std::endl;
        visiting.pop();
        vector<vector<double>> currentList = adjacencyMatrix_[airportToIndexMap[currentNode.getData().airportCode_]];
        for(int i = 0; i < currentList.size(); i++) {
            if (!nodes_[i].visited_) {
                if (currentList[i].size() > 0) {
                    nodes_[i].visited_ = true;
                    visiting.push(nodes_[i]);
                    path.push(nodes_[i]);
                }
            }
        }
    }
    return path;
}
>>>>>>> e178c44ef25e4cb957c8c83f79ae7dcea5180e39
