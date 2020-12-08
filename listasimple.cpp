#include "listasimple.h"

ListaSimple::ListaSimple(){
    primerNodo = ultimoNodo = NULL;
}

void ListaSimple::insertarAlInicio (string nombre){
    if (primerNodo == NULL){
        primerNodo = new NodoSimple(nombre);
        ultimoNodo = primerNodo;
    }
    else{
        NodoSimple *nuevo = new NodoSimple(nombre);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

void ListaSimple::insertarAlFinal (string nombre){
    if (primerNodo == NULL){
        primerNodo = new NodoSimple(nombre);
        ultimoNodo = primerNodo;
    }
    else{
        NodoSimple *nuevo = new NodoSimple(nombre);
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}
