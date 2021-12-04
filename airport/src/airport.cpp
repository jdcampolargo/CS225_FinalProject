#include "../include/airport.h"

Airport::Airport(){}

Airport::Airport(std::string Name,std::string City, std::string Country, std::string AirportCode, std::string Latitude, std::string Longitude, std::string Altitude) {
  name_ = Name;
  city_ = City;
  country_ = Country;
  airportCode_ = AirportCode;
  latitude_ = Latitude;
  longitude_ = Longitude;
  altitude_ = Altitude;
}


// //Start of Dijkstra's algorithm

// #include <vector>
// #include <limits>
// #include <set>

// using namespace std;

// tuple<int, int> getVertexWithMinDistances(vector<int> minDistances, set<int> distances);
// // O(v^2 + e) time | O(v) space - where v is the number of
// // vertices and e is the number of edges in the input graph

// vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
//   int numberOfVertices = edges.size();
//   vector<int> minDistances(edges.size(), numeric_limits<int>::max());
//   minDistances[start] = 0;
//   set<int> visited;
//   while (visited.size() != numberOfVertices) {
//     auto [vertex, currentMinDistance] =
//         getVertexWithMinDistances(minDistances, visited);
//     if (currentMinDistance == numeric_limits<int>::max()) {
//       break;
//     }
//     visited.insert(vertex);
// for (auto edge : edges[vertex]) {
//       auto destination = edge[0];
//       auto distanceToDestination = edge[1];
//       if (visited.find(destination) != visited.end()) {
//         continue;
//       }
//       auto newPathDistance = currentMinDistance + distanceToDestination;
//       auto currentDestinationDistance = minDistances[destination];
//       if (newPathDistance < currentDestinationDistance) {
//         minDistances[destination] = newPathDistance;
//       }
//     }
//   }
//   vector<int> finalDistances;
//   for (auto distance : minDistances) {
//     if (distance == numeric_limits<int>::max()) {
//       finalDistances.push_back(-1);
//     } else {
//       finalDistances.push_back(distance);
//     }
//   }
//   return finalDistances;

// }
// tuple<int, int> getVertexWithMinDistances(vector<int> distances, set<int> visited) {
	
// 	int currentMinDistance = numeric_limits<int>::max();

//   int vertex = -1;
//   for (int vertexIdx = 0; vertexIdx < distances.size(); vertexIdx++) {

//     int distance = distances[vertexIdx];
//     if (visited.find(vertexIdx) != visited.end()) {
//       continue;
//     }

//     if (distance <= currentMinDistance) {

//       vertex = vertexIdx;

//       currentMinDistance = distance;

//     }
//   }
//   return {vertex, currentMinDistance};
// }
