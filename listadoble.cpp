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
        texto += tmp->persona->imprimir()+"\n";
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

void ListaDoble::insertionSort(Persona* _persona){
    if(isEmpty()){
        insertarAlInicio(_persona);
    }else if(primerNodo->persona->ID > _persona->ID){
        insertarAlInicio(_persona);
    }else if(ultimoNodo->persona->ID < _persona->ID){
        insertarAlFinal(_persona);
    }else{
        NodoPersona* temp = primerNodo;
        while(temp->siguiente->persona->ID < _persona->ID){
            temp = temp->siguiente;
        }
        NodoPersona * nuevo = new NodoPersona(_persona);
        nuevo->siguiente = temp->siguiente;
        nuevo->anterior = temp;
        temp->siguiente->anterior = nuevo;
        temp->siguiente = nuevo;
    }
}

NodoPersona* ListaDoble::BuscarEnPos(int posicion){
        if (posicion <= 0){
            return primerNodo;
        }
        else if( posicion >= largo() ){
            return ultimoNodo;
        }
        else{
            NodoPersona * temp = primerNodo;
            for(int i = 1; i < posicion; i++){
                temp = temp->siguiente;
            }
            return temp->siguiente;
        }
    }

NodoPersona* ListaDoble::BuscarPorID(int ID){
    if (primerNodo->persona->ID == ID){
        return primerNodo;
    }
    else if(ultimoNodo->persona->ID == ID){
        return ultimoNodo;
    }
    else{
        NodoPersona * temp = primerNodo;
        for(int i = 1; i < largo(); i++){
            if(temp->siguiente->persona->ID == ID){
                return temp->siguiente;
            }
            temp = temp->siguiente;
        }
    }
    return NULL;
}

void ListaDoble::listaBlackDwarf(Persona* _persona){
    if(isEmpty()){
        insertarAlInicio(_persona);
    }else{
        insertarAlFinal(_persona);
    }
}

void ListaDoble::hacerPecar(){
    NodoPersona * temp = primerNodo;
    for(int i = 1; i < largo(); i++){
        temp->persona->pecados->modificarCantidad();
        temp = temp->siguiente;
    }
}

void ListaDoble::hacerAccionesBuenas(){
    NodoPersona * temp = primerNodo;
    for(int i = 1; i < largo(); i++){
        temp->persona->virtudes->modificarCantidad();
        temp = temp->siguiente;
    }
}

