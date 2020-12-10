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

bool ListaPecVir::modificarCantidad(int _dato, string _nombre){
    PecadoVirtud * temp = primerNodo;
    while(temp!=0) {
        if(temp->nombre == _nombre){
            temp->cantidad += _dato;
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

string ListaPecVir::imprimir(){
    /*
    string texto = "";
    PecadoVirtud * temp = primerNodo;
    while(temp!=0) {
        texto += temp->nombre+"\t"+temp->cantidad+"\n";
        }
        temp = temp->siguiente;
    }
    return texto;
    */
    return "";
}
