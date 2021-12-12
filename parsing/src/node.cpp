#include "include/node.h"

using std::string;



Node::Node(Airport data) {
    data_ = data;
}
void Node::setVisited(bool condition) {
    visited_ = condition;
}

bool Node::isVisited() {
            return visited_;
        }

Airport& Node::getData() {
    return data_;
}