#ifndef MATRIX2D
#define MATRIX2D

#include <cmath>
#include <cstdio>
#include "vector.h"

using namespace std;

class Matrix2D {
  protected:
    double *data;
    int n;

  public:
    Matrix2D(int n);
    Matrix2D(char* arr);
    Matrix2D(Matrix2D &other);
    virtual ~Matrix2D();

    int get_N_matr(); // значение размера матрицы
    
    void fill_file(char* arr, int n); // заполнение матрицы из файла
    void fill();
    int size_file(char* arr); // кол-во эл-тов в файле

    
    double sum_strok(int i); // сумма строки матрицы по модулю
    vector mult(Matrix2D C, vector &y);
    
    void print(); // вывод матрицы

    vector operator*(vector &y);
    double* operator[](int i);
    friend ostream &operator<<(ostream &out, Matrix2D &other); // Вывод
};

#endif // MATRIX2D
