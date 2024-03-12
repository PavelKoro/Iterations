#include <iostream>
#include "Matrix2D.h"
#include "vector.h"

vector::vector(int n) {
    this->n = n;
    vec = new double[n];
    for(int i=0; i<n; i++) vec[i]=0;
}

vector::vector(char* arr) {
    this->n = size_file(arr);
    vec = new double[n];
    fill_file(arr, n);
}

vector::vector(vector &other) {
    this->n = other.n;
    vec = new double[n];
    for(int i=0; i<n; i++) vec[i]=other.vec[i];
}

vector::~vector() {
    delete[] vec;
}


int vector::get_N_vec() { return n; }

void vector::fill_file(char* arr, int n) {
    double num = 0;
    FILE* file = fopen(arr, "rb");
    if (file) {
        for(int i=0; i<n; i++) {
            fscanf(file, "%lf", &num);
            vec[i] = num;    
        }
        fclose (file);
    }
}

void vector::fill() {
    (*this)[0] = 11;
    (*this)[1] = 23;
    (*this)[2] = -4;
    (*this)[3] = 8;
}

int vector::size_file(char* arr) {
    int size = 0;
    double num = 0;
    FILE* file = fopen(arr, "rb");
    if (file) {
        while (!feof(file)) {
            fscanf(file, "%lf", &num);    
            size++;
        }
        fclose (file);
    } else{
        size = -1;
    }
    return size;
}

double vector::distance_1(vector x) {
    double result = 0;
    for(int i=0; i<n; i++) {
        result += (vec[i]-x[i])*(vec[i]-x[i]);
    }
    return sqrt(result);
}

double vector::distance_2(vector x) {
    double max = 0;
    double num = 0;
    for(int i=0; i<n; i++) {
        num = vec[i] - x[i];
        if(num < 0) {
            num *= -1;
        }
        if(max < num) {
            max = num;
        }
    }

    return max;
}

void vector::print() {
    for(int i=0; i<n; i++) {
        printf("%9f ", vec[i]);
    }
    printf("\n");
}


vector vector::operator-(const vector &other) {
    vector r(n);
    for(int i=0; i<n; i++) {
        r.vec[i] = vec[i] - other.vec[i];
    }
    return r;
}

vector &vector::operator=(const vector &other) {
    if (this != &other) {
        for(int i=0; i<n; i++) {
            (*this)[i] = other.vec[i];
        }
    }
    return *this;
}

bool vector::operator!=(const vector &other) {
    bool res;
    int count = 0;
    for(int i=0; i<n; i++) {
        if(vec[i] != other.vec[i]) {
            count += 1;
        }
    }
    if(!count) {
        res = true;
    } else {
        res = false;
    }
    return res;
}

double& vector::operator[](int i) {
    return vec[i]; // data + n*i
}

ostream &operator<<(ostream &out, vector &other) {
    other.print();
    return out;
}