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

using std::vector;
using std::pair;
using std::cout;
using std::endl;

Graph::Graph() {}

Graph::Graph(vector<Node>& nodes, vector<Edge>& edges) {
    nodes_ = nodes;
    nodeCount = nodes_.size();
    
    //resize matrix
    vector<double> temp;
    temp.resize(nodeCount);
    adjacencyMatrix_.resize(nodeCount, temp);

    //create map for code to index
    for (int i = 0; i < nodes_.size(); i++) {
        airportToIndexMap.insert(pair<std::string, int>(nodes_[i].getData().airportCode_, i));
    }

    //insert edges
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

        //Check if edge already has weight
        if (int(edge.weight) <= 0) {
            edge.weight = flightDistance;
        }
        nodes_.at(nodeIdx1).edges.push_back(edge);
        adjacencyMatrix_[nodeIdx1][nodeIdx2] = flightDistance;
        edgesCount++;
    }
}

double Graph::calculateDistance(double lat1, double long1, double lat2,
                                double long2) {
  double dist;
    dist = sin(lat1/180 * pi) * sin(lat2/180 * pi) + cos(lat1/180 * pi) * cos(lat2/180 * pi) * cos((long1 - long2)/180 * pi);
    dist = acos(dist);
    dist = 6371 * dist;
  return dist;
}

int Graph::findNumberOfConnections(std::string airportCode) {
    int connections = 0;
    for (int i = 0; i < nodeCount; i++) {
        if (adjacencyMatrix_[airportToIndexMap[airportCode]][i] > 0) {
            connections++;
        }
    }
  return connections;
}

std::queue<Node> Graph::BFS(std::string startPosition) {
    //copy nodes for algo since we dont want to change visited value permenantly
    vector<Node> nodes = nodes_;
    std::queue<Node> path;
    std::queue<Node> visiting;
    Node& startingNode = nodes[airportToIndexMap[startPosition]];

    visiting.push(startingNode);
    startingNode.visited_ = true;
    path.push(startingNode);

    while(!visiting.empty()) {
        Node currentNode = visiting.front();
        cout<<currentNode.getData().name_<<endl;
        visiting.pop();
        for(int i = 0; i < currentNode.edges.size(); i++) {
            int nodetoCheck = airportToIndexMap.at(currentNode.edges[i].nodeTwoCode);
            if (!nodes[nodetoCheck].visited_) {
                nodes[nodetoCheck].visited_ = true;
                visiting.push(nodes[nodetoCheck]);
                path.push(nodes[nodetoCheck]);
            }
        }
    }
    return path;
}
