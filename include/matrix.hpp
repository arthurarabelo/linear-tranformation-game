#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>

class Matrix{
    public:
        Matrix(int, int);
        Matrix Multiply(Matrix m1);
        ~Matrix();
    private:
        int rows_;
        int cols_;
        int **p;

    friend class Node;
};

#endif
