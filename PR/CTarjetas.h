#ifndef CLASE_TARJETA
#define CLASE_TARJETA

#include <iostream>
#include <string>
#include <random>
#include <time.h>
using namespace std;

class Tarjeta
{
    protected:
        string numero;
        double saldo;
    public:
        //Constructor para recuperar tarjetas previas
        Tarjeta(string n, double d):numero(n),saldo(d){}
        //Tarjeta(&Tarjeta t_elim):
        //{}

        //Constructor para nueva tarjeta
        //Definicion de funciones virtuales
        //Imprimir datos no editables
        virtual string get_numero()=0;

        //Getter dinero
        virtual double get_saldo()=0;

        virtual void mostrar_datos()=0;

        virtual void mod_saldo(double monto)=0;

        virtual void set_saldo(double mnt)=0;


        //Destructor de tarjetas
        virtual ~Tarjeta(){}

};
#endif