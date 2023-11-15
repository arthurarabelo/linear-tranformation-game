#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>
#include "node.hpp"

using namespace std;

class Heap{
    public:
        Heap(int n);
        Matrix build(int p, int l, int r);
        Matrix query(int a, int b, int p, int l, int r);
        Matrix MultiplyMatrices(Matrix m1, Matrix m2);
        ~Heap();
    private:
        int max;
        Node* instants;
        Node* seg;
};

#endif
