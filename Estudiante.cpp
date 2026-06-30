#include "Estudiante.h"
#include <iomanip>//pq el enunciado pide que ppa salga con dos decimales
//cout << fixed << setprecision(2) << ppa;

Estudiante:: Estudiante(string cod,string nom,string ape,double prom)
{
    codigo=cod;
    nombre=nom;
    apellido=ape;
    ppa=prom;
}

string Estudiante::GetCodigo()
{
    return codigo;
}

string Estudiante::GetNombre()
{
    return nombre;
}

string Estudiante::GetApellido()
{
    return apellido;
}

double Estudiante::GetPpa()
{
    return ppa;
}

void Estudiante::MostrarDatos()
{
    cout<<codigo<<","<<nombre<<","<<apellido<<","
    <<fixed<<setprecision(2)<<ppa<<endl;
    //fixed muestra la cantidad de numeros despues del
    //decimal que "setprecision" le indique
}
