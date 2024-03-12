#ifndef ITERAT
#define ITERAT

#include "Matrix2D.h"
#include "vector.h"


class iterat: public Matrix2D, public vector
{
    public:
        iterat(int n);
        iterat(iterat &other);
        virtual ~iterat();
        vector urav(Matrix2D A, vector y, double EPS); // метод итераций
        int prov(Matrix2D A);

    protected:
        void rest_C(Matrix2D &C, Matrix2D A); // C =  D^(–1) * B
        void CorrecVec_z(vector &z, Matrix2D A); // z = vec = D^(–1) * y
        double ratio(Matrix2D C) ; //Коэффициент сжатия

};

#endif // ITERAT