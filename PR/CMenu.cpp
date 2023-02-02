#include "CMenu.h"
#include "Funciones.h"
#include <iostream>
#include "libgame.h"
#include <fstream>
#include <iomanip>

using namespace std;

void Menu::inicio(vector<string>& n,vector<string>& app_patt,vector<string>& app_matt,vector<string>& telefs,vector<string>& direccions,vector<string>& identidades,vector<string>& dir_correos,vector<vector<string>>& tar_db,vector<vector<double>>&din_tar){

    Banco mibanco;
    int opcion,opt2;

    //Iniciarcilar los datos del banco con los clientes
    mibanco.recuperar_personas(nombres,ap_pat,ap_mat,telefono,direccion,dni,correos);
    mibanco.recuperar_tarjetas(tarjetas,plata);


    while (true)
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i==0 or j==0 or i==9 )
                {
                    Color(VERDE2);
                    cout<<setw(35)<<"  . . . --´````'''°";
                }
                else if(j==9)
                {
                    Color(AMARILLO);
                    cout<<" +";
                    cout<<"   +";
                    cout<<" +";
                }
                else if(i==2 and j==6)
                {
                    Color(PLATA);
                    cout<<"UTEC BANK";
                }
                else if(i==4 and j==5)
                {
                    Color(AMARILLO);
                    cout<<"Jr. Medrano Silva 182";

                }
                else if(i==6 and j==5)
                {
                    Color(PLATA);
                    cout<<"+51 016753987";

                }
                else
                {
                    cout<<"      ";
                }
            }
            cout<<endl;
        }

        //cout<<"\nBienvenido al sistema del banco "<<mibanco.get_nombre()<<".\nRecuerdo que puede contactarnos a travez de nuestro telefono: "<<mibanco.get_telefono()<<".\nNos puede encontrar en: "<<mibanco.get_direccion()<<"."<<endl<<endl;
        cout<<endl;
        Color(PLATA);
        cout<<"Opciones:\n\n1. Agregar/eliminar clientes\n2. Servicios de los clientes\n3. Buscar datos del cliente\n4. Imprimir reportes\n5. Salir\n\n";

        do{cout<<"Ingrese una opcion valida: "; cin>>opcion;}
        while(opcion<=0 or opcion>=6);

        if(opcion==5)
        {
            Color(MORADO);
            cout<<"\nGracias por confiar en nosotros, lo esperamos pronto!!!\n\n";
            Color(PLATA);break;
        }
        else{
            switch (opcion)
            {
            case 1:
            {

                cout<<"\nQue desea hacer ahora?\n\n1. Agregar cliente\n2. Eliminar cliente\n\n";
                do{cout<<"Ingrese una opcion valida: "; cin>>opt2;}
                while(opt2<=0 or opt2>=3);
                switch (opt2)
                {
                    case 1:
                        mibanco.agregar_cliente();
                        break;
                    case 2:
                        eliminar_cliente(mibanco);
                        break;
                    default:
                        break;
                }
                break;}
            case 2:{
                //system("cls"); //Quitar el comentario al terminar
                servicios_cliente(mibanco);
                break;}
            case 3:{
                //system("cls"); //Quitar el comentario al terminar
                buscar_cliente(mibanco);
                break;}
            case 4:{
                //system("cls"); //Quitar el comentario al terminar
                cout<<"\nQue desea hacer ahora?\n\n1. Imprimir reporte de los clientes registrados\n2. Imprimir reporte de tarjetas existentes\n3. Imprimir reporte de prestamos realizados\n\n";
                do{cout<<"Ingrese una opcion valida: "; cin>>opt2;}
                while(opt2<=0 or opt2>=4);
                switch (opt2)
                {
                    case 1:
                        //system("cls"); //Quitar el comentario al terminar
                        mibanco.imprimir_datos_clientes();
                        break;
                    case 2:{
                        double dinero=0;
                        int tar=0;
                        //system("cls"); //Quitar el comentario al terminar
                        for(int i=0; i<mibanco.clientes.size();i++)
                        {

                            mibanco.clientes[i]->mostrar_tarjetas();
                            //4cout<<"DINERO---> "<<mibanco.clientes[i]->get_monto_total()<<endl;
                            dinero+=mibanco.clientes[i]->get_monto_total();
                            //cout<<"DINERO---+++ "<<mibanco.clientes[i]->get_monto_total()<<endl;
                            tar+=mibanco.clientes[i]->get_total_tarjetas();
                        }
                        Color(AMARILLO);
                        cout<<"\tEl total de tarjetas registradas es: "<<tar<<endl;
                        cout<<"\tEl total de dinero existente es: "<<dinero<<endl;
                        Color(PLATA);
                        break;}
                    case 3:{
                        //system("cls"); //Quitar el comentario al terminar
                        int prestamos=0;
                        double t_pres=0.0, interes=0.0;
                        for(const auto&i:mibanco.clientes){
                            if(i->get_deuda_total()!=0.0){
                                prestamos+=1;
                                t_pres+=i->get_deuda_total();
                                interes+=i->get_intereses();
                            }
                        }
                        if(prestamos==0)
                        {
                            Color(AMARILLO);
                            cout<<"\nNo hay prestamos realizados por el momento.\n\n";
                            Color(PLATA);
                        }
                        else{
                            cout<<"\n---------------------------------------------------------\n";
                            cout<<"Reporte de prestamos realizados hasta la fecha: \n\n";
                            cout<<"Numero de prestamos existentes actualmente: "<<prestamos<<endl;
                            cout<<"Total de intereses cobrados: "<<interes<<endl;
                            cout<<"Total de dinero a cobrar: "<<t_pres<<endl;
                            cout<<"---------------------------------------------------------\n\n";
                        }
                        break;}
                    default:
                        break;
                }
                break;}
            default:
                break;
            }
        }
    }
    //Despues de terminar de ejecutarse todo, se procede a reescribir los vectores de datos con las funciones de exportacion
    n=mibanco.exportar_vector_nombres();
    app_patt=mibanco.exportar_vector_apellidos_paternos();
    app_matt=mibanco.exportar_vector_apellidos_maternos();
    telefs=mibanco.exportar_vector_telefonos();
    direccions=mibanco.exportar_vector_direcciones();
    identidades=mibanco.exportar_vector_dnis();
    dir_correos=mibanco.exportar_vector_correos();
    tarjetas=mibanco.exportar_vector_tarjetas();
    plata=mibanco.exportar_vector_montos_tarjetas();
    cout<<"RECORRER TARGETAS"<<endl;
    for (int i=0;i<tarjetas.size();i++)
    {
        for(auto cuentas:tarjetas[i])
        {
            cout<<"Cuenta "<<i+1<<": "<<cuentas<<endl;

        }
        for(auto fondos:plata[i])
        {
            cout<<"Fondos "<<i+1<<": "<<fondos<<endl;
        }

    }

    //Despues de terminar de ejecutarse todo, se procede a reescribir los vectores de datos con las funciones de exportacion
    ofstream salida("../PR/Clientes.txt");
    //archivo.open("../PR/Clientes.txt.txt",ios::out); //app final
    if (salida.fail())
    {
        cout<<"-----ERROR NO SE PUDO ABRIR ARCHIVO-----"<<endl;
        exit(1);
    }
    cout<<"SOBREESCRIBIR"<<endl;
    for(int cliente=0;cliente<n.size();cliente++)
    {
        cout<<"\nNombres: "<<n[cliente]<<endl;
        cout<<"Apellido Paterno: "<<app_patt[cliente]<<endl;
        cout<<"Apellido Materno: "<<app_matt[cliente]<<endl;
        cout<<"Telefono: "<<telefs[cliente]<<endl;
        cout<<"Direccion: "<<direccions[cliente]<<endl;
        cout<<"Dni: "<<identidades[cliente]<<endl;
        cout<<"Correo: "<<dir_correos[cliente]<<endl;
        for (int j=0;j<tarjetas[cliente].size();j++)
        {
            cout<<"Cuenta "<<j+1<<": "<<tarjetas[cliente][j]<<endl;
            cout<<"Fondos "<<j+1<<": "<<plata[cliente][j]<<endl;
        }

    }

    //ESCRIBIR
    for(int i=0;i<n.size();i++)
    {
        salida<<n[i]<<",";
        salida<<app_patt[i]<<",";
        salida<<app_matt[i]<<",";
        salida<<telefs[i]<<",";
        salida<<direccions[i]<<",";
        salida<<identidades[i]<<",";
        salida<<dir_correos[i]<<",";
        for(auto cuentas:tarjetas[i]){salida<<cuentas<<",";}
        for(auto fondos:plata[i]){salida<<fondos<<","<<endl;}
    }
    salida.close();


}
