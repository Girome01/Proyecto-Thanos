#ifndef LISTAELIMSALV_H
#define LISTAELIMSALV_H

#include <cstdlib>
#include <iostream>
using namespace std;

struct NodoDato {
    string datos;
    NodoDato* siguiente;

    NodoDato(string _dato) {
       datos = _dato;
    }
};

struct listaElimSalv{
    NodoDato* primerNodo;
    NodoDato* ultimoNodo;

    listaElimSalv(){
        primerNodo = ultimoNodo = NULL;
    }

    int largo();
    bool isEmpty();
    string imrpimir();
};

#endif // LISTAELIMSALV_H
