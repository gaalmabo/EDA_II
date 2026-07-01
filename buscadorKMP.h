#ifndef BUSCADORKMP_H
#define BUSCADORKMP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BuscadorKMP
{
private:
    static vector<int> ConstruirLPS(string patron);

public:
    static bool Buscar(string texto, string patron);
};

#endif