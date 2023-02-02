#ifndef CLASE_PRESTAMOS
#define CLASE_PRESTAMOS

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Prestamo{
    private:
        string fecha_prestamo;
        string nombre_persona;
        string apellido_paterno_persona;
        string apellido_materno_persona;
        string identificacion;
        double monto;
        double interes;
        double restante;
        int dia;
        int mes;
        int anios;
        int meses_prestamo;
        int anios_prestamo;
    public:
        Prestamo(string nmb, string app, string amp, string identif){
            nombre_persona=nmb;
            apellido_paterno_persona=app;
            apellido_materno_persona=amp;
            identificacion=identif;
            restante=0.0;
            monto=0.0;
            interes=0.0;
            fecha_prestamo="Indefinido";
            fecha_prestamo="Indefinido";
        }
        void pedir_prestamo(){
            if(monto==0.0){
                double m=0.0;
                int ms,an;
                do{cout<<"\nCuanto dinero desea pedir prestado al banco? (Mayor a S/. 50 - Menos de S/. 10000) -> "; cin>>m;}
                while(m<20.0 or m>10000.0);
                monto=m;
                cout<<"\nIngrese el tiempo en el que desea pagar todas las deudas:\n\n";
                do{
                    cout<<"Anios de pago: "; cin>>an;
                }while(an<=0);

                do{
                    cout<<"Meses de pago: ";cin>>ms;
                }while(ms<0 or ms>=12);

                meses_prestamo=ms;
                anios_prestamo=an;
                interes=(0.0325*monto)*(meses_prestamo+(anios_prestamo*12));
                restante=monto+interes;

                //----------------------------Obtener fechas para adjuntarlos en un string------------------------------------
                time_t t = time(nullptr);
                tm* now = localtime(&t);
                fecha_prestamo=to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);

                dia=now->tm_mday;
                mes=now->tm_mon + 1;
                anios=now->tm_year + 1900;
                //----------------------------Obtener fechas para adjuntarlos en un string------------------------------------

                cout<<"\nFelicidades, su solicitud de prestamo ha sido aprobado.\n";
                cout<<"Usted ha hecho un prestamo para pagarlo en: "<<ms+(an*12)<<" meses a una tasa de interes de 3.25% mensual.\n";
                cout<<"El monto total a pagar es: "<<restante<<endl;
                cout<<"Puede revisar sus fechas de pago en la seccion 'cronograma de pagos'.\n";
            }
            else{cout<<"\nUsted ya tiene una deuda pendiente. Cancelela primero y vuelva a intentarlo.\n";}
        }
        void cancelar_prestamo(){
            if(monto==0.0){
                cout<<"\nUsted no cuenta con prestamos existentes para cancelar.\n";
            }
            else{
                restante=0.0;
                monto=0.0;
                interes=0.0;
                fecha_prestamo="Indefinido";
                dia=0;
                mes=0;
                anios=0;
                meses_prestamo=0;
                anios_prestamo=0;
                cout<<"\nFelicidades, su prestamo ha sido cancelado correctamente. Ahora ya puede solicitar otro prestamo\n";
            }
        }

        void mostrar_cronograma(){
            int m_temp=mes+1;
            int an_temp=anios;
            if(monto!=0.0){
                cout<<"\n--------------------------------------\n";
                cout<<"Fechas a pagar           Monto   \n";
                int mp=meses_prestamo+(anios_prestamo*12);
                for(int i=0; i<mp;i++){
                    if(m_temp>12){m_temp=1; an_temp+=1;}
                    if(dia<10){cout<<"0"<<dia<<"/";}
                    else{cout<<""<<dia<<"/";}
                    if(m_temp<10){cout<<"0"<<m_temp<<"/";}
                    else{cout<<m_temp<<"/";}
                    cout<<an_temp<<"\t"<<monto/mp<<endl;
                    m_temp++;
                }
                cout<<"--------------------------------------\n";
            }
            else{
                cout<<"\nUsted no cuenta con prestamos existentes.\n";
            }
        }
        double get_prestamo_total(){return restante;}
        double get_intereses(){return interes;}
        virtual ~Prestamo(){}
};
#endif