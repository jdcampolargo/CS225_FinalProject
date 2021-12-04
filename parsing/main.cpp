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
    //std::cout<<graph.adjacencyMatrix_[graph.adjacencyMatrix_.at("ORD")][graph.adjacencyMatrix_.at("BRL")].size()<<std::endl;

    /*std::cout<<nodesList.at(0).getData().city_<<std::endl;
    std::cout<<nodesList.at(0).getData().country_<<std::endl;
    std::cout<<std::stof(nodesList.at(0).getData().longitude_)<<std::endl;
    std::cout<<std::stof(nodesList.at(0).getData().latitude_)<<std::endl;

    std::cout<<edgesList[0].node1_<< "   " <<edgesList[0].node2_ <<std::endl;
    std::cout<<edgesList[1].node1_<< "   " <<edgesList[1].node2_ <<std::endl;
    std::cout<<edgesList[2].node1_<< "   " <<edgesList[2].node2_ <<std::endl;
    std::cout<<edgesList[3].node1_<< "   " <<edgesList[3].node2_ <<std::endl;*/

    return 0;
}