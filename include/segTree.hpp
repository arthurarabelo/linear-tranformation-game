#ifndef SEG_TREE_HPP
#define SEG_TREE_HPP
#include <iostream>
#include "node.hpp"

using namespace std;

class SegTree{
    public:
        explicit SegTree(int n);
        ~SegTree();
//        Matrix build(int p, int l, int r);
        Matrix query(int a, int b, int p, int l, int r);
        Matrix MultiplyMatrices(const Matrix &m1, const Matrix &m2);
        Matrix UpdateMatrix(int i, Matrix &newM, int p, int l, int r);
    private:
        int max; //número de instantes
        Node* seg; //vetor que representa a árvore de segmentação
        Matrix id; //matriz identidade
};

#endif
