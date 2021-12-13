#include "catch2/catch.hpp"
#include "include/Dijkstra.h"
#include "../airport/include/airport.h"
#include "include/node.h"
#include "include/parser.h"
#include "include/graph.h"
#include <iostream>
#include <map>
using std::vector;
using std::cout;
using std::endl;

TEST_CASE("test Dijkstra") {
    Parser parser = Parser();
    vector<Node> nodesList;
    parser.InputNodes(nodesList, "../data/AirportData.csv");

    Graph testGraph = Graph();
    for (int i = 0; i < 10; i++) {
        testGraph.insertNode(nodesList[i]);
    }

    Edge edge("GKA", "MAG");
    edge.weight = 1.5;
    Edge edge1("MAG", "HGU");
    edge1.weight = 1.6;
    Edge edge2("HGU", "LAE");
    edge2.weight = 1.25;
    Edge edge3("LAE", "POM");
    edge3.weight = 1.1;
    Edge edge4("GKA", "POM");
    edge4.weight = 10.50;

    testGraph.insertEdge(edge);
    testGraph.insertEdge(edge1);
    testGraph.insertEdge(edge2);
    testGraph.insertEdge(edge3);
    testGraph.insertEdge(edge4);

    Dijkstra dijkstra = Dijkstra(testGraph, "GKA", "POM");

    for (int i = 0; i < dijkstra.path.size(); i++) {
        cout<<dijkstra.path.at(i)<<endl;
    }
    cout<<dijkstra.path_distance<<endl;


    SECTION("Test choose correct distance") {
        REQUIRE(dijkstra.path_distance ==  5.45);
    }
}