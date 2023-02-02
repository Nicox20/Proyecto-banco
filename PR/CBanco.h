#ifndef CLASE_BANCO
#define CLASE_BANCO
#include "CPersonas.h"
#include <string>

class Banco{
    private:
        vector<Persona*> clientes;
        string nombres;
        string telefono;
        string direccion;
    public:
        //Constructor inicial del banco
        Banco():nombres("S.A UTECSINO"),telefono("+51 016753987"),direccion("Jr. Medrano Silva 182"){}

        //---------------------------------------------------------Metodo para recuperar todas las personas de manera inicial---------------------------------------------------------
        void recuperar_personas(vector<string> nomb, vector<string> ap_pat, vector<string> ap_mat, vector<string> telf, vector<string> dirc, vector<string> idt, vector<string> crr){
            for(int i=0; i<idt.size();i++){
                string a=nomb[i];
                string b=ap_pat[i];
                string c=ap_mat[i];
                string d=telf[i];
                string e=dirc[i];
                string f=idt[i];
                string g=crr[i];
                clientes.push_back(new Persona(a,b,c,d,e,f,g));
            }
        }
        //---------------------------------------------------------Metodo para recuperar todas las personas de manera inicial---------------------------------------------------------

        //-----------Metodo para recuperar las tarjetas de credito con sus datos respectivos----------------
        void recuperar_tarjetas(vector<vector<string>> numero_tarjetas, vector<vector<double>> dinero){
            for(int i=0;i<clientes.size();i++){clientes[i]->recuperar_tarjeta(numero_tarjetas[i],dinero[i]);}
        }
        //-----------Metodo para recuperar las tarjetas de credito con sus datos respectivos----------------
        
        //Metodo para agregar nuevas personas al banco
        void agregar_cliente(){clientes.push_back(new Persona());}

        //Metodo para eliminar personas del banco de acuerdo a su posicion
        void eliminar_cliente(int posicion)
        {
            //Limpiar datos del objeto
            delete clientes[posicion];
            clientes[posicion]=nullptr;
            //Eliminar directamente del vector
            clientes.erase(clientes.begin()+posicion);
        }

        //Metodo para imprimir los datos de todos los clientes
        void imprimir_datos_clientes()
        {
            if(clientes.size()==0)
            {
                Color(AMARILLO);
                cout<<"\nNO EXISTE CLIENTES"<<endl;
                Color(PLATA);
            }
            for (const auto &i:clientes)
            {
                i->imprimir_datos();
            }
        }

        //----------Metodo para imprimir los datos de un cliente en especifico-----------
        void imprimir_cliente(int pos)
        {

            clientes[pos]->imprimir_datos();
        }


        //----------Metodo para imprimir los datos de un cliente en especifico-----------

        //--------------------Metodos para exportar vectores de datos-----------------------
        vector<string> exportar_vector_nombres()
        {
            vector<string> temporal;
            for(const auto&i:clientes){temporal.push_back(i->get_nombre());}
            return temporal;
        }
        vector<string> exportar_vector_apellidos_paternos()
        {
            vector<string> temporal;
            for(const auto&i:clientes){temporal.push_back(i->get_apellido_paterno());}
            return temporal;
        }
        vector<string> exportar_vector_apellidos_maternos()
        {
            vector<string> temporal;
            for(const auto&i:clientes){temporal.push_back(i->get_apellido_materno());}
            return temporal;
        }
        vector<string> exportar_vector_telefonos()
        {
            vector<string> temporal;
            for(const auto&i:clientes){temporal.push_back(i->get_telefono());}
            return temporal;
        }
        vector<string> exportar_vector_direcciones()
        {
            vector<string> temporal;
            for(const auto&i:clientes){temporal.push_back(i->get_direccion());}
            return temporal;
        }
        vector<string> exportar_vector_dnis()
        {
            vector<string> temporal;
            for(const auto&i:clientes){temporal.push_back(i->get_dni());}
            return temporal;
        }
        vector<string> exportar_vector_correos(){
            vector<string> temporal;
            for(const auto&i:clientes){temporal.push_back(i->get_correo());}
            return temporal;
        }

        vector<vector<string>> exportar_vector_tarjetas()
        {
            vector<vector<string>> temporal;
            for(const auto&i:clientes){temporal.push_back(i->get_tarjetas());}
            return temporal;
        }

        vector<vector<double>> exportar_vector_montos_tarjetas(){
            vector<vector<double>> temporal;
            for(const auto&i:clientes){temporal.push_back(i->get_monto_tarjeta());}
            return temporal;
        }
        //--------------------Metodos para exportar vectores de datos-----------------------

        //Getter
        vector<Persona*> get_clientes(){return clientes;}
        string get_nombre(){return nombres;}
        string get_telefono(){return telefono;}
        string get_direccion(){return direccion;}
        //friend
        friend void pos_cliente(Banco& b,int &p);
        friend void servicios_cliente(Banco& b);
        friend void buscar_cliente(Banco& b);
        friend class Menu;
        //Destructor
        ~Banco(){}
};

#endif