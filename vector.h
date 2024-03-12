#ifndef VECTOR
#define VECTOR

using namespace std;

class vector {
    protected:
        double *vec;
        int n;

    public:
        vector(int n);
        vector(char* arr);
        vector(vector &other);
        virtual ~vector();

        int get_N_vec(); // значение размера вектора

        void fill_file(char* arr, int n); // заполнение вектора из файла
        void fill();
        int size_file(char* arr); // кол-во эл-тов в файле

        double distance_1(vector x);
        double distance_2(vector x);
        void print(); // вывод матрицы
        
        vector operator-(const vector &other);
        vector &operator=(const vector &other);
        bool operator!=(const vector &other);
        double& operator[](int i);
        friend ostream &operator<<(ostream &out, vector &other);
};

#endif // VECTOR