#include "../airport/include/airport.h"
#include "include/Dijkstra.h"
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
    //All airports
    parser.InputNodes(nodesList, "../data/AirportData.csv");
    parser.InputEdges(edgesList, "../data/RoutesData.csv");

    

    Graph graph(nodesList, edgesList);

    //cout<<graph.findNumberOfConnections("AYK")<<endl;

    string source; 
    string destination;
    cout << "Type in source airport: "; 
    cin >> source; 
    cout << "Type in your destination: ";
    cin >> destination;

   Dijkstra dijkstra = Dijkstra(graph, source, destination);
    for (int i = 0; i < dijkstra.path.size(); i++) {
        cout<<dijkstra.path.at(i)<<endl;
    }
    cout<<dijkstra.path_distance<<" kilometers"<<endl;
    return 0;
}