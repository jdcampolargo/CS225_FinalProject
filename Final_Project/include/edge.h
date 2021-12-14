#pragma once
#include <string>

class Edge {
    public:
    Edge(std::string firstNode, std::string secondNode);
    std::string nodeOneCode;
    std::string nodeTwoCode;

    double weight;
};