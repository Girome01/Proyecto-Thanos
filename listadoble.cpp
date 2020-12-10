#include "listadoble.h"

int ListaDoble::largo(){
    NodoPersona * temp = primerNodo;
    int largo = 0;
    while(temp != 0) {
        largo++;
        temp = temp->siguiente;
    }
    return largo;
}

bool ListaDoble::isEmpty(){
    return primerNodo == NULL;
}

void ListaDoble::insertarAlInicio (Persona* _persona){
    if (isEmpty())
        primerNodo = ultimoNodo = new NodoPersona (_persona);
    else{
        NodoPersona * nuevo = new NodoPersona(_persona);
        nuevo->siguiente = primerNodo;
        primerNodo->anterior = nuevo;
        primerNodo = nuevo;
    }
}

void ListaDoble::insertarAlFinal (Persona* _persona){
    if (isEmpty())
        primerNodo = ultimoNodo = new NodoPersona (_persona);
    else{
        NodoPersona * nuevo = new NodoPersona(_persona);
        nuevo->anterior = ultimoNodo;
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}

string ListaDoble::imprimir(){
    string texto = "";
    NodoPersona * tmp = primerNodo;
    while (tmp != NULL){
        texto += tmp->persona->imprimir()+"\n******************\n";
        tmp = tmp->siguiente;
    }
    return texto;
}

string ListaDoble::imprimirAmigos(){
    string texto = "";
    NodoPersona * tmp = primerNodo;
    while (tmp != NULL){
        texto += tmp->persona->imprimirAmigos()+"\n";
        tmp = tmp->siguiente;
    }
    return texto;
}
