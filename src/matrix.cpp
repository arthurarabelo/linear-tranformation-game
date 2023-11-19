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
    temp.SetAsNull();
    for(int i = 0; i < temp.rows_; ++i) {
        for (int j = 0; j < temp.cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                temp.p[i][j] += (p[i][k] * m1.p[k][j]);
            }
        }
    }
    return temp;
}

Point Matrix::MultiplyPoint(Point point) {
    Point result;
    for(int i = 0; i < this->cols_; i++){
        result.x += this->p[0][i] * point.x;
    }
    for(int j = 0; j < this->cols_; j++){
        result.y += this->p[1][j] * point.y;
    }
    return result;
}

istream& operator>>(istream& is, Matrix& m)
{
    for (int i = 0; i < m.rows_; ++i) {
        for (int j = 0; j < m.cols_; ++j) {
            is >> m.p[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Matrix& m)
{
    for (int i = 0; i < m.rows_; ++i) {
        os << m.p[i][0];
        for (int j = 1; j < m.cols_; ++j) {
            os << " " << m.p[i][j];
        }
        os << endl;
    }
    return os;
}

void Matrix::SetAsNull() {
    for(int i = 0; i < this->rows_; i++){
        for(int j = 0; j < this->cols_; j++){
            this->p[i][j] = 0;
        }
    }
}

