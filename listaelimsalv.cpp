#include "listaelimsalv.h"

int ListaElimSalv::largo(){
    NodoDato * temp = primerNodo;
    int largo = 0;
    while(temp != 0) {
        largo++;
        temp = temp->siguiente;
    }
    return largo;
}

bool ListaElimSalv::isEmpty(){
    return primerNodo == NULL;
}

string ListaElimSalv::imrpimir(){
    string texto = "";
    NodoDato * temp = primerNodo;
    while(temp!=0){
        texto += temp->datos + "\n";
        temp = temp->siguiente;
    }
    return texto;
}

void ListaElimSalv::insertarAlFinal(string _dato){
    if (primerNodo == NULL){
        primerNodo = new NodoDato(_dato);
        ultimoNodo = primerNodo;
    }
    else{
        NodoDato *nuevo = new NodoDato(_dato);
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}


