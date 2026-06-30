#ifndef LEERARCHIVO_H
#define LEERARCHIVO_H

#include <iostream>
#include <fstream>//para abrir y leer archivos
#include <sstream>//sirve para dividir una linea por palabras con comas
#include <string>
#include <vector>

using namespace std;

class LeerArchivo
{
    private:
        string nombreArchivo;//guarda el nombre del archivo csv

    public:
        LeerArchivo(string archivo);

        vector<string> LeerNombres();
        vector<string> LeerApellidos();
};
#endif
