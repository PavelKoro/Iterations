#include <iostream>
#include <cmath>

#include "iterat.h"

iterat::iterat(int n): Matrix2D(n), vector(n) {}
iterat::iterat(iterat &other): Matrix2D(other), vector(other) {}
iterat::~iterat() {}

vector iterat::urav(Matrix2D A, vector y, double EPS) {
    int size = A.get_N_matr();
    Matrix2D C(size);
    vector z = y;

    rest_C(C, A);
    CorrecVec_z(z, A);
    double q = ratio(C);

    C.print();
    z.print();
    printf(" α = %f\n\n", q);
    
    ////////////// х(m+1) = z – Cx
    vector x0 = z;
    vector x1(size);
    
    int i=1;
    while(1) {
        x1 = z - C*x0;
        if(x1.distance_2(x0) < EPS*(1-q)/q) {
            printf("\ni = %d\n", i);
            printf("d2(x(%d), x(%d)) = %f\n", i, i-1, x1.distance_2(x0));
            printf("ε(1–α)/α = %f\n", EPS*(1-q)/q);
            return x1;
        }
        printf("%d: ", i);
        x1.print();
        x0 = x1;
        i += 1;
    }
}

int iterat::prov(Matrix2D A) {
    int count = 0; 
    int size = A.get_N_matr();

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(A[i][i] < A[i][j]) {
                count += 1;
            }
        }
    }

    if(count == 0) {
        return 1;
    } else {
        return 0;
    }
}

void iterat::rest_C(Matrix2D &C, Matrix2D A) {
    int size = A.get_N_matr();
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            C[i][j] = A[i][j]/A[i][i];
        }
    }
    for(int i=0; i<size; i++) {
        C[i][i] = 0;
    }
}

void iterat::CorrecVec_z(vector &z, Matrix2D A) {
    int size = A.get_N_matr();
    for(int i=0; i<size; i++) {
        z[i] = z[i]/A[i][i];
    }
}

double iterat::ratio(Matrix2D C) {
    double q = 0;
    int size = C.get_N_matr();
    for(int i=0; i<size; i++) {
        if(q < C.sum_strok(i)) {
            q = C.sum_strok(i);
        }
    }
    return q;
}
