#include "segTree.hpp"

SegTree::SegTree(int n) : max(n), id(2,2){
    seg = new Node[4 * max];
}

SegTree::~SegTree() {
    delete[] seg;
}

Matrix SegTree::MultiplyMatrices(const Matrix &m1, const Matrix &m2) {
    Matrix r(2,2);
    r = r.Multiply(m1, m2);
    return r;
}


Matrix SegTree::build(int p, int l, int r) {
    if (l == r){
        seg[p].m = id;
        return seg[p].m;
    }
    int x = (l + r) / 2;
    return seg[p].m = MultiplyMatrices(build(2 * p, l, x), build(2 * p + 1, x + 1, r));
}

Matrix SegTree::query(int a, int b, int p, int l, int r) {
    if (b < l || a > r) {
        return id;
    }
    if (a <= l && b >= r) {
        if (!seg[p].m_updated) return id;
        return seg[p].m;
    }
    int x = (l + r) / 2;
    return MultiplyMatrices(query(a, b, 2 * p, l, x),query(a, b, 2 * p + 1, x + 1, r));
}

Matrix SegTree::UpdateMatrix(int i, Matrix &newM, int p, int l, int r) {
    if (i < l || r < i) {
        if (!seg[p].m_updated) return id;
        return seg[p].m;
    }
    if (l == r) {
        seg[p].m_updated = true;
        return seg[p].m = newM;
    }
    int m = (l + r) / 2;
    seg[p].m_updated = true;
    return seg[p].m = MultiplyMatrices(UpdateMatrix(i, newM, 2 * p, l, m),
                                       UpdateMatrix(i, newM, 2 * p + 1, m + 1, r));
}

