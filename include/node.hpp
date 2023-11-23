#ifndef TP3_NODE_HPP
#define TP3_NODE_HPP
#include <iostream>
#include "matrix.hpp"

using namespace std;

class Node{
    public:
        Node();
        ~Node();
    private:
        Matrix*  m;
        bool m_updated{};

    friend class SegTree;
};

#endif