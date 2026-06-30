#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include <algorithm>
#include "NodoAvl.h"

using namespace std;

class ArbolAvl
{
    public:
        NodoAvl* raiz;

        ArbolAvl();

        int GetAltura(NodoAvl* node);
        void UpdateAltura(NodoAvl* node);
        int GetBalance(NodoAvl* node);

        NodoAvl* LeftRotate(NodoAvl* x);
        NodoAvl* RightRotate(NodoAvl* x);

        int CompararEstudiantes(Estudiante* a,Estudiante* b);
        //para saber en que lado va cual dependiendo del orden alfabetico

        NodoAvl* InsertarNodo(NodoAvl* node,Estudiante* estudiante,NodoAvl* padre=nullptr);

        void Inorder(NodoAvl* node);
        void printTree(NodoAvl* node,int space=0,int height=10);//solo para verlo
};

#endif // ARBOLAVL_H
