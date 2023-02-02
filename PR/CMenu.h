#ifndef MENU
#define MENU
#include "CBanco.h"
class Menu{
    private:
        vector<string> nombres;
        vector<string> ap_pat;
        vector<string> ap_mat;
        vector<string> telefono;
        vector<string> direccion;
        vector<string> dni;
        vector<string> correos;
        vector<vector<string>> tarjetas;
        vector<vector<double>> plata;
    public:
        Menu(vector<string> nomb, vector<string> ap_p, vector<string> ap_m, vector<string> telf, vector<string> dirc, vector<string> idt, vector<string> crr,vector<vector<string>> tardb, vector<vector<double>> plt)
        {
            nombres=nomb;
            ap_pat=ap_p;
            ap_mat=ap_m;
            telefono=telf;
            direccion=dirc;
            dni=idt;
            correos=crr;
            tarjetas=tardb;
            plata=plt;
            tarjetas=tardb;
            plata=plt;
        }
        void inicio(vector<string>& n,vector<string>& app_patt,vector<string>& app_matt,vector<string>& telefs,vector<string>& direccions,vector<string>& identidades,vector<string>& dir_correos,vector<vector<string>>& tar_db,vector<vector<double>>&din_tar);
        friend class Persona;
        ~Menu(){}
};

#endif