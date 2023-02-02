#include "CMenu.h"
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
void leer(vector<string> Base,int ubicacion,vector<string>& nombres,vector<string>& apellidos_paternos,vector<string>& apellidos_maternos,vector<string>& telefonos,vector<string>& direcciones,vector<string>& dnis, vector<vector<string>>& cuentas,vector<string>& correos , vector<vector<double>>& fondos);
int main()
{
    //PR/CBanco.h PR/CDebito.h PR/CMenu.h PR/CMenu.cpp PR/CMovimientos.h PR/CPersonas.h PR/CPrestamos.h PR/CTarjetas.h PR/Funciones.h PR/main.cpp PR/libgame.cpp PR/libgame.h
    vector<string> nombres;
    vector<string> ap_pat;
    vector<string> ap_mat;
    vector<string> telefono;
    vector<string> direccion;
    vector<string> dni;
    vector<string> correos;
    vector<vector<string>> tarjetas;
    vector<vector<double>> plata;


    //Agregar un if para verificar si hay datos guardados previamente
    ofstream archivo;
    archivo.open("../PR/Clientes.txt",ios::in); //Si no existe lo crea
    if (archivo.fail())
    {
        cout<<"ERROR NO SE PUDO ABRIR ARCHIVO"<<endl;
        exit(1);
    }
    //Si el archivo de clientes esta vacio, se crea el archivo y se ejecuta el menu
    string path = "../PR/Clientes.txt";
    if(filesystem::file_size(path) != 0)
    {
        Color(VERDE2);
        cout<<"R E C U P E R A N D O  D A T O S . . .. ... ..... ............"<<endl;
        Color(PLATA);
        //NECESARIOS PARA RECUPERAR LOS DATOS DEL TXT
        ifstream Archivos;
        string todo;
        string linea;

        //VECTOR DE LINEAS DE CODIGO DEL TXT
        vector<string> Base_de_datos;
        ifstream gg("../PR/Clientes.txt");
        while(getline(gg,linea))
        {
            Base_de_datos.push_back(linea);

        }
        cout<<endl;
        int ub=0;
        do{


            leer(Base_de_datos,ub,nombres,ap_pat,ap_mat,telefono,direccion,dni,tarjetas,correos,plata);
            ub++;
        } while (ub!=Base_de_datos.size());
    }

    archivo.close();




    //Sino iniciar el menu de manera directa
    Menu mimenu(nombres,ap_pat,ap_mat,telefono,direccion,dni,correos,tarjetas,plata);
    mimenu.inicio(nombres,ap_pat,ap_mat,telefono,direccion,dni,correos,tarjetas,plata);


    return 0;
}


void leer(vector<string> Base,int ubicacion,vector<string>& nombres,vector<string>& apellidos_paternos,vector<string>& apellidos_maternos,vector<string>& telefonos,vector<string>& direcciones,vector<string>& dnis, vector<vector<string>>& cuentas,vector<string>& correos , vector<vector<double>>& fondos)
{
    vector<string> cuentas_temp;
    vector<double> fondos_temp;
    int posiciones=1;
    string temp="";

    for(int i=0;i<Base[ubicacion].size();i++)
    {
        if(Base[ubicacion][i]==*",")
        {
            if(posiciones==1)
            {
                //cout<<"Nombres: "<<temp<<endl;
                nombres.push_back(temp);
            }

            else if(posiciones==2)
            {
                //cout<<"Apellido Paterno: "<<temp<<endl;
                apellidos_paternos.push_back(temp);
            }
            else if(posiciones==3)
            {
                //cout<<"Apellido Materno: "<<temp<<endl;
                apellidos_maternos.push_back(temp);
            }

            else if(posiciones==4)
            {
                //cout<<"Telefono: "<<temp<<endl;
                telefonos.push_back(temp);
            }
            else if(posiciones==5)
            {
                //cout<<"Direccion: "<<temp<<endl;
                direcciones.push_back(temp);
            }


            else if(posiciones==6)
            {
                //cout<<"Dni: "<<temp<<endl;
                dnis.push_back(temp);
            }
            else if(posiciones==7)
            {
                //cout<<"Correo: "<<temp<<endl;
                correos.push_back(temp);
            }
            else if(posiciones%2 == 0)
            {
                //cout<<"Cuenta: "<<temp<<endl;
                cuentas_temp.push_back(temp);
            }
            else
            {
                //ERROR USANDO STOD
                double n;
                istringstream(temp)>>n;
                //cout<<"SUMA-------------->  "<<n+2.0121<<endl;
                fondos_temp.push_back(n); //Stod es una funcion para convertir un string a double
            }
            temp="";
            posiciones++;//cout<<i<<" --->"<<posiciones<<endl;
        }

        else
        {
            temp+=Base[ubicacion][i];
        }
    }

    //AGREGO LAS CUENTAS DEL CLIENTE AL VECTOR DE VECTORES QUE ALMACE LAS CUENTAS DE TODOS LOS CLIENTES
    cuentas.push_back(cuentas_temp);
    fondos.push_back(fondos_temp);
}
