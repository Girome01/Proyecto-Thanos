#ifndef COLA_H
#define COLA_H

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <QList>

#include "arbol.h"

using namespace std;


// estructura nodo para lista simple
struct Nodo {
       NodoArbol *nodo; // parte de datos

       Nodo* siguiente;// puntero para enlazar nodos
       // constructor

       Nodo(NodoArbol *_nodo){
                nodo = _nodo; // asigna los datos
                siguiente = NULL; // sig es null
       }

      void imprimir();

};

struct Cola {
       // solo con pN es suficiente
       Nodo *frente;

       Cola()
       {
            frente = NULL;
       }

       // encabezados de funcion
       void encolar (NodoArbol *_nodo);
       Nodo* desencolar ();
       Nodo* verFrente();
       bool vacia();
       void imprimir();
};

#endif // COLA_H
