#include "segTree.hpp"

//construtor: aloca o vetor que representa a árvore de segmentação
SegTree::SegTree(int n) : max(n), id(2,2){
    seg = new Node[4 * max];
}

//destrutor: deleta os nós da árvore de segmentos
SegTree::~SegTree() {
    delete[] seg;
}

//multiplica duas matrizes: chama a função multiply da classe Matrix
Matrix SegTree::MultiplyMatrices(const Matrix &m1, const Matrix &m2) {
    Matrix r(2,2);
    r = r.Multiply(m1, m2);
    return r;
}

//constrói a árvore de segmentação
//Matrix SegTree::build(int p, int l, int r) {
//    if (l == r){
//        seg[p].m = id;
//        return seg[p].m;
//    }
//    int x = (l + r) / 2;
//    return seg[p].m = MultiplyMatrices(build(2 * p, l, x), build(2 * p + 1, x + 1, r));
//}

//faz a consulta para um certo intervalo [a,b]
Matrix SegTree::query(int a, int b, int p, int l, int r) {
    if (b < l || a > r) {
        //se l e r não estiverem contidos no intervalo, retorna identidade: o intervalo [l,r] não deve ser considerado
        return id;
    }
    if (a <= l && b >= r) {
        if (!seg[p].m_updated) {
            //se a matriz não foi atualizada, retorna identidade
            return id;
        }
        return seg[p].m;
    }
    int x = (l + r) / 2;
    return MultiplyMatrices(query(a, b, 2 * p, l, x),query(a, b, 2 * p + 1, x + 1, r));
}

//atualiza a matriz de um certo instante, correspondente à certa folha da árvore de segmentação
Matrix SegTree::UpdateMatrix(int i, Matrix &newM, int p, int l, int r) {
    if (i < l || r < i) {
        if (!seg[p].m_updated){
            //se a matriz não foi atualizada, retorna identidade
            return id;
        }
        return seg[p].m;
    }
    if (l == r) {
        //chegou na folha correspondente ao instante: atualiza a matriz e a flag m_updated
        seg[p].m_updated = true;
        return seg[p].m = newM;
    }
    int m = (l + r) / 2;
    //a flag é aqui atualizada porque as matrizes relacionadas ao instante atualizado também serão por conseguinte atualizadas
    seg[p].m_updated = true;
    return seg[p].m = MultiplyMatrices(UpdateMatrix(i, newM, 2 * p, l, m),
                                       UpdateMatrix(i, newM, 2 * p + 1, m + 1, r));
}

