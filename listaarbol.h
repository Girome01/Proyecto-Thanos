#ifndef LISTAARBOL_H
#define LISTAARBOL_H

struct NodoPersona;
#include "listadoble.h"

struct NodoListaArbol{
    NodoPersona* persona;
    NodoListaArbol* siguiente;
    NodoListaArbol(NodoPersona* _persona){
        persona = _persona;
        siguiente = NULL;
    }
};

struct ListaArbol{
    NodoListaArbol* primerNodo;
    NodoListaArbol* ultimoNodo;
    int largo = 0;

    ListaArbol();

    int largoLista();
    void agregarHumanos(NodoPersona* persona);
    NodoListaArbol *centroLista();
    ListaArbol *primerMitad();
    ListaArbol *segundaMitad();
    void imprimir();
};

#endif // LISTAARBOL_H
