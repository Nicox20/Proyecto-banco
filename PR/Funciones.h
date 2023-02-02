#ifndef FUNCIONES
#define FUNCIONES
#include <iostream>
#include "CBanco.h"
#include "CDebito.h"
using namespace std;

void eliminar_cliente(Banco& b)
{
    int pos,opt;
    bool encontrar=false;
    string nm;
    vector<Persona*>respaldo=b.get_clientes();
    //Preguntar mediante que forma se va a buscar el cliente a eliminar
    cout<<"\nComo desea encontrar al cliente a eliminar?\n 1. Buscar por Nombre(s)\n 2. Buscar por DNI\n 3. Buscar por Numero de Telefono\n\n";
    do{cout<<"Elija una opcion valida: "; cin>>opt;}
    while(opt>=4 or opt<=0);
    //Ver que sucede en las diferentes opciones
    switch (opt){
        //Borrado mediante busqueda del nombre
        case 1:
        {
            cin.ignore();
            cout<<"\nIngrese el nombre de la persona: "; getline(cin,nm);
            for(int i=0;i<respaldo.size();i++)
            {
                if(respaldo[i]->get_nombre()==nm)
                {
                    encontrar=true;
                    pos=i;
                    break;
                }
            }
            //Si el nombre se encuentra en alguno de los objetos persona, se procede a realizar una confirmacion previa.
            if(encontrar==true)
            {
                char ot;
                do{cout<<"¿Esta seguro de eliminar al cliente "<<respaldo[pos]->get_nombre()<<" "<<respaldo[pos]->get_apellido_paterno()<<" "<<respaldo[pos]->get_apellido_materno()<<"? (S/N) -> "; cin>>ot;}
                    while((ot!='S') and (ot!='N'));
                    if(ot=='S'){
                        b.eliminar_cliente(pos);
                    }
                    else{cout<<"\nOperacion cancelada con exito.\n";}
            }
            //De lo contrario, imprime un mensaje de error
            else{
                Color(ROJO);
                cout<<"\nEl cliente que desea eliminar no esta registrada en este banco.\n";
                Color(PLATA);}
            break;
        }
        //Borrado mediante busqueda por DNI
        case 2:{
            cin.ignore();
            cout<<"\nIngrese el DNI de la persona: "; getline(cin,nm);
            for(int i=0;i<respaldo.size();i++)
            {
                if(respaldo[i]->get_dni()==nm)
                {
                    encontrar=true;
                    pos=i;
                    break;
                }
            }
            //Si el DNI se encuentra en alguno de los objetos persona, se procede a realizar una confirmacion previa.
            if(encontrar==true)
            {
                char ot;
                do{cout<<"¿Esta seguro de eliminar al cliente "<<respaldo[pos]->get_nombre()<<" "<<respaldo[pos]->get_apellido_paterno()<<" "<<respaldo[pos]->get_apellido_materno()<<"? (S/N) -> "; cin>>ot;}
                    while((ot!='S') and (ot!='N'));
                    if(ot=='S'){
                        b.eliminar_cliente(pos);
                    }
                    else{cout<<"\nOperacion cancelada con exito.\n";}
            }
            //De lo contrario, imprime un mensaje de error
            else
            {
                Color(ROJO);

                cout<<"\nEl cliente que desea eliminar no esta registrada en este banco.\n";
                Color(PLATA);
            }
            break;}
         //Borrado mediante busqueda por numero de telefono
        case 3:{
            cin.ignore();
            cout<<"\nIngrese el numero de telefono de la persona: "; getline(cin,nm);
            for(int i=0;i<respaldo.size();i++){
                if(respaldo[i]->get_telefono()==nm)
                {
                    encontrar=true;
                    pos=i;
                    break;
                }
            }
            //Si el telefono se encuentra en alguno de los objetos persona, se procede a realizar una confirmacion previa.
            if(encontrar==true){
                char ot;
                do{cout<<"¿Esta seguro de eliminar al cliente "<<respaldo[pos]->get_nombre()<<" "<<respaldo[pos]->get_apellido_paterno()<<" "<<respaldo[pos]->get_apellido_materno()<<"? (S/N) -> "; cin>>ot;}
                    while((ot!='S') and (ot!='N'));
                    if(ot=='S'){
                        b.eliminar_cliente(pos);
                        //system("pause");
                        //system("cls");
                    }
                    else{
                        cout<<"\nOperacion cancelada con exito.\n";
                        //system("pause");
                        //system("cls");
                    }
            }
            //De lo contrario, imprime un mensaje de error
            else{
                Color(ROJO);
                cout<<"\nEl cliente que desea eliminar no esta registrada en este banco.\n";
                Color(PLATA);
            }
            break;}
        default:
            break;
    }
}

void buscar_cliente(Banco& b)
{
    int pos,opt;
    bool encontrar=false;
    string nm;
    //Preguntar mediante que forma se va a buscar el cliente a eliminar
    cout<<"\n¿Como desea buscar al cliente?\n 1. Buscar por Nombre(s)\n 2. Buscar por DNI\n 3. Buscar por Numero de Telefono\n\n";
    do{cout<<"Elija una opcion valida: "; cin>>opt;}
    while(opt>=4 or opt<=0);
    //Ver que sucede en las diferentes opciones
    switch (opt){
        //Borrado mediante busqueda del nombre
        case 1:{
            cin.ignore();
            cout<<"\nIngrese el(los) nombre(s) de la persona: "; getline(cin,nm);
            for(int i=0;i<b.clientes.size();i++){
                if(b.clientes[i]->get_nombre()==nm){
                    encontrar=true;
                    pos=i;
                    break;
                }
            }
            //Si el nombre se encuentra en alguno de los objetos persona, se procede a mostrar sus datos
            if(encontrar==true){
                b.imprimir_cliente(pos);
                //system("pause");
                //system("cls");
            }
            //De lo contrario, imprime un mensaje de error
            else{
                cout<<"\nEl cliente buscado no esta registrada en este banco.\n";
                //system("pause");
                //system("cls");
            }
            break;}
        //Borrado mediante busqueda por DNI
        case 2:{
            cin.ignore();
            cout<<"\nIngrese el DNI de la persona: "; getline(cin,nm);
            for(int i=0;i<b.clientes.size();i++){
                if(b.clientes[i]->get_dni()==nm){
                    encontrar=true;
                    pos=i;
                    break;
                }
            }
            //Si el nombre se encuentra en alguno de los objetos persona, se procede a mostrar sus datos
            if(encontrar==true){
                b.imprimir_cliente(pos);
                //system("pause");
                //system("cls");
            }
            //De lo contrario, imprime un mensaje de error
            else{
                cout<<"\nEl cliente que desea eliminar no esta registrada en este banco.\n";
                //system("pause");
                //system("cls");
            }
            break;}
         //Borrado mediante busqueda por numero de telefono
        case 3:{
            cin.ignore();
            cout<<"\nIngrese el numero de telefono de la persona: "; getline(cin,nm);
            for(int i=0;i<b.clientes.size();i++){
                if(b.clientes[i]->get_telefono()==nm){
                    encontrar=true;
                    pos=i;
                    break;
                }
            }
            //Si el nombre se encuentra en alguno de los objetos persona, se procede a mostrar sus datos
            if(encontrar==true){
                b.imprimir_cliente(pos);
                //system("pause");
                //system("cls");
            }
            //De lo contrario, imprime un mensaje de error
            else{
                cout<<"\nEl cliente que desea eliminar no esta registrada en este banco.\n";
                //system("pause");
                //system("cls");
            }
            break;}
        default:
            break;
    }
}

void pos_cliente(Banco& b,int& p){
    int pos,opt;
    bool encontrar=false;
    string nm;
    //Preguntar mediante que forma se va a buscar el cliente a eliminar
    cout<<"\n¿Como desea buscar al cliente? (Necesario para registrar nuevos servicios)\n 1. Buscar por Nombre(s)\n 2. Buscar por DNI\n 3. Buscar por Numero de Telefono\n\n";
    do{cout<<"Elija una opcion valida: "; cin>>opt;}
    while(opt>=4 or opt<=0);
    //Ver que sucede en las diferentes opciones
    switch (opt){
        //Borrado mediante busqueda del nombre
        case 1:{
            cin.ignore();
            cout<<"\nIngrese el(los) nombre(s) de la persona: "; getline(cin,nm);
            for(int i=0;i<b.clientes.size();i++){
                if(b.clientes[i]->get_nombre()==nm){
                    encontrar=true;
                    pos=i;
                    break;
                }
            }
            //Si el nombre se encuentra en alguno de los objetos persona, se procede a mostrar sus datos
            if(encontrar==true){
                p=pos;
                //system("pause");
                //system("cls");
            }
            //De lo contrario, imprime un mensaje de error
            else{
                cout<<"\nEl cliente buscado no esta registrada en este banco.\n";
                p=-1;
                //system("pause");
                //system("cls");
            }
            break;}
        //Borrado mediante busqueda por DNI
        case 2:{
            cin.ignore();
            cout<<"\nIngrese el DNI de la persona: "; getline(cin,nm);
            for(int i=0;i<b.clientes.size();i++){
                if(b.clientes[i]->get_dni()==nm){
                    encontrar=true;
                    pos=i;
                    break;
                }
            }
            //Si el nombre se encuentra en alguno de los objetos persona, se procede a mostrar sus datos
            if(encontrar==true){
                p=pos;
                //system("pause");
                //system("cls");
            }
            //De lo contrario, imprime un mensaje de error
            else{
                cout<<"\nEl cliente que desea eliminar no esta registrada en este banco.\n";
                p=-1;
                //system("pause");
                //system("cls");
            }
            break;}
         //Borrado mediante busqueda por numero de telefono
        case 3:{
            cin.ignore();
            cout<<"\nIngrese el numero de telefono de la persona: "; getline(cin,nm);
            for(int i=0;i<b.clientes.size();i++){
                if(b.clientes[i]->get_telefono()==nm){
                    encontrar=true;
                    pos=i;
                    break;
                }
            }
            //Si el nombre se encuentra en alguno de los objetos persona, se procede a mostrar sus datos
            if(encontrar==true){
                p=pos;
                //system("pause");
                //system("cls");
            }
            //De lo contrario, imprime un mensaje de error
            else{
                cout<<"\nEl cliente que desea eliminar no esta registrada en este banco.\n";
                p=-1;
                //system("pause");
                //system("cls");
            }
            break;}
        default:
            break;
    }
}

void servicios_cliente(Banco& b){
    int pos,ot;
    pos_cliente(b,pos);
    if(pos!=-1){
        cout<<"\n¿Que servicios desea agregar al cliente "<<b.clientes[pos]->get_nombre()<<" "<<b.clientes[pos]->get_apellido_paterno()<<" "<<b.clientes[pos]->get_apellido_materno()<<"?\n1. Agregar nueva tarjeta de debito\n2. Bloquear tarjetas de debito existentes\n3. Mostrar todas las tarjetas de debito\n4. Depositar a una tarjeta\n5. Retirar fondos de una tarjeta\n6. Ver historial de transacciones\n7. Hacer nuevo prestamo\n8. Cancelar prestamo\n9. Mostrar cronograma de pagos\n\n";
        do{cout<<"Elija una opcion valida: "; cin>>ot;}
        while(ot>=10 or ot<=0);
        switch (ot)
        {
        case 1:{
            //Agregar tarjeta de credito
            b.clientes[pos]->agregar_tarjeta();
            break;}
        case 2:{
            //Eliminar tarjeta de credito
            b.clientes[pos]->bloquear_tarjeta();
            break;}
        case 3:{
            //Mostrar tarjetas de debito de la persona
            b.clientes[pos]->mostrar_tarjetas();
            break;}
        case 4:{
            //Depositar fondos
            b.clientes[pos]->depositar();
            break;}
        case 5:{
            //Retirar fondos
            b.clientes[pos]->retirar();
            break;}
        case 6:{
            //Historial de transacciones
            b.clientes[pos]->mostrar_historial_transacciones();
            break;}
        case 7:{
            //Hacer prestamo
            b.clientes[pos]->pedir_prestamo();
            break;}
        case 8:{
            //Pagar prestamo
            b.clientes[pos]->cancelar_prestamo();
            break;}
        case 9:{
            //Pagar prestamo
            b.clientes[pos]->cronograma_pagos();
            break;}
        default:
            break;
        }
    }
}

#endif