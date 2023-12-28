#include "matrix.hpp" 

//construtor: inicializa a matriz como identidade
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

//destrutor: como não há memória alocada para a matriz, não é preciso dar nenhum free ou delete
Matrix::~Matrix()= default;

//multiplicação: cria matriz resultado, a transforma em nula e, feito os cálculos, a retorna
Matrix Matrix::Multiply(const Matrix &m1, const Matrix &m2) {
    unsigned long int x = 100000000;
    Matrix c(2,2);
    c.SetAsNull();
    for(int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            for (int k = 0; k < cols_; ++k) {
                c.p[i][j] += m1.p[i][k] * m2.p[k][j];
            }
        c.p[i][j] = c.p[i][j] % x; //coloca na matriz resultado apenas os últimos 8 dígitos caso o número tenha mais algarismos que 8
        }
    }
    return c;
}

//transformação linear:o parâmetro ponto é passado como referência e muda seus valores
void Matrix::LinearTransformation(Point &point) {
    unsigned long int x = point.x;
    unsigned long int y = point.y;
    point.x = (this->p[0][0] * x)  + (this->p[0][1] * y);
    point.y = (this->p[1][0] * x) + (this->p[1][1] * y);
}

//sobrecarga do operador >> para a leitura da matriz
istream& operator>>(istream& is, Matrix& m) {
    for (int i = 0; i < m.rows_; ++i) {
        for (int j = 0; j < m.cols_; ++j) {
            is >> m.p[i][j];
        }
    }
    return is;
}

//sobrecarga do operador << para imprimir a matriz
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

//função que atribui a todos os elementos da matriz o número 0: utilizada na multiplicação
void Matrix::SetAsNull() {
    for(int i = 0; i < this->rows_; i++){
        for(int j = 0; j < this->cols_; j++){
            this->p[i][j] = 0;
        }
    }
}

//sobrecarga do operador =
Matrix& Matrix::operator=(const Matrix &m) {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            p[i][j] = m.p[i][j];
        }
    }
    return *this;
}

