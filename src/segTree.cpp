#include "segTree.hpp"

SegTree::SegTree(int n) : max(n), queryMatrix(2, 2), id(2, 2) {
    seg = new Node[4 * max * sizeof(Node)];
}

SegTree::~SegTree() {
    delete[] seg;
}

Matrix* SegTree::MultiplyMatrices(Matrix *m1, Matrix *m2) {
    return m1->Multiply(*m2);
}

//Matrix* SegTree::build(int p, int l, int r) {
//    if (l == r) return &id;
//    int x = (l + r) / 2;
//    return seg[p].m = MultiplyMatrices(build(2 * p, l, x), build(2 * p + 1, x + 1, r));
//}

Matrix* SegTree::query(int a, int b, int p, int l, int r) {
    if (b < l || a > r) {
        return &id;
    }
    if (a <= l && b >= r) {
        if (!seg[p].m_updated) return &id;
        return seg[p].m;
    }
    int x = (l + r) / 2;
    delete seg[p].m;
    return seg[p].m = MultiplyMatrices(query(a, b, 2 * p, l, x), query(a, b, 2 * p + 1, x + 1, r));
}

Matrix* SegTree::UpdateMatrix(int i, Matrix *newM, int p, int l, int r) {
    if (i < l || r < i) {
        if (!seg[p].m_updated) return &id;
        return seg[p].m;
    }
    if (l == r) {
        if(seg[p].m_updated){
            delete seg[p].m;
        }
        seg[p].m_updated = true;
        seg[p].m = newM;
        return seg[p].m;
    }
    int m = (l + r) / 2;
    delete seg[p].m;
    seg[p].m_updated = true;
    return seg[p].m = (MultiplyMatrices(UpdateMatrix(i, newM, 2 * p, l, m),
                                           UpdateMatrix(i, newM, 2 * p + 1, m + 1, r)));
}

