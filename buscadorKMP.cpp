#include "buscadorKMP.h"
#include <cctype>

string ConvertirMinusculas(string texto)
{
    for(int i = 0; i < texto.length(); i++) {
        texto[i] = tolower(texto[i]);
    }

    return texto;
}

vector<int> BuscadorKMP::ConstruirLPS(string patron)
{
    vector<int> lps(patron.length(), 0);

    int longitud = 0;
    int i = 1;

    while(i < patron.length()) {
        if(patron[i] == patron[longitud]) {
            longitud++;
            lps[i] = longitud;
            i++;
        }
        else
        {
            if(longitud != 0) {
                longitud = lps[longitud - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool BuscadorKMP::Buscar(string texto, string patron)
{
    if(patron.empty()) {
        return true;
    }

    texto = ConvertirMinusculas(texto);
    patron = ConvertirMinusculas(patron);

    vector<int> lps = ConstruirLPS(patron);

    int i = 0;
    int j = 0;

    while(i < texto.length()) {
        if(texto[i] == patron[j]) {
            i++;
            j++;

            if(j == patron.length()) {
                return true;
            }
        }
        else
        {
            if(j != 0) {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return false;
}






