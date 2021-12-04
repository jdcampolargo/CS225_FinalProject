#include "../include/edge.h"
#include "../include/node.h"
#include "../src/node.cpp"
#include "../airport/include/airport.h"
#include <cmath>
#include <string>

Edge::Edge(std::string firstNode, std::string secondNode) {
    node1_ = firstNode;
    node2_ = secondNode;
}