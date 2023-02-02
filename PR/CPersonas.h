#ifndef CLASE_PERSONA
#define CLASE_PERSONA
#include <iostream>
#include <vector>
#include <string>
#include "CDebito.h"
#include "CTarjetas.h"
#include "CMovimientos.h"
#include "CPrestamos.h"
#include "libgame.h"
#include <ctime>
using namespace std;


class Persona
        {
    //-----------------ATRIBUTOS-----------------
    private:
        string nombres;
        string apellido_paterno;
        string apellido_materno;
        string telefono;
        string direccion;
        string dni;
        string correo;
        vector<Tarjeta*> tarjetas;
        vector<Movimiento*> transacciones;
        Prestamo* p1;

    //-----------------ATRIBUTOS-----------------

    public:
        //-----------------------------------Constructor para registrar unicamente personas nuevas-----------------------------------
        Persona()
        {
            p1=new Prestamo(nombres,apellido_paterno,apellido_materno,dni);
            string _nombres,_apellido_paterno,_apellido_materno,_telefono,_direccion,_dni,_correo;
            cout<<endl<<endl;
            /*cout<<"#####  ######  ####  #  ####  ##### #####   ####         ####  #      # ###### #    # ##### ######"<<endl;
            cout<<"#    # #      #    # # #        #   #    # #    #       #    # #      # #      ##   #   #   #"<<endl;
            cout<<"#    # #####  #      #  ####    #   #    # #    # ##### #      #      # #####  # #  #   #   #####"<<endl;
            cout<<"#####  #      #  ### #      #   #   #####  #    #       #      #      # #      #  # #   #   #"<<endl;
            cout<<"#    # ######  ####  #  ####    #   #    #  ####         ####  ###### # ###### #    #   #   ######"<<endl;
             */
            cin.ignore();
            Color(AZUL);
            cout<<"----------------------INGRESE SUS DATOS----------------------"<<endl;
            Color(PLATA);
            cout<<"\n   Nombres: ";getline(cin,_nombres);
            cout<<"\n   Apellido paterno : "; getline(cin,_apellido_paterno);
            cout<<"\n   Apellido materno : "; getline(cin,_apellido_materno);
            //VALIDAR DNI
            cout<<"\n   DNI : "; getline(cin,_dni);
            while (_dni.length()!=8)
            {
            Color(ROJO);
            cout<<"\n         DNI INVALIDO, INGRESE DNI NUEVAMENTE "<<endl;
            Color(PLATA);
            cout<<"\n   DNI : "; getline(cin,_dni);
            }

            //VALIDAR TELEFONO
            cout<<"\n   Telefono : "; getline(cin,_telefono);
            while(_telefono.length()!=9)
            {
                Color(ROJO);
                cout<<"\n         TELEFONO INVALIDO"<<endl;
                Color(PLATA);
                cout<<"\n   Telefono : "; getline(cin,_telefono);
            }
            cout<<"\n   Direccion: "; getline(cin,_direccion);
            cout<<"\n   Correo electronico : "; getline(cin,_correo);
            nombres=_nombres;
            apellido_materno=_apellido_materno;
            apellido_paterno=_apellido_paterno;
            telefono=_telefono;
            direccion=_direccion;
            dni=_dni;
            correo=_correo;
            //cout<<"\nLos datos del cliente se han registrado exitosamente.\n";
            //cout<<"Al ser nuevo cliente, se le asigna automaticamente una nueva tarjeta.\n";
            string numero;
            //Crear nuevo numero de tarjeta:
            int s1,s2,s3,s4;
            srand(time(nullptr));
            s1=1000+(rand()%9000);
            s2=1000+(rand()%9000);
            s3=1000+(rand()%9000);
            s4=1000+(rand()%9000);
            numero=to_string(s1) + to_string(s2) + to_string(s3) + to_string(s4);
            tarjetas.push_back(new Debito(numero,0.0));
            cout<<"\n   Su numero de tarjeta es: ";
            Color(VERDE);
            cout<<numero<<endl;
            Color(AZUL);
            cout<<"\n              DATOS DEL CLIENTE REGISTRADO CON EXITO"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<endl<<endl;

        };
        //-----------------------------------Constructor para registrar unicamente personas nuevas-----------------------------------


        //-----------------------------Constructor para recuperar los clientes previos---------------------------------------
        Persona(string n, string ap, string am, string tl, string dr, string id, string corr):nombres(n),apellido_paterno(ap),apellido_materno(am),telefono(tl),direccion(dr),dni(id),correo(corr),p1(new Prestamo(nombres,apellido_paterno,apellido_materno,dni)){}
        //-----------------------------Constructor para recuperar los clientes previos---------------------------------------


        //Setters
        void set_nombre(string n){nombres=n;}
        void set_apellido_paterno(string n){apellido_paterno=n;}
        void set_apellido_materno(string n){apellido_materno=n;}
        void set_telefono(string n){telefono=n;}
        void set_direccion(string n){direccion=n;}
        void set_dni(string n){dni=n;}
        void set_correo(string n){correo=n;}

        //Getters
        string get_nombre(){return nombres;}
        string get_apellido_paterno(){return apellido_paterno;}
        string get_apellido_materno(){return apellido_materno;}
        string get_telefono(){return telefono;}
        string get_direccion(){return direccion;}
        string get_dni(){return dni;}
        string get_correo(){return correo;}
        double get_deuda_total(){return p1->get_prestamo_total();}
        double get_intereses(){return p1->get_intereses();}
        vector<string> get_tarjetas(){
            vector<string> temporal;
            for(const auto&i:tarjetas){temporal.push_back(i->get_numero());}
            return temporal;
        }
        vector<double> get_monto_tarjeta(){
            vector<double> temporal;
            for(const auto&i:tarjetas){temporal.push_back(i->get_saldo());}
            return temporal;
        }
        //Imprimir datos del cliente
        void imprimir_datos()
        {
            cout<<"-------------------------------------------------------------"<<endl;
            cout.width(20);
            cout<<left<<"|Nombre(s): ";
            cout.width(40);
            cout<<right<<nombres<<"|"<<endl;

            cout.width(20);
            cout<<left<<"|Apellido paterno: ";
            cout.width(40);
            cout<<right<<apellido_paterno<<"|"<<endl;
            
            cout.width(20);
            cout<<left<<"|Apellido materno: ";
            cout.width(40);
            cout<<right<<apellido_materno<<"|"<<endl;

            cout.width(20);
            cout<<left<<"|DNI: ";
            cout.width(40);
            cout<<right<<dni<<"|"<<endl;

            cout.width(20);
            cout<<left<<"|Telefono: ";
            cout.width(40);
            cout<<right<<telefono<<"|"<<endl;

            cout.width(20);
            cout<<left<<"|Direccion: ";
            cout.width(40);
            cout<<right<<direccion<<"|"<<endl;

            cout.width(21);
            cout<<left<<"|Correo electronico: ";
            cout.width(39);
            cout<<right<<correo<<"|"<<endl;

            cout.width(26);
            cout<<left<<"|<<<Tarjetas afiliadas>>>";
            cout.width(35);
            cout<<right<<"<<<Monto>>>|"<<endl;
            for(const auto&i:tarjetas){
                    cout.width(10);
                    cout<<left<<i->get_numero();
                    cout.width(40);
                    cout<<right<<i->get_saldo()<<endl;
            }
            cout<<"-------------------------------------------------------------"<<endl<<endl;
        }

        //Mostrar todas las tarjetas afiliadas
        void mostrar_tarjetas()
        {
            for(const auto& i:tarjetas){i->mostrar_datos();}
        }

        //Obtener dinero total
        double get_monto_total()
        {
            double money;
            for(const auto&i:tarjetas)
            {
                money+=i->get_saldo();
            }
            return money;
        }

        //Obtener total de tarjetas existentes
        int get_total_tarjetas(){return tarjetas.size();}

        //--------------------------------------------------Agregar nueva tarjeta-------------------------------------------------
        void agregar_tarjeta()
        {
            string numero;
            //Crear nuevo numero de tarjeta:
            int s1,s2,s3,s4;
            srand(time(nullptr));
            s1=1000+(rand()%9000);
            s2=1000+(rand()%9000);
            s3=1000+(rand()%9000);
            s4=1000+(rand()%9000);
            numero=to_string(s1) + to_string(s2) + to_string(s3) + to_string(s4);
            tarjetas.push_back(new Debito(numero,0.0));
            tarjetas[0]+50;
            cout<<endl<<"Gracias por afiliarse a una nueva tarjeta!!!\nEste es su nuevo numero de tarjeta: "<<numero<<endl;
        }
        //--------------------------------------------------Agregar nueva tarjeta-------------------------------------------------

        //--------------------------------------------------Recuperar tarjetas-------------------------------------------------
        void recuperar_tarjeta(vector<string> tar, vector<double> money)
        {
            for(int i=0;i<tar.size();i++){tarjetas.push_back(new Debito(tar[i],money[i]));}
        }
        //--------------------------------------------------Recuperar tarjetas-------------------------------------------------


        //Bloquear nueva tarjeta
        void bloquear_tarjeta()
        {
            string n;
            bool v=false;
            cout<<"Las tarjetas que tiene disponible son las siguientes: "<<endl;
            for (const auto& i:tarjetas){cout<<"-"<<i->get_numero()<<endl;}
            cout<<endl<<"Ingrese el numero de la tarjeta a bloquear: "; cin>>n;
            for(int i=0;i<tarjetas.size();i++){
                if(n==tarjetas[i]->get_numero()){
                    v=true;
                    char ot;
                    do{cout<<"¿Esta seguro de bloquear la tarjeta "<<tarjetas[i]->get_numero()<<"? (S/N) -> "; cin>>ot;}
                    while((ot!='S') and (ot!='N'));
                    if(ot=='S'){

                        string numero;
                        //Crear nuevo numero de tarjeta:
                        int s1,s2,s3,s4;
                        srand(time(nullptr));
                        s1=1000+(rand()%9000);
                        s2=1000+(rand()%9000);
                        s3=1000+(rand()%9000);
                        s4=1000+(rand()%9000);
                        numero=to_string(s1) + to_string(s2) + to_string(s3) + to_string(s4);
                        auto reemplazo=new Debito(numero,tarjetas[i]->get_saldo());
                        tarjetas[i]=reemplazo;
                        cout<<"\nFelicidades, su tarjeta anterior se ha bloqueado exitosamente.\n";
                        cout<<"Ahora se le ha asignado una nueva tarjeta. Su nuevo numero es: "<<tarjetas[i]->get_numero()<<endl;
                        cout<<"El saldo actual de la tarjeta es: "<<tarjetas[i]->get_saldo()<<endl<<endl;
                        //delete tarjetas[i];
                        //tarjetas[i]=nullptr;
                        //tarjetas.erase(tarjetas.begin()+i);
                        //cout<<"Tarjeta eliminada con exito"<<endl;
                        //system("pause");
                        //system("cls");
                    }
                    else{
                        cout<<"\nOperacion cancelada con exito.\n";
                    //system("pause");
                    //system("cls");
                    }
                break;
                }
            }
            if(v==false){cout<<endl<<"La tarjeta ingresada no esta registrada a su nombre."<<endl;}
        }

        //--------------------------------------Metodo para depositar-----------------------------------------------------
        void depositar()
        {
            string n;
            bool v=false;
            cout<<"Las tarjetas que tiene disponible para deposito son las siguientes: "<<endl;
            for (const auto& i:tarjetas){cout<<"-"<<i->get_numero()<<endl;}
            cout<<endl<<"Ingrese el numero de la tarjeta para hacer el deposito: "; cin>>n;
            for(int i=0;i<tarjetas.size();i++){
                if(n==tarjetas[i]->get_numero()){
                    string mensaje,fecha;
                    v=true;
                    double ot;
                    do{cout<<"Ingrese el monto a depositar a la tarjeta "<<tarjetas[i]->get_numero()<<" (Mayor a S/. 10) -> "; cin>>ot;}
                    while(ot<10);
                    cin.ignore();
                    cout<<"Ingrese el motivo de la operacion: "; getline(cin,mensaje);

                    //----------------------------Obtener fechas para adjuntarlos en un string------------------------------------
                    time_t t = time(nullptr);
                    tm* now = localtime(&t);
                    fecha=to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
                    //----------------------------Obtener fechas para adjuntarlos en un string------------------------------------

                    //-----------------------------Agregar una nueva transaccion-----------------------------------
                    transacciones.push_back(new Movimiento(mensaje,fecha,tarjetas[i]->get_numero(),ot));
                    //-----------------------------Agregar una nueva transaccion-----------------------------------
                    
                    tarjetas[i]->mod_saldo(ot);
                    cout<<"\nFelicidades, ha depositado S/. "<<ot<<" a la tarjeta "<<tarjetas[i]->get_numero()<<endl;
                    cout<<"Ahora usted cuenta con S/. "<<tarjetas[i]->get_saldo()<<" en esa tarjeta."<<endl;
                    cout<<"Puede verificar su transaccion desde el apartado de 'Mostrar historial de transacciones'."<<endl;
                    break;
                }
            }
            if(v==false){cout<<endl<<"La tarjeta ingresada no esta registrada a su nombre."<<endl;}
        }
        //--------------------------------------Metodo para depositar-----------------------------------------------------

        //--------------------------------------Metodo para retirar-----------------------------------------------------
        void retirar()
        {
            string n;
            bool v=false;
            cout<<"Las tarjetas que tiene disponible para retiro son las siguientes: "<<endl;
            for (const auto& i:tarjetas){cout<<"-"<<i->get_numero()<<endl;}
            cout<<endl<<"Ingrese el numero de la tarjeta para hacer el retiro: "; cin>>n;
            for(int i=0;i<tarjetas.size();i++){
                if(n==tarjetas[i]->get_numero()){
                    string mensaje,fecha;
                    v=true;
                    double ot;
                    do{cout<<"Ingrese el monto a retirar a la tarjeta "<<tarjetas[i]->get_numero()<<" (Mayor a S/. 10) -> "; cin>>ot;}
                    while(ot<10);
                    if(tarjetas[i]->get_saldo()-ot<=0){
                        cout<<"No existen fondos suficientes en la tarjeta."<<endl;
                        break;
                    }
                    else{
                        cin.ignore();
                        cout<<"Ingrese el motivo de la operacion: "; getline(cin,mensaje);

                        //----------------------------Obtener fechas para adjuntarlos en un string------------------------------------
                        time_t t = time(nullptr);
                        tm* now = localtime(&t);
                        fecha=to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
                        cout<<now->tm_mon + 5;
                        //----------------------------Obtener fechas para adjuntarlos en un string------------------------------------

                        //-----------------------------Agregar una nueva transaccion-----------------------------------
                        transacciones.push_back(new Movimiento(mensaje,fecha,tarjetas[i]->get_numero(),(ot*(-1))));
                        //-----------------------------Agregar una nueva transaccion-----------------------------------
                    
                        tarjetas[i]->mod_saldo((-1)*ot);
                        cout<<"\nFelicidades, ha retirado S/. "<<ot<<" de la tarjeta "<<tarjetas[i]->get_numero()<<endl;
                        cout<<"Ahora usted cuenta con S/. "<<tarjetas[i]->get_saldo()<<" en esa tarjeta."<<endl;
                        cout<<"Puede verificar su transaccion desde el apartado de 'Mostrar historial de transacciones'."<<endl;
                        break;
                    }
                    
                }
            }
            if(v==false){cout<<endl<<"La tarjeta ingresada no esta registrada a su nombre."<<endl;}
        }
        //--------------------------------------Metodo para retirar-----------------------------------------------------

        //---------------------------------Metodo para mostrar transacciones recientes-----------------------------------
        void mostrar_historial_transacciones(){
            if(transacciones.size()<=0){
                cout<<"\nNo existen transacciones previas existentes.\n\n";
            }
            else{
                for(const auto &i:transacciones){
                    i->mostrar_transaccion();
                }
            }
        }
        //---------------------------------Metodo para mostrar transacciones recientes-----------------------------------

        void pedir_prestamo(){
            p1->pedir_prestamo();
        }

        void cancelar_prestamo(){
            p1->cancelar_prestamo();
        }
        void cronograma_pagos(){
            p1->mostrar_cronograma();
        }
        //----------------------------------------Destructor-------------------------------------------------------
        virtual ~Persona()
        {
            Color(AMARILLO);
            cout<<"\nTus datos en en este banco ha sido eliminados "<<nombres<<" "<<apellido_paterno<<" "<<apellido_materno<<endl;
            for (const auto& i:tarjetas){delete i;}
            Color(PLATA);

        }
        //----------------------------------------Destructor-------------------------------------------------------
};

#endif