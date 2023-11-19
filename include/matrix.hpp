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
        Matrix Multiply(Matrix m1);
        Point MultiplyPoint(Point p);
        ~Matrix();
        void SetAsNull();
        friend std::ostream& operator<<(std::ostream&, const Matrix&);
        friend std::istream& operator>>(std::istream&, Matrix&);

    private:
        int rows_;
        int cols_;
        int **p;

    friend class Node;
};

#endif
