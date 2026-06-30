#ifndef ESTUDIANTE_h
#define ESTUDIANTE_h

#include <iostream>
#include <string>

using namespace std;

class Estudiante
{
    private:
        string codigo;
        string nombre;
        string apellido;
        double ppa;
    public:
        //constructor
        Estudiante(string cod,string nom,string ape,double prom);

        //getters
        string GetCodigo();
        string GetNombre();
        string GetApellido();
        double GetPpa();

        void MostrarDatos();
};
#endif
