#include "../airport/include/airport.h"
#include "include/node.h"
#include "include/parser.h"
#include "include/graph.h"
#include <iostream>
#include <map>
using std::vector;
using std::cout;
using std::endl;

int main() {
    Parser parser = Parser();
    vector<Node> nodesList;
    vector<Edge> edgesList;
    //USA  airports only
    //parser.InputNodes(nodesList, "../data/USAAirports.csv");
    //All airports
    parser.InputNodes(nodesList, "../data/AirportData.csv");
    parser.InputEdges(edgesList, "../data/RoutesData.csv");
    
    /*Graph testGraph = Graph();

    for (int i = 0; i < 10; i++) {
        testGraph.insertNode(nodesList[i]);
        //cout<<nodesList[i].getData().airportCode_<<endl;
        //cout<<nodesList[i].edges.size()<<endl;
    }

    Edge edge("GKA", "MAG");
    Edge edge1("MAG", "GKA");

    testGraph.insertEdge(edge);
    testGraph.insertEdge(edge1);

    cout<<testGraph.adjacencyMatrix_.size()<<endl;
    cout<<testGraph.adjacencyMatrix_[testGraph.airportToIndexMap.at("GKA")].size()<<endl;

    cout<<testGraph.nodes_[testGraph.airportToIndexMap.at("GKA")].edges.size()<<endl;
    cout<<testGraph.nodes_[testGraph.airportToIndexMap.at("GKA")].edges[0].nodeTwoCode<<endl;
    cout<<testGraph.nodes_[testGraph.airportToIndexMap.at("MAG")].edges.size()<<endl;
    cout<<testGraph.nodes_[testGraph.airportToIndexMap.at("MAG")].edges[0].nodeTwoCode<<endl;*/


    Graph graph(nodesList, edgesList);

    cout<<graph.adjacencyMatrix_[graph.airportToIndexMap.at("ORD")][graph.airportToIndexMap.at("ATL")]<<endl;
    cout<<graph.findNumberOfConnections("ORD")<<endl;
    cout<<graph.edgesCount<<endl;
    cout<<graph.BFS("ORD").size()<<endl;

    for (int i = 0; i < graph.adjacencyMatrix_.size(); i++) {
        for (int j = 0; j < graph.adjacencyMatrix_.size(); j++) {
            if (graph.adjacencyMatrix_[i][j] > 0) {
                cout<<nodesList[i].getData().airportCode_<< "--->" << nodesList[j].getData().airportCode_<<endl;
                cout<<graph.adjacencyMatrix_[i][j]<<endl;
            }
        }
    }
    return 0;
}