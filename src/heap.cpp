#include "heap.hpp"
Heap::Heap(int n) : max(n){
    instants = (Node *) malloc(max*sizeof (Node));
    seg = (Node *) calloc(max*4, sizeof (Node));
}

Heap::~Heap() {
    free(instants);
    free(seg);
}

Matrix Heap::MultiplyMatrices(Matrix m1, Matrix m2) {
    return m1.Multiply(m2);
}

Matrix Heap::build(int p, int l, int r) {
    if(l == r) return seg[p].m = instants[l].m;
    int x = (l+r)/2;
    return seg[p].m = MultiplyMatrices(build(2*p, l, x), build(2*p+1, x+1, r));
}

Matrix Heap::query(int a, int b, int p, int l, int r) {
    Matrix id(2, 2);
    if(b < l || a > r) return id;
    if(a <= l && b >= r) return seg[p].m;
    int x = (l+r)/2;
    return MultiplyMatrices(query(a, b, 2*p, l, x), query(a, b, 2*p+1, x+1, r));
}

void Heap::UpdateMatrix(int inst, Matrix newM) {
    instants[inst].m = newM;
}

