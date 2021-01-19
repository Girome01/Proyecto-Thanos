#include "listasalvahumanos.h"

ListaSalvaHumanos::ListaSalvaHumanos()
{
    primerNodo = ultimoNodo = NULL;
}

void ListaSalvaHumanos::insertarAlInicio (NodoArbol *nodoA){
    if (primerNodo == NULL){
        primerNodo = new NodoSalvar(nodoA);
        ultimoNodo = primerNodo;
    }
    else{
        NodoSalvar *nuevo = new NodoSalvar(nodoA);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

void ListaSalvaHumanos::insertarAlFinal (NodoArbol *nodoA){
    if (primerNodo == NULL){
        primerNodo = new NodoSalvar(nodoA);
        ultimoNodo = primerNodo;
    }
    else{
        NodoSalvar *nuevo = new NodoSalvar(nodoA);
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}

int ListaSalvaHumanos::largo(){
    int largo=0;
    NodoSalvar * temp = primerNodo;
    while(temp!=0){
        largo++;
        temp = temp->siguiente;
    }
    return largo;
}

