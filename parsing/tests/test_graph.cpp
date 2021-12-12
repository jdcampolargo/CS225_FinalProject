#include "catch2/catch.hpp"
#include "../airport/include/airport.h"
#include "include/node.h"
#include "include/parser.h"
#include "include/graph.h"
#include <iostream>
#include <map>
using std::vector;
using std::cout;
using std::endl;


TEST_CASE("Test Data Parsing") {
    Parser parser = Parser();
    vector<Node> nodesList;
    vector<Edge> edgesList;
    parser.InputNodes(nodesList, "../data/AirportData.csv");
    parser.InputEdges(edgesList, "../data/RoutesData.csv");
    
    Graph graph(nodesList, edgesList);
    /*std::cout<<graph.adjacencyMatrix_[graph.airportToIndexMap.at("ORD")][graph.airportToIndexMap.at("ATL")]<<std::endl;
    std::cout<<graph.findNumberOfConnections("ORD")<<std::endl;
    std::cout<<graph.edgesCount<<std::endl;
    std::cout<<graph.BFS("ORD").size()<<std::endl;*/
    SECTION("Test Node Parsing", "[nodes]") {
        REQUIRE(nodesList.size() == 6072);
    }

    SECTION("Test Node Parsing: first Node", "[nodes]") {
        REQUIRE(nodesList.at(0).getData().airportCode_ == "GKA");
    }

    SECTION("Test Node Parsing: inbetween Node", "[nodes]") {
        REQUIRE(nodesList.at(200).getData().airportCode_ == "ZFM");
    }

    SECTION("Test Node Parsing: Last Node", "[nodes]") {
        REQUIRE(nodesList.at(6071).getData().airportCode_ == "CPO");
    }

    SECTION("Test Edge Parsing", "[nodes]") {
        REQUIRE(edgesList.size() == 67657);
    }

    SECTION("Test Edge Parsing: first Edge", "[nodes]") {
        REQUIRE((edgesList.at(0).nodeOneCode == "AER" && edgesList.at(0).nodeTwoCode == "KZN"));
    }

    SECTION("Test Edge Parsing: InBetween Edge", "[nodes]") {
        REQUIRE((edgesList.at(28777).nodeOneCode == "POA" && edgesList.at(28777).nodeTwoCode == "FLN"));
    }

    SECTION("Test Edge Parsing: Last Edge", "[nodes]") {
        REQUIRE((edgesList.at(67656).nodeOneCode == "OSS" && edgesList.at(67656).nodeTwoCode == "FRU"));
    }
}

TEST_CASE("Graph Insert Node") {
    Parser parser = Parser();
    vector<Node> nodesList;
    vector<Edge> edgesList;
    parser.InputNodes(nodesList, "../data/AirportData.csv");
    parser.InputEdges(edgesList, "../data/RoutesData.csv");

    Graph testGraph = Graph();
    //add initial nodes
    for (int i = 0; i < 4; i++) {
        testGraph.insertNode(nodesList[i]);
    }

    SECTION("Check node insertion is correct") {
        REQUIRE(nodesList.at(0).getData().airportCode_ == "GKA");
    }

    SECTION("Check node insertion is correct") {
        REQUIRE(nodesList.at(4).getData().airportCode_ == "POM");
    }

    SECTION("Check Matrix Size is correct") {
        REQUIRE(testGraph.adjacencyMatrix_.size() == 4);
        REQUIRE(testGraph.adjacencyMatrix_[0].size() == 4);
    }
    //add rest of nodes
    for (int i = 4; i < 10; i++) {
        testGraph.insertNode(nodesList[i]);
    }

    SECTION("Check node insertion is correct") {
        REQUIRE(nodesList.at(9).getData().airportCode_ == "THU");
    }

    SECTION("Check Matrix Size is correct") {
        REQUIRE(testGraph.adjacencyMatrix_.size() == 10);
        REQUIRE(testGraph.adjacencyMatrix_[0].size() == 10);
    }
    
}

TEST_CASE("Graph Insert Edge") {
    Parser parser = Parser();
    vector<Node> nodesList;
    vector<Edge> edgesList;
    parser.InputNodes(nodesList, "../data/AirportData.csv");
    parser.InputEdges(edgesList, "../data/RoutesData.csv");

    Graph testGraph = Graph();
    for (int i = 0; i < 10; i++) {
        testGraph.insertNode(nodesList[i]);
    }

    Edge edge("GKA", "MAG");
    Edge edge1("MAG", "GKA");

    testGraph.insertEdge(edge);
    testGraph.insertEdge(edge1);


    SECTION("Insert Edge") {
        REQUIRE(testGraph.nodes_[testGraph.airportToIndexMap.at("GKA")].edges.size() == 1);
        REQUIRE(testGraph.nodes_[testGraph.airportToIndexMap.at("MAG")].edges.size() == 1);
        REQUIRE(testGraph.nodes_[testGraph.airportToIndexMap.at("GKA")].edges[0].nodeTwoCode == "MAG");
        REQUIRE(testGraph.nodes_[testGraph.airportToIndexMap.at("MAG")].edges[0].nodeTwoCode == "GKA");
    }
}

TEST_CASE("Test BFS") {
    Parser parser = Parser();
    vector<Node> nodesList;
    vector<Edge> edgesList;
    parser.InputNodes(nodesList, "../data/AirportData.csv");
    parser.InputEdges(edgesList, "../data/RoutesData.csv");

    Graph testGraph = Graph();
    for (int i = 0; i < 10; i++) {
        testGraph.insertNode(nodesList[i]);
    }

    testGraph.insertEdge(Edge("GKA", "MAG"));
    testGraph.insertEdge(Edge("MAG", "GKA"));

    SECTION("BFS TEST 2 components") {
        REQUIRE(testGraph.BFS("GKA").size() == 2);
    }
    
    testGraph.insertEdge(Edge("MAG", "HGU"));

    SECTION("BFS TEST 3 components") {
        REQUIRE(testGraph.BFS("GKA").size() == 3);
    }

    testGraph.insertEdge(Edge("HGU", "GKA"));

    SECTION("BFS TEST 2 paths to same node") {
        REQUIRE(testGraph.BFS("GKA").size() == 3);
    }

    testGraph.insertEdge(Edge("GKA", "SFJ"));

    SECTION("BFS TEST 4 components") {
        REQUIRE(testGraph.BFS("GKA").size() == 4);
    }

    SECTION("BFS TEST 2 components") {
        REQUIRE(testGraph.BFS("GKA").size() == 4);
    }
}