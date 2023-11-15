#include "matrix.hpp"

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols){
    p = new int*[rows_];
    for(int i = 0; i < cols_; i++){
        p[i] = new int[cols_];
    }
    for(int i = 0; i < rows_; i++){
        for(int j = 0; j < cols_; j++){
            if(i == j) {
                p[i][j] = 1;
                continue;
            }
            p[i][j] = 0;
        }
    }
}

Matrix::~Matrix(){
    for(int i = 0; i < cols_; i++){
        delete[] p[i];
    }
    delete p;
}

Matrix Matrix::Multiply(Matrix m1) {
    Matrix temp(rows_, m1.cols_);
    for (int i = 0; i < temp.rows_; ++i) {
        for (int j = 0; j < temp.cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                temp.p[i][j] += (p[i][k] * m1.p[k][j]);
            }
        }
    }
    return temp;
}

