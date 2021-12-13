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

TEST_CASE("Test Dijkstra input Nodes") {
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

    SECTION("Test choose correct distance") {
        REQUIRE(int(dijkstra.path_distance * 100) ==  544);
    }

    SECTION("Test correct path") {
        REQUIRE(dijkstra.path.at(0) == "GKA");
        REQUIRE(dijkstra.path.at(1) == "MAG");
        REQUIRE(dijkstra.path.at(2) == "HGU");
        REQUIRE(dijkstra.path.at(3) == "LAE");
        REQUIRE(dijkstra.path.at(4) == "POM");
    }
}

TEST_CASE("Test Dijkstra Parsed Data") {
    Parser parser = Parser();
    vector<Node> nodesList;
    vector<Edge> edgesList;
    parser.InputNodes(nodesList, "../data/AirportData.csv");
    parser.InputEdges(edgesList, "../data/RoutesData.csv");
    Graph graph(nodesList, edgesList);

    Dijkstra dijkstra = Dijkstra(graph, "MNL", "ORD");

    SECTION("Test choose correct distance") {
        REQUIRE(int(dijkstra.path_distance) ==  13124);
    }

    SECTION("Test correct path from Philippines to Chicago") {
        REQUIRE(dijkstra.path.at(0) == "MNL");
        REQUIRE(dijkstra.path.at(1) == "NRT");
        REQUIRE(dijkstra.path.at(2) == "ORD");
        
    }

    Dijkstra dijkstra1 = Dijkstra(graph, "CMI", "SOF");

    SECTION("Test choose correct distance") {
        REQUIRE(int(dijkstra1.path_distance) ==  8583);
    }

    SECTION("Test correct path from Champaign to Bulgaria") {
        REQUIRE(dijkstra1.path.at(0) == "CMI");
        REQUIRE(dijkstra1.path.at(1) == "ORD");
        REQUIRE(dijkstra1.path.at(2) == "AMS");
        REQUIRE(dijkstra1.path.at(3) == "SOF");
    }

    Dijkstra dijkstra2 = Dijkstra(graph, "AYK", "GDV");

    SECTION("Test No Connection Airport") {
        REQUIRE(dijkstra2.path.size() ==  0);
    }
}