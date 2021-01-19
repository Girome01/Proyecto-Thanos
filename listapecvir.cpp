#include "listapecvir.h"

ListaPecVir::ListaPecVir(){
    primerNodo = ultimoNodo = NULL;
}

void ListaPecVir::insertarAlInicio (int cantidad, string nombre){
    if (primerNodo == NULL){
        primerNodo = new PecadoVirtud(cantidad,nombre);
        ultimoNodo = primerNodo;
    }
    else{
        PecadoVirtud *nuevo = new PecadoVirtud(cantidad,nombre);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

void ListaPecVir::insertarAlFinal (int cantidad, string nombre){
    if (primerNodo == NULL){
        primerNodo = new PecadoVirtud(cantidad,nombre);
        ultimoNodo = primerNodo;
    }
    else{
        PecadoVirtud *nuevo = new PecadoVirtud(cantidad,nombre);
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}

void ListaPecVir::modificarCantidad(){
    PecadoVirtud * temp = primerNodo;
    while(temp!=0) {
        int _dato = int(QRandomGenerator::global()->bounded(0, 100));
        temp->cantidad += _dato;
        temp = temp->siguiente;
    }
}

string ListaPecVir::imprimir(){
    string texto = "";
    PecadoVirtud * temp = primerNodo;
    while(temp!=0){
        stringstream buff;
        buff << temp->cantidad;
        string cant = buff.str();
        texto += temp->nombre+"\t"+cant+"\n";
        temp = temp->siguiente;
    }
    return texto;
}

int ListaPecVir::cantidadPecVir(){
    PecadoVirtud * temp = primerNodo;
    int cantidadTotal=0;
    while(temp!=0) {
        cantidadTotal+=temp->cantidad;
        temp = temp->siguiente;
    }
    return cantidadTotal;
 }

int ListaPecVir::total(){
    int total=0;
    PecadoVirtud * temp = primerNodo;
    while(temp!=0){
        total += temp->cantidad;
        temp = temp->siguiente;
    }
    return total;
}
