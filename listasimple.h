#ifndef LITASIMPLE_H
#define LITASIMPLE_H


#include <cstdlib>
#include <iostream>
using namespace std;

struct NodoSimple {
       string nombre;
       NodoSimple* siguiente;

       NodoSimple(string _nombre) {
         nombre = _nombre;
         siguiente = NULL;
       }
};


struct ListaSimple {
    NodoSimple *primerNodo, *ultimoNodo;

    ListaSimple();

    void insertarAlInicio (string nombre);
    void insertarAlFinal(string nombre);

};

#endif // LITASIMPLE_H
