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

int ListaDeportes::largo(){
    int largo=0;
    NodoDeporte * temp = primerNodo;
    while(temp!=0){
        largo++;
        temp = temp->siguiente;
    }
    return largo;
}

int ListaDeportes::frecuenciaDeporte(){
    NodoDeporte * temp = primerNodo;
    int cantidadTotal=0;
    while(temp!=0) {
        cantidadTotal+=temp->vecesSemana;
        temp = temp->siguiente;
    }
    return cantidadTotal;
}

string ListaDeportes::imprimir(){
    string texto = "";
    NodoDeporte * temp = primerNodo;
    while(temp!=0){
        stringstream buff;
        buff << temp->vecesSemana;
        string cant = buff.str();
        texto += temp->nombre+"\tCantidad de veces por semana: "+cant+"\n";
        temp = temp->siguiente;
    }
    return texto;
}
