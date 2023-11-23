#ifndef SEG_TREE_HPP
#define SEG_TREE_HPP
#include <iostream>
#include "node.hpp"

using namespace std;

class SegTree{
    public:
        SegTree(int n);
//        Matrix* build(int p, int l, int r);
        Matrix* query(int a, int b, int p, int l, int r);
        Matrix* MultiplyMatrices(Matrix *m1, Matrix *m2);
        Matrix* UpdateMatrix(int i, Matrix *newM, int p, int l, int r);
        ~SegTree();
    private:
        int max;
        Node* seg;
        Matrix queryMatrix;
        Matrix id;
};

#endif
