#ifndef ARBOL_H
#define ARBOL_H

struct ListaDoble;
#include "listadoble.h"
#include "listaarbol.h"
#define COUNT 10

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <QList>
using namespace std;

struct NodoArbol{
       NodoPersona* persona;
       NodoArbol* hijoizquierdo;
       NodoArbol* hijoderecho;
       int cantRecorridoHormiga=0;
       int marcaNodo;
       bool hormiga=false;
       bool detonarBomba=false;
       bool telaranna=false;

       NodoArbol(NodoPersona* _persona){
           cout<<"CREO EL NODO"<<endl;
            persona = _persona;
            cout<<"DEFINE SUS HIJOS COMO NULL"<<endl;
            hijoizquierdo = hijoderecho = NULL;
       }
};

struct Arbol{
    NodoArbol* raiz;
    QList<int> posiciones = {};
    string arbolS;
    int tempNumNivel=0;

    Arbol();

    void construirARBOL(ListaDoble* mundo,NodoArbol* nodo);

    int obtenerPor(int largoLista);
    void crearArray(int _posicion, int largoLista);

    NodoArbol* agregarNodo(NodoArbol *nodo, NodoPersona *personaAgregar);
    void insertarNodo(NodoListaArbol *NodoPersona);
    void llenarArbol(ListaArbol *lista);
    void crearArbol(int largoLista, ListaDoble *listaHumanidad);


    void imprimirArray();
    QList<int> listaMenores(QList<int> _posiciones, int pos);
    QList<int> listaMayores(QList<int> _posiciones, int pos);
    void inOrden(NodoArbol* nodo);
    void print2DUtil(NodoArbol* root, int space);
    void print2D(NodoArbol *root);
    int profundidad(NodoArbol *raiz);
    void encontrarNiveles (NodoArbol *nodoA, int clevel,int nivelSalvado);
    void marcarNiveles();
};

#endif // ARBOL_H
