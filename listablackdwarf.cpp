#include "listablackdwarf.h"

ListaBlackDwarf::ListaBlackDwarf()
{
    primerNodo = ultimoNodo = NULL;
}

void ListaBlackDwarf::insertarAlInicio (Persona *_personaBD){
    if (primerNodo == NULL){
        primerNodo = new NodoBlackDwarf(_personaBD);
        ultimoNodo = primerNodo;
    }
    else{
        NodoBlackDwarf *nuevo = new NodoBlackDwarf(_personaBD);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

void ListaBlackDwarf::insertarAlFinal (Persona *_personaBD){
    if (primerNodo == NULL){
        primerNodo = new NodoBlackDwarf(_personaBD);
        ultimoNodo = primerNodo;
    }
    else{
        NodoBlackDwarf *nuevo = new NodoBlackDwarf(_personaBD);
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}

string ListaBlackDwarf::imprimir(){
    string texto = "";
    NodoBlackDwarf * temp = primerNodo;
    while(temp!=0){
        texto += temp->personaBD->ID+"\n";
        temp = temp->siguiente;
    }
    return texto;
}

int ListaBlackDwarf::largoBD(){
    int largo=0;
    NodoBlackDwarf * temp = primerNodo;
    while(temp!=0){
        largo++;
        temp = temp->siguiente;
    }
    return largo;
}

NodoBlackDwarf* ListaBlackDwarf::BuscarEnPos(int posicion){
        if (posicion <= 0){
            return primerNodo;
        }
        else if( posicion >= largoBD() ){
            return ultimoNodo;
        }
        else{
            NodoBlackDwarf * temp = primerNodo;
            for(int i = 1; i < posicion; i++){
                temp = temp->siguiente;
            }
            return temp->siguiente;
        }
    }

