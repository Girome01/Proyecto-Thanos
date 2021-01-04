#include "listahashmap.h"

ListaHashMap::ListaHashMap()
{
    primerNodo = ultimoNodo = NULL;
}

void ListaHashMap::insertarAlInicio (int _key){
    if (primerNodo == NULL){
        primerNodo = new NodoHashMap(_key);
        ultimoNodo = primerNodo;
    }
    else{
        NodoHashMap *nuevo = new NodoHashMap(_key);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

Persona* ListaHashMap::encontrarPorID(ListaDoble *personas, int id){
    NodoPersona *temp=personas->primerNodo;
    while(temp!=NULL){
        if(temp->persona->ID==id)
            return temp->persona;
        temp=temp->siguiente;
    }
    return NULL;
}
void ListaHashMap::matarPersonas(ListaDoble *personas){
    NodoHashMap *temp=primerNodo;
    while(temp!=NULL){
        Persona *matar=encontrarPorID(personas, temp->key);
        matar->vivo=false;
    }
}

void ListaHashMap::insertarAlFinal (int _key){
    if (primerNodo == NULL){
        primerNodo = new NodoHashMap(_key);
        ultimoNodo = primerNodo;
    }
    else{
        NodoHashMap *nuevo = new NodoHashMap(_key);
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}
