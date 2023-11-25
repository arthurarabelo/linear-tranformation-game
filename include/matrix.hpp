#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>

using namespace std;

typedef struct point_t{
    long unsigned int x, y;
} Point;

class Matrix{
    public:
        Matrix(int, int);
        Matrix Multiply(const Matrix &m1, const Matrix &m2);
        void LinearTransformation(Point &p);
        ~Matrix();
        void SetAsNull();
        friend std::ostream& operator<<(std::ostream&, const Matrix&);
        friend std::istream& operator>>(std::istream&, Matrix&);
        Matrix& operator=(const Matrix&);

    private:
        int rows_;
        int cols_;
        long unsigned int p[2][2];

    friend class Node;
};

#endif
