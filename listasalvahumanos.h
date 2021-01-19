#ifndef LISTASALVAHUMANOS_H
#define LISTASALVAHUMANOS_H

#include <cstdlib>
#include <iostream>
#include "arbol.h"
using namespace std;

struct NodoSalvar {
       NodoArbol *nodoA;
       NodoSalvar* siguiente;

       NodoSalvar(NodoArbol *_nodoA) {
         nodoA = _nodoA;
         siguiente = NULL;
       }
};

struct ListaSalvaHumanos
{
    NodoSalvar *primerNodo, *ultimoNodo;

    ListaSalvaHumanos();

    void insertarAlInicio (NodoArbol *nodoA);
    void insertarAlFinal(NodoArbol *nodoA);
    int largo();
};

#endif // LISTASALVAHUMANOS_H
