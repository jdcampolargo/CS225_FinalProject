#include <iostream>
#include "include/node.h"
#include "src/node.cpp"
#include "../airport/include/airport.h"
#include "include/parser.h"
#include "include/graph.h"
#include <map>

int main() {
    Parser parser = Parser();
    std::vector<Node<Airport>> nodesList = std::vector<Node<Airport>>();
    std::vector<Edge> edgesList = std::vector<Edge>();
    parser.InputNodes(nodesList, "../data/AirportData.csv");
    parser.InputEdges(edgesList, "../data/RoutesData.csv");
    Graph graph(nodesList, edgesList);

    std::cout<<graph.adjacencyMatrix_[graph.airportToIndexMap.at("BRL")][graph.airportToIndexMap.at("ORD")].size()<<std::endl;
    std::cout<<graph.adjacencyMatrix_[graph.airportToIndexMap.at("BRL")][graph.airportToIndexMap.at("ORD")][0]<<std::endl;
    std::cout<<graph.findNumberOfConnections("DME")<<std::endl;
    return 0;
}