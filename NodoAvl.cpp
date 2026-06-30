#include "NodoAvl.h"

NodoAvl::NodoAvl(Estudiante* est)
{
    estudiante=est;
    izq=nullptr;
    der=nullptr;
    padre=nullptr;
    altura=0;
}
