#ifndef CLASE_DEBITO
#define CLASE_DEBITO
#include "CTarjetas.h"

class Debito:public Tarjeta
{
    private:
        string tipo;
    public:
        //Constructor para recuperar tarjetas de credito y/o asignar nuevas
        Debito(string n, double d):Tarjeta(n, d),tipo("Debito"){}

        string get_numero(){return numero;}
        double get_saldo(){return saldo;}
        void set_saldo(double mnt){saldo=mnt;}

        void mostrar_datos(){
            cout<<"---------------------------------------------------"<<endl;
            cout.width(20);
            cout<<left<<"|Tipo de tarjeta: ";
            cout.width(30);
            cout<<right<<tipo<<"|"<<endl;

            cout.width(20);
            cout<<left<<"|Numero de tarjeta: ";
            cout.width(30);
            cout<<right<<numero<<"|"<<endl;

            cout.width(20);
            cout<<left<<"|Saldo disponible: ";
            cout.width(30);
            cout<<right<<saldo<<"|"<<endl;
            cout<<"---------------------------------------------------"<<endl<<endl;
        }
        void mod_saldo(double monto){saldo+=monto;}

        Debito &operator=(Debito &origen){
            saldo=origen.saldo;
            numero=origen.numero;
            return *this;
        }

        friend class Menu;
        ~Debito(){}
};
#endif // !1