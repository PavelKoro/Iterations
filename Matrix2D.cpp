#include <iostream>
#include "Matrix2D.h"
#include "vector.h"

Matrix2D::Matrix2D(int n) {
    this->n = n;
    data = new double[n*n];
    for(int i=0; i<n*n; i++) data[i]=i;
}

Matrix2D::Matrix2D(char* arr) {
    this->n = size_file(arr);
    data = new double[n*n];
    fill_file(arr, n);
}

Matrix2D::Matrix2D(Matrix2D &other) {
    this->n = other.n;
    data = new double[n*n];
    for(int i=0; i<n*n; i++) data[i]=other.data[i];
}

Matrix2D::~Matrix2D() {
    delete[] data;
}

int Matrix2D::get_N_matr() { return n; }

void Matrix2D::fill_file(char* arr, int n) {
    double num = 0;
    FILE* file = fopen(arr, "rb");
    if (file) {
        for(int i=0; i<n*n; i++) {
            fscanf(file, "%lf", &num);
            data[i] = num;    
        }
        fclose (file);
    }
}

void Matrix2D::fill() {
    (*this)[0][0] = 6;
    (*this)[0][1] = 1;
    (*this)[0][2] = -2;
    (*this)[0][3] = 1;

    (*this)[1][0] = 0;
    (*this)[1][1] = 5;
    (*this)[1][2] = 1;
    (*this)[1][3] = 2;

    (*this)[2][0] = 1;
    (*this)[2][1] = -3;
    (*this)[2][2] = 7;
    (*this)[2][3] = -1;

    (*this)[3][0] = 3;
    (*this)[3][1] = 1;
    (*this)[3][2] = 2;
    (*this)[3][3] = 8;
}

int Matrix2D::size_file(char* arr) {
    int size = 0;
    double num = 0;
    FILE* file = fopen(arr, "rb");
    if (file) {
        while (!feof(file)) {
            fscanf(file, "%lf", &num);    
            size++;
        }
        fclose (file);
        size = sqrt(size);
    } else{
        size = -1;
    }
    return size;
}

double Matrix2D::sum_strok(int i) {
    double result = 0;
    for(int j=0; j<n; j++) {
        if((*this)[i][j] < 0) {
            (*this)[i][j] = -1 * (*this)[i][j];
        }
        result += (*this)[i][j];
    }
    return result;
}

vector Matrix2D::mult(Matrix2D C, vector &y) {
    vector r(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            r[i] += C[i][j]*y[j];
        }
    }
    return r;
}

void Matrix2D::print() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%9f ", (*this)[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

vector Matrix2D::operator*(vector &y) {
    vector copy = y;
    copy = mult((*this), copy);
    return copy;
}

double* Matrix2D::operator[](int i) {
    return &(data[n*i]); // data + n*i
}

ostream &operator<<(ostream &out, Matrix2D &other) {
    other.print();
    return out;
}