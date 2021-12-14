#include "catch2/catch.hpp"
#include "include/Dijkstra.h"
#include "../airport/include/airport.h"
#include "include/node.h"
#include "include/parser.h"
#include "include/graph.h"
#include "include/pagerank.h"
#include <iostream>
#include <map>
using std::vector;
using std::cout;
using std::endl;

//Manual testing done on full dataset 

TEST_CASE("Test PageRank matrix") {
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

    PageRank* pr = new PageRank(3, testGraph);
    pr->updateAdjMatrix(0.85);
    
    REQUIRE((int)(pr->adjacency_matrix_[0][0]*1000) == 15);
    REQUIRE((int)(pr->adjacency_matrix_[0][1]*1000) == 15);
}

TEST_CASE("Testing PageRank on subset of US airports") { 
    Parser parser = Parser();
    vector<Node> nodesList;
    parser.InputNodes(nodesList, "../data/USAAirports.csv");

    Graph testGraph = Graph();
    for (int i = 0; i < 10; i++) {
        testGraph.insertNode(nodesList[i]);
    }

    Edge edge("ORD", "BTI");
    edge.weight = 1.5;
    Edge edge1("FRN", "LUR");
    edge1.weight = 1.6;
    Edge edge2("FRN", "SVW");
    edge2.weight = 1.25;
    Edge edge3("SVW", "BMX");
    edge3.weight = 1.1;
    Edge edge4("SVW", "BYS");
    edge4.weight = 10.50;

    testGraph.insertEdge(edge);
    testGraph.insertEdge(edge1);
    testGraph.insertEdge(edge2);
    testGraph.insertEdge(edge3);
    testGraph.insertEdge(edge4);

    PageRank* pr = new PageRank(3, testGraph);
    pr->updateAdjMatrix(0.85);
    vector<pair<string, double>> ranks = pr->calculateRank(100);
    pr->getMostPopularAirports(pr->pr_);
    REQUIRE(pr->mostPopularAirports[0] == "SVW");
    REQUIRE(pr->mostPopularAirports[1]  == "LUR");
    REQUIRE(pr->mostPopularAirports[2]  == "FRN");
}