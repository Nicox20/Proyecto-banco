#ifndef C_MOVIMIENTOS
#define C_MOVIMIENTOS
#include <iostream>
using namespace std;
class Movimiento{
    private:
        string mensaje;
        string fecha;
        string cuenta;
        double monto;
    public:
        Movimiento(string m, string f, string c, double mont){mensaje=m; fecha=f; cuenta=c; monto=mont;}
        string get_mensaje(){return mensaje;}
        string get_fecha(){return fecha;}
        string get_cuenta(){return cuenta;}
        double get_monto(){return monto;}
        void set_mensaje(string m){mensaje=m;}
        void set_fecha(string f){fecha=f;}
        void set_cuenta(string c){cuenta=c;}
        void set_monto(double m){monto=m;}
        void mostrar_transaccion(){
            cout<<endl<<"------------------------------------------------------------------------------"<<endl;
            cout<<"Fecha de la transaccion: "<<fecha<<endl;
            cout<<"Cuenta destino         : "<<cuenta<<endl;
            cout<<"Monto                  : "<<monto<<endl;
            cout<<"Motivo                 : "<<mensaje<<endl;
            cout<<"------------------------------------------------------------------------------"<<endl;

        }
        virtual ~Movimiento(){}
};

#endif 