#include "listadeportes.h"

ListaDeportes::ListaDeportes(){
    primerNodo = ultimoNodo = NULL;
}

void ListaDeportes::insertarAlInicio (int vecesSemana, string nombre){
    if (primerNodo == NULL){
        primerNodo = new NodoDeporte(vecesSemana, nombre);
        ultimoNodo = primerNodo;
    }
    else{
        NodoDeporte *nuevo = new NodoDeporte(vecesSemana, nombre);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

void ListaDeportes::insertarAlFinal (int vecesSemana, string nombre){
    if (primerNodo == NULL){
        primerNodo = new NodoDeporte(vecesSemana, nombre);
        ultimoNodo = primerNodo;
    }
    else{
        NodoDeporte *nuevo = new NodoDeporte(vecesSemana, nombre);
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}
