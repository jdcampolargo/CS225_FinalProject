#include "include/Dijkstra.h"
#include "include/airport.h"
#include "include/node.h"
#include "include/parser.h"
#include "include/graph.h"
#include <iostream>
#include <exception>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <climits>
#include <stack>
using namespace std;


Dijkstra::Dijkstra (Graph& graph, string StartAirport, string DestinationAirport) {
    bool failed = false;
    try {
        graph.nodes_.at(graph.airportToIndexMap.at(StartAirport));
    } catch (const std::exception& ex) {
        cout<<"Starting airport: "<<StartAirport<<" is not found"<<endl;
        failed = true;
    }

    try {
        graph.nodes_.at(graph.airportToIndexMap.at(DestinationAirport));
    } catch (const std::exception& ex) {
        cout<<"Destination airport: "<<DestinationAirport<<" is not found"<<endl;
        failed = true;
    }

    if (!failed) {
        vector<Node> nodes = graph.nodes_;
    priority_queue<pair<double, string>, vector<pair<double, string>>,greater<pair<double, string>> > Q;

    for (Node node : nodes) {
        string airportCode = node.getData().airportCode_;
        distances.insert(pair<string, double>(airportCode, INT_MAX));
        previous_nodes.insert(pair<string, string>(airportCode, ""));
    }

    distances.at(StartAirport) = 0.0;
    Q.push(pair<double, string>(0.0, StartAirport));

    while(!Q.empty()) {
        pair<double, string> currentNode = Q.top();
        Q.pop();
        Node nodeObj = nodes.at(graph.airportToIndexMap.at(currentNode.second));
        for (Edge edge : nodeObj.edges) {
            Node n = nodes.at(graph.airportToIndexMap.at(edge.nodeTwoCode));
            if (!n.visited_) {
                double alt = distances.at(edge.nodeOneCode) + edge.weight;
                if (alt < distances.at(edge.nodeTwoCode)) {
                    distances.at(edge.nodeTwoCode) = alt;
                    previous_nodes[edge.nodeTwoCode] = edge.nodeOneCode;
                    Q.push(pair<double, string>(distances.at(edge.nodeTwoCode), edge.nodeTwoCode));
                }
            }
        }
        nodeObj.visited_ = true;
    }
    path_distance = distances.at(DestinationAirport);
    string key = DestinationAirport;
    path.push_back(DestinationAirport);
    int count = 0;
    while(key != StartAirport) {
        path.push_back(previous_nodes[key]);
        key = previous_nodes[key];
        if (count == previous_nodes.size()) {
            path_distance = 0;
            path.clear();
            break;
        }
        count++;
    }
    std::reverse(path.begin(), path.end());
    }
}