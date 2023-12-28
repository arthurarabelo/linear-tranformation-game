#ifndef TP3_NODE_HPP 
#define TP3_NODE_HPP
#include <iostream>
#include "matrix.hpp"

using namespace std;

class Node{
    public:
        Node();
    private:
        Matrix  m;
        bool m_updated; //flag que sinaliza se a matriz do nó foi atualizada ou continua como identidade

    friend class SegTree;
};

#endif