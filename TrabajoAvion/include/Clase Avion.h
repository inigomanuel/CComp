#ifndef CLASE AVION_H
#define CLASE AVION_H


class Clase Avion
{
    protected:
        int tamanio;
        int motores;
    public:
        Clase Avion(string t, string mot);
        Clase Avion();
        void getDesc();
        virtual ~Avion();


};

#endif // CLASE AVION_H
