#include "ArbolAvl.h"

ArbolAvl::ArbolAvl()//constructor
{
    raiz=nullptr;//al inicio está vacio
}

int ArbolAvl::GetAltura(NodoAvl* node)
{
    if(node !=nullptr)
    {
        return node->altura;
    }
    else
    {
        return 0;//si el nodo es nulo la altura es 0
    }
}

void ArbolAvl::UpdateAltura(NodoAvl* node)
{
    if(node)
    {
        node->altura=max(GetAltura(node->izq),GetAltura(node->der))+1;//toma la mayor altura entre su hijo izq y derecho
    }
}

int ArbolAvl::GetBalance(NodoAvl* node)
{
    if(node !=nullptr)
    {
//balance=altura del hijo izq -altura del hijo derecho
        int izqAltura= GetAltura(node->izq);
        int derAltura= GetAltura(node->der);
        return izqAltura-derAltura;
    }
    else
    {
        return 0;
    }
}

NodoAvl* ArbolAvl::LeftRotate(NodoAvl* x)
{
    NodoAvl* y= x->der;//y es la nueva raiz
    x->der = y->izq;

    if(y->izq != nullptr)
    {
        y->izq->padre=x;
    }

    y->padre=x->padre;

    if(x->padre==nullptr)
    {
        raiz=y;
    }
    else
    {
        if(x==x->padre->izq)
        {
            x->padre->izq=y;
        }
        else
        {
            x->padre->der=y;
        }
    }

    y->izq=x;
    x->padre=y;

    UpdateAltura(x);
    UpdateAltura(y);
    return y;
}

NodoAvl* ArbolAvl::RightRotate(NodoAvl* x)
{
    NodoAvl* y= x->izq;
    x->izq = y->der;

    if(y->der != nullptr)
    {
        y->der->padre=x;
    }

    y->padre=x->padre;

    if(x->padre==nullptr)
    {
        raiz=y;
    }
    else
    {
        if(x==x->padre->der)
        {
            x->padre->der=y;
        }
        else
        {
            x->padre->izq=y;
        }
    }

    y->der=x;
    x->padre=y;

    UpdateAltura(x);
    UpdateAltura(y);

    return y;
}

int ArbolAvl::CompararEstudiantes(Estudiante* a,Estudiante* b)
{
    if( a->GetApellido() < b->GetApellido() )
    {
        return -1;//a va a la izq de b
    }
    else
    {
        if( a->GetApellido() > b->GetApellido())
        {
            return 1;//a va a la der de b
        }
        else//Si tienen el mismo apellido verificamos codigo
        {
            if( a->GetCodigo() < b->GetCodigo())//si el codigo de a es menor al de b
            {
                return -1;//a va a la izq de b
            }
            else
            {
                if( a->GetCodigo() > b->GetCodigo())//si el codigo de a es mayor al de b
                {
                    return 1;//a va a la der de b
                }
                else
                {
                    return 0;//son el mismo estudiante
                }
            }
        }
    }
}

NodoAvl* ArbolAvl::InsertarNodo(NodoAvl* node,Estudiante* estudiante,NodoAvl* padre)
{
    if(!node)
    {
        NodoAvl* newNode=new NodoAvl(estudiante);
        newNode->padre=padre;
        return newNode;
    }

    //se usa el metodo CompararEstudiantes() para determinar si el nuevo estudiante irá a la izq o derecha
    int comparacion= CompararEstudiantes(estudiante,node->estudiante);//nodo nuevo vs nodo actual

    if(comparacion < 0)//estudiante va a la izq
    {
        node->izq= InsertarNodo(node->izq,estudiante,node);
    }
    else
    {
        if(comparacion>0)//estudiante va a la derecha
        {
            node->der=InsertarNodo(node->der,estudiante,node);
        }
        else//si es igual
        {
            return node;
        }
    }

    UpdateAltura(node);

    int balance=GetBalance(node);
    //caso izq-izq
    if(balance>1 && CompararEstudiantes(estudiante,node->izq->estudiante)<0)
    {
        return RightRotate(node);
    }

    //caso der-der
    if(balance <-1 && CompararEstudiantes(estudiante,node->der->estudiante)>0)
    {
        return LeftRotate(node);
    }

    //caso izq-der
    if(balance >1 && CompararEstudiantes(estudiante,node->izq->estudiante)>0)
    {
        node->izq=LeftRotate(node->izq);

        if(node->izq !=nullptr)
        {
            node->izq->padre=node;
        }

        return RightRotate(node);
    }

    //caso der-izq
    if(balance <-1 && CompararEstudiantes(estudiante,node->der->estudiante)<0)
    {
        node->der=RightRotate(node->der);

        if(node->der !=nullptr)
        {
            node->der->padre=node;
        }

        return LeftRotate(node);
    }
    return node;
}

void ArbolAvl::Inorder(NodoAvl* node)
{
    if(node==nullptr)
    {
        return;//caso base
    }

    Inorder(node->izq);//recorre subarbol izq
    node->estudiante->MostrarDatos();//muestra estudiante actual
    Inorder(node->der);//recorre subarbol derecho
}

void ArbolAvl::printTree(NodoAvl* node, int space, int height)
{
    if(node == nullptr)
    {
        return;
    }

    space += height;

    printTree(node->der, space, height);

    cout << endl;

    for(int i = height; i < space; i++)
    {
        cout << " ";
    }

    cout << node->estudiante->GetApellido()
         << " - "
         << node->estudiante->GetNombre()
         << " ("
         << node->estudiante->GetCodigo()
         << ")"
         << endl;

    printTree(node->izq, space, height);
}




