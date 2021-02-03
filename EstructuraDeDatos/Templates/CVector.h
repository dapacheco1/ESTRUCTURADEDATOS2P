// CVector.h
#ifndef CVECTOR_H
#define CVECTOR_H

class CVector
{
    public:
        CVector(int, int);
        virtual ~CVector();
        bool operator > (CVector v);
        int GetX() {return x;}
        int GetY() {return y;}
    protected:
        float x, y;
    private:
};

#endif // CVECTOR_H
