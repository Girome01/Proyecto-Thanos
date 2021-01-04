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

struct ListaElimSalv{
    NodoDato* primerNodo;
    NodoDato* ultimoNodo;

    ListaElimSalv(){
        primerNodo = ultimoNodo = NULL;
    }

    int largo();
    bool isEmpty();
    string imrpimir();
    void insertarAlFinal(string nombre);
};

#endif // LISTAELIMSALV_H
