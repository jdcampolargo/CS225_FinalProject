#pragma once
#include <string>
#include "../include/node.h"
#include "../airport/include/airport.h"

class Edge {
    public:
    Edge(std::string firstNode, std::string secondNode);
    std::string node1_;
    std::string node2_;
};