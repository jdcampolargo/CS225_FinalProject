#include "../airport/include/airport.h"
#include "include/Dijkstra.h"
#include "include/node.h"
#include "include/parser.h"
#include "include/graph.h"
#include "include/pagerank.h"
#include <iostream>
#include <climits>
#include <map>
using std::vector;
using std::cout;
using std::endl;

int main() {
    cout << "\nSetting up program..." << endl;
    Parser parser = Parser();
    vector<Node> nodesList;
    vector<Edge> edgesList;
    //All airports
    parser.InputNodes(nodesList, "../data/AirportData.csv");
    parser.InputEdges(edgesList, "../data/RoutesData.csv");
    Graph graph(nodesList, edgesList);
    string source;
    string destination;

    PageRank* pr = new PageRank(10, graph);
    pr->updateAdjMatrix(0.85);
    vector<pair<string, double>> ranks = pr->calculateRank(100);
    pr->getMostPopularAirports(pr->pr_);

    int option = -1;

    cout<<"Enter 0 to quit"<<endl;
    cout<<"Enter 1 for finding shortest route"<<endl;
    cout<<"Enter 2 for shortest path to nearest popular airport"<<endl;

    while (option != 0) {
    cout << "Option #: ";
    cin >> option; 

    if (option == 1) {
        cout << "Type in source airport: "; 
        cin >> source; 
        cout << "Type in your destination: ";
        cin >> destination;

        Dijkstra dijkstra1 = Dijkstra(graph, source, destination);

        for (int i = 0; i < dijkstra1.path.size(); i++) {
            cout<<graph.nodes_[graph.airportToIndexMap[dijkstra1.path.at(i)]].getData().name_<<endl;
        }
        cout<<dijkstra1.path_distance<<" kilometers"<<endl;

    } else if (option == 2) {
        int shortest = INT_MAX;
        vector<string> path;
        cout << "Type in source airport: "; 
        cin >> source; 
        cout << "Performing calculations..." << endl;

        for (int i = 0; i < pr->mostPopularAirports.size(); i++) {
            Dijkstra dijkstra = Dijkstra(graph, source, pr->mostPopularAirports[i]);
            if (dijkstra.path_distance < shortest) {
                shortest = dijkstra.path_distance;
                path = dijkstra.path;
            }
        }

        for (string part : path) {
            cout<<graph.nodes_[graph.airportToIndexMap[part]].getData().name_<<endl;
        }
    }
}    
    return 0;
}