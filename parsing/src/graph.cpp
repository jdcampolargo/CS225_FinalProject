#include "../airport/include/airport.h"
#include "../include/graph.h"
#include "../include/node.h"
#include "../airport/include/airport.h"
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>

#define pi 3.14159265358979323846

Graph::Graph(vector<Node<Airport>>& nodes, vector<Edge>& edges) {
    adjacencyMatrix_.resize(nodes.size(), vector<vector<double>>(nodes.size()));
    nodes_ = nodes;
    for (int i = 0; i < nodes_.size(); i++) {
        airportToIndexMap.insert(std::pair<string, int>(nodes_[i].getData().airportCode_, i));
    }
    int count = 0;
    for (Edge edge : edges) {
        insertEdge(edge);
    }
}

void Graph::insertNode(Node& node) {
    nodes_.push_back(node);
    nodeCount++;
    vector<double> temp;
    temp.resize(nodeCount);
    adjacencyMatrix_.push_back(temp);

    for (int i = 0; i < nodeCount - 1; i++) {
        adjacencyMatrix_[i].push_back(0);
    }
    airportToIndexMap.insert(pair<std::string, int>(node.getData().airportCode_, nodeCount - 1));
}

void Graph::insertEdge(Edge edge) {
    int nodeIdx1;
    int nodeIdx2;
    bool failed = false;

    //check if node is found
    try {
        nodeIdx1 = airportToIndexMap.at(edge.nodeOneCode);
    } catch (const std::exception& ex) {
        failed = true;
        //cout<<"Couldn't find "<< edge.nodeOneCode <<endl;
    }

    try {
        nodeIdx2 = airportToIndexMap.at(edge.nodeTwoCode);
    } catch (const std::exception& ex) {
        failed = true;
        //cout<<"Couldn't find "<< edge.nodeTwoCode <<endl;
    }
    if (!failed && airportToIndexMap.at(edge.nodeTwoCode) == airportToIndexMap.at(edge.nodeOneCode)) {
        failed = true;
    }

    if (!failed) {
        //find distance
        double lat1 = std::stod(nodes_[nodeIdx1].getData().latitude_);
        double long1 = std::stod(nodes_[nodeIdx1].getData().longitude_);
        double lat2 = std::stod(nodes_[nodeIdx2].getData().latitude_);
        double long2 = std::stod(nodes_[nodeIdx2].getData().longitude_);
        double flightDistance = calculateDistance(lat1, long1, lat2, long2);

        //add edge to edges list for each node
        nodes_.at(nodeIdx1).edges.push_back(edge);
        adjacencyMatrix_[nodeIdx1][nodeIdx2] = flightDistance;
        edgesCount++;
    }
    std::cout<<count<<std::endl;
}

double Graph::calculateDistance(double lat1, double long1, double lat2,
                                double long2) {
  double dist;
  dist = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2);
  dist = acos(dist);
  dist = (6371 * pi * dist) / 180; // formula for calculalting distance
  return dist;
}

int Graph::findNumberOfConnections(string airportCode) {
  int connections = 0;
  for (int i = 0; i < adjacencyMatrix_[airportToIndexMap[airportCode]].size();
       i++) {
    if (adjacencyMatrix_[airportToIndexMap[airportCode]][i].size() != 0) {
      connections += adjacencyMatrix_[airportToIndexMap[airportCode]][i].size();
    }
  }
  return connections;
}

std::queue<Node<Airport>> Graph::BFS(string startPosition) {
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

list<Node<Airports>> DijkstraAlgo(string startPosition) {
  return NULL;
}
