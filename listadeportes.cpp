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

bool ListaDeportes::esta(string deporte){
    NodoDeporte * temp = primerNodo;
    while(temp!=0){
        if(temp->nombre == deporte){
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

NodoDeporte* ListaDeportes::obtener(string deporte){
    NodoDeporte * temp = primerNodo;
    while(temp!=0){
        if(temp->nombre == deporte){
            return temp;
        }
        temp = temp->siguiente;
    }
    return NULL;
}
