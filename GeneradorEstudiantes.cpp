#include "GeneradorEstudiantes.h"
#include <cmath>

int GeneradorEstudiantes::contador=1000;

GeneradorEstudiantes::GeneradorEstudiantes(vector<string> nom,vector<string> ape): gen(random_device{}())
{
    nombres=nom;
    apellidos=ape;

    carreras[0]="CS";
    carreras[1]="SI";
    carreras[2]="CE";
    carreras[3]="TI";
}

string GeneradorEstudiantes::GenerarCodigo(string carrera)
{
    string codigo=carrera + to_string(contador);
    contador++;
    return codigo;
}
double GeneradorEstudiantes::GenerarPpa()
{
    uniform_real_distribution<> dis(1.0,20.0);//esto crea un numero

    double ppa=dis(gen);
    //dis(gen) puede retornar numeros con varios decimales
    //el enunciado nos pide dos
    //se multiplica por 100 para pasar los dos primeros decimales a la parte entera
    //luego se redondea con round() y se vuelve a dividir entre 100
    //para que ppa tenga los dos decimales
    ppa= round(ppa*100.0)/100.0;
    return ppa;
}

string GeneradorEstudiantes::GenerarCarreraAleatoria()
{
    uniform_int_distribution<> dis(0,3);//crea una distribucion de números enteros entre 0 y 3

    int indice=dis(gen);//devuelve una posicion valida del arreglo
    return carreras[indice];
}

string GeneradorEstudiantes::GenerarNombreAleatorio()
{
    uniform_int_distribution<> dis(0,nombres.size()-1);

    int indice=dis(gen);
    return nombres[indice];
}

string GeneradorEstudiantes::GenerarApellidoAleatorio()
{
    uniform_int_distribution<> dis(0,apellidos.size()-1);

    int indice=dis(gen);
    return apellidos[indice];
}

Estudiante* GeneradorEstudiantes::GenerarEstudiante()
{
    string carrera=GenerarCarreraAleatoria();
    string codigo= GenerarCodigo(carrera);
    string nombre= GenerarNombreAleatorio();
    string apellido= GenerarApellidoAleatorio();
    double ppa=GenerarPpa();

    Estudiante* estudiante=new Estudiante(codigo,nombre,apellido,ppa);

    return estudiante;
}

vector<Estudiante*> GeneradorEstudiantes::GenerarVectorEstudiantes(int cantidad)
{
    vector<Estudiante*> estudiantes;

    for(int i=0;i<cantidad;i++)
    {
        estudiantes.push_back(GenerarEstudiante());
    }
    return estudiantes;
}

