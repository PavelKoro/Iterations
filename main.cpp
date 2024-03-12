#include <iostream>
#include "file.h"

using namespace std;

int main(int argc, char **argv) {
    char* arr1;
    char* arr2;
    int size = 0;
    double EPS = 0;

    if(argc == 3 || argc == 1) {
        printf("Введите ε: ");
        cin >> EPS;
    } else if(argc > 3) {
        printf("Лишнии файлы!\n");
    } else {
        printf("Недостаточно файлов!\n");
    }

    if(argc == 3) {       
        arr1 = argv[1];
        arr2 = argv[2];

        Matrix2D A(arr1);
        cout << "Матрица А:" << endl;
        cout << A;
        
        vector vec(arr2);
        cout << "Вектор y:" << endl;
        cout << vec;
        cout << endl;

        size = A.get_N_matr();
        iterat tmp(size);

        if(tmp.prov(A)) {
            vector x1(size);
            x1 = tmp.urav(A, vec, EPS);
            cout << "Вектор x1:" << endl;
            cout << x1;
            cout << endl;

            printf("Проверка:\n");
            vector p(size);
            p = A*x1;
            p.print();   
        } else {
            printf("Неправильная матрица A:\n - У диагонали есть не максимальное число!\n");
        }
    } else {
        size = 4;
        Matrix2D A(size);
        A.fill();
        cout << "Матрица А:" << endl;
        cout << A;

        vector vec(size);
        vec.fill();
        cout << "Вектор y:" << endl;
        cout << vec;
        cout << endl;

        iterat tmp(size);
        vector x1(size);
        x1 = tmp.urav(A, vec, EPS);
        cout << "Вектор x1: ";
        cout << x1;
        cout << endl;

        printf("Проверка:\n");
        vector p(size);
        p = A*x1;
        p.print();
    }
    return 0;
}