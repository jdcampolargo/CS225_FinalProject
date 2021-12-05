#include <iostream>
#include "include/node.h"
#include "src/node.cpp"
#include "../airport/include/airport.h"
#include "include/parser.h"
#include "include/graph.h"
#include <map>
using std::vector;
using std::cout;
using std::endl;

int main() {
    Parser parser = Parser();
    vector<Node<Airport>> nodesList = vector<Node<Airport>>();
    vector<Edge> edgesList = vector<Edge>();
    parser.InputNodes(nodesList, "../data/AirportData.csv");
    parser.InputEdges(edgesList, "../data/RoutesData.csv");
    Graph graph(nodesList, edgesList);

    cout<<graph.adjacencyMatrix_[graph.airportToIndexMap.at("BRL")][graph.airportToIndexMap.at("ORD")].size()<<endl;
    cout<<graph.adjacencyMatrix_[graph.airportToIndexMap.at("BRL")][graph.airportToIndexMap.at("ORD")][0]<<endl;
    cout<<graph.findNumberOfConnections("ATL")<<endl;

    graph.BFS("ORD");

    /*for (int i = 0; i < graph.adjacencyMatrix_.size(); i++) {
        for (int j = 0; j < graph.adjacencyMatrix_.size(); j++) {
            if (graph.adjacencyMatrix_[i][j].size() > 1) {
                std::cout<<nodesList[i].getData().airportCode_<< "--->" << nodesList[j].getData().airportCode_<<std::endl;
                for (int k = 0; k < graph.adjacencyMatrix_[i][j].size(); k++) {
                    std::cout<<graph.adjacencyMatrix_[i][j][k]<<std::endl;
                }
            }
        }
    }*/
    return 0;
}