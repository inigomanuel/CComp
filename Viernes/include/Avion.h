#ifndef CLASE AVION_H
#define CLASE AVION_H


class Avion
{
    protected:
        int tamanio;
        int motores;
    public:
        Avion(int t, int mot);
        Avion();
        void getDesc();
        virtual ~Avion();


};

#endif // CLASE AVION_H
