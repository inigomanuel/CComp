#ifndef COMPLEJO_H
#define COMPLEJO_H


class Complejo
{
    private:
        double real,complejo;
    public:
        Complejo(double x, double y);
        Complejo suma(Complejo x);
        void imprimir();
};

#endif // COMPLEJO_H
