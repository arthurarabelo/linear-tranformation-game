#include "matrix.hpp"

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
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

Matrix::~Matrix()= default;

Matrix Matrix::Multiply(const Matrix &m1, const Matrix &m2) {
    unsigned long int x = 100000000;
    Matrix c(2,2);
    c.SetAsNull();
    for(int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                c.p[i][j] += m1.p[i][k] * m2.p[k][j];
            }
        c.p[i][j] = c.p[i][j] % x;
        }
    }
    return c;
}

void Matrix::LinearTransformation(Point &point) {
    unsigned long int x = point.x;
    unsigned long int y = point.y;
    point.x = (this->p[0][0] * x)  + (this->p[0][1] * y);
    point.y = (this->p[1][0] * x) + (this->p[1][1] * y);
}

istream& operator>>(istream& is, Matrix& m) {
    for (int i = 0; i < m.rows_; ++i) {
        for (int j = 0; j < m.cols_; ++j) {
            is >> m.p[i][j];
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Matrix& m) {
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

