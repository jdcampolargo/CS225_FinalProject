#pragma once
#include "../airport/include/airport.h"
#include "edge.h"
#include <stdint.h>
#include <string>
#include <vector>

//class Edge;


class Node {
    public:
    std::vector<Edge> edges;

    Node(Airport data);
        
    Airport& getData();

    void setVisited(bool condition);

    bool isVisited();

    bool visited_ = false;

    private:
    Airport data_ = Airport();
};
