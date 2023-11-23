#include "matrix.hpp"

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols){
    p = new long unsigned int*[rows_];
    for(int i = 0; i < cols_; i++){
        p[i] = new long unsigned int[cols_];
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
    delete[] p;
}

Matrix* Matrix::Multiply(Matrix& m1) {
    unsigned long int x = 100000000;
    auto* result = new Matrix(2,2);
    result->SetAsNull();
    for(int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                result->p[i][j] += (this->p[i][k] * m1.p[k][j]);
            }
            result->p[i][j] = result->p[i][j] % x;
        }
    }
    return result;
}

Point Matrix::LinearTransformation(Point &point) {
    unsigned long int x = point.x;
    unsigned long int y = point.y;
    point.x = (this->p[0][0] * x) + (this->p[0][1] * y);
    point.y = (this->p[1][0] * x) + (this->p[1][1] * y);

    return point;
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

Matrix& Matrix::operator=(const Matrix &m) {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            p[i][j] = m.p[i][j];
        }
    }
    return *this;
}

