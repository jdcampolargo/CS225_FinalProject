#pragma once
#include "node.h"
#include "edge.h"
#include "../airport/include/airport.h"
#include <vector>
#include <map>

class Parser {
    public:
    void InputNodes(std::vector<Node>& airportVector, std::string filename);
    void InputEdges(std::vector<Edge>& edgesVector, std::string filename);
    std::string removeWhiteSpace(std::string& string);
    private:
    std::vector<std::string> CommaSplit(std::string string);
};