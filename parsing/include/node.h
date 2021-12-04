#pragma once
#include <stdint.h>
#include <string>


template <class T>
class Node {
    public:
        Node(T data);
        
        T getData();

        void setVisited(bool condition);

        bool isVisited();

    private:
        T data_ = T();
        bool visited_ = false;
};
