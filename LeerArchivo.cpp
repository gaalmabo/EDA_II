#include "LeerArchivo.h"

LeerArchivo::LeerArchivo(string archivo)
{
    nombreArchivo=archivo;
}

vector<string> LeerArchivo::LeerNombres()
{
    vector<string> nombres;//aqui se almacenaran los nombres
    ifstream archivo(nombreArchivo);
    //ifstream para abrir un archivo para lectura

    if(!archivo.is_open())
    {
        cout<<"No se pudo abrir el archivo"<<endl;
        return nombres;
    }

    string linea;//guarda una fila completa del csv

    //saltar la cabecera del csv
    getline(archivo,linea);
    //lee la primera linea "first_name,last_name"
    //y el archivo queda apuntando a la segunda linea

    while(getline(archivo,linea))//mientras se pueda leer una linea del archivo
    //en cada vuelta getline lee una fila y la guarda en linea
    {
        stringstream ss(linea);
        //convierte la linea en un flujo para poder separarla usando comas

        string nombre;
        string apellido;

//getline leerá desde donde se quedó ss hasta encontrar la primera coma o hasta el final
        getline(ss,nombre,',');//lee hasta la primera coma
        getline(ss,apellido,',');//lee hasta el final

        nombres.push_back(nombre);
    }
    archivo.close();

    return nombres;
}

vector<string> LeerArchivo::LeerApellidos()
{
    vector<string> apellidos;
    ifstream archivo(nombreArchivo);

    if(!archivo.is_open())
    {
        cout<<"No se pudo abrir el archivo"<<endl;
        return apellidos;
    }

    string linea;

    getline(archivo,linea);

    while(getline(archivo,linea))
    {
        stringstream ss(linea);

        string nombre;
        string apellido;

        getline(ss,nombre,',');
        getline(ss,apellido);

        apellidos.push_back(apellido);
    }
    archivo.close();

    return apellidos;
}
