#include "listaelimsalv.h"

int listaElimSalv::largo(){
    NodoDato * temp = primerNodo;
    int largo = 0;
    while(temp != 0) {
        largo++;
        temp = temp->siguiente;
    }
    return largo;
}

bool listaElimSalv::isEmpty(){
    return primerNodo == NULL;
}

string listaElimSalv::imrpimir(){
    string texto = "";
    NodoDato * temp = primerNodo;
    while(temp!=0){
        texto += temp->datos + "\n";
        temp = temp->siguiente;
    }
    return texto;
}

