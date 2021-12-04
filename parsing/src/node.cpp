#include "../include/node.h"

using std::string;


template <class T>
Node<T>::Node(T data) {
    data_ = data;
}
template <class T>
void Node<T>::setVisited(bool condition) {
    visited_ = true;
}

template <class T>
bool Node<T>::isVisited() {
            return visited_;
        }

template <class T>
T Node<T>::getData() {
    return data_;
}