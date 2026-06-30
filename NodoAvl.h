#ifndef NODOAVL_H
#define NODOAVL_H

#include "Estudiante.h"

class NodoAvl
{
    public:
        Estudiante* estudiante;
        NodoAvl* izq;
        NodoAvl* der;
        NodoAvl* padre;
        int altura;

        NodoAvl(Estudiante* est);
};

#endif // NODOAVL_H
