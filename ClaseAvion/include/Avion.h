#ifndef CLASE AVION_H
#define CLASE AVION_H


class Avion
{
    protected:
        int tamanio;
        int motores;
        int estado;
    public:
        Avion(int t, int mot, int estado);
        Avion();
        void getDesc();


};

#endif // CLASE AVION_H
