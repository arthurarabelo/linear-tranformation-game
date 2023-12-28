#ifndef MATRIX_HPP 
#define MATRIX_HPP
#include <iostream>

using namespace std;

//struct do tipo ponto
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
        int rows_; //número de linhas da matriz
        int cols_; //número de colunas da matriz
        long unsigned int p[2][2]; //ponteiro duplo (matriz), cada um com duas caixinhas de memória

    friend class Node;
};

#endif
