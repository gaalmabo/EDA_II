#ifndef GENERADORESTUDIANTES_h
#define GENERADORESTUDIANTES_h

#include "Estudiante.h"
#include <iostream>
#include <string>
#include <vector>//aaaaaaaaaaa
#include <random>

using namespace std;

class GeneradorEstudiantes
{
    private:
        vector<string> nombres;
        vector<string> apellidos;
        string carreras[4];
        static int contador;//guardara el sig num para el sig codigo

        mt19937 gen;//generador de numeros

    public:
        GeneradorEstudiantes(vector<string> nom,vector<string> ape);

        string GenerarCodigo(string carrera);
        double GenerarPpa();
        string GenerarCarreraAleatoria();
        string GenerarNombreAleatorio();
        string GenerarApellidoAleatorio();

        Estudiante* GenerarEstudiante();
        vector<Estudiante*> GenerarVectorEstudiantes(int cantidad);//cantidad=300
};



#endif // GeneradorEstudiantes_h
