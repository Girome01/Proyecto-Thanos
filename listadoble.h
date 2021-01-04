#ifndef LISTADOBLE_H
#define LISTADOBLE_H

struct Persona;
#include "persona.h"

#include <cstdlib>
#include <iostream>
using namespace std;


struct NodoPersona{
    Persona* persona;
    NodoPersona * siguiente;
    NodoPersona * anterior;

    NodoPersona(Persona* _persona){
        persona = _persona;
        siguiente = anterior = NULL;
    }

    NodoPersona(){
        persona = 0;
        siguiente = anterior = NULL;
    }

    NodoPersona(Persona* _persona, NodoPersona * _sig, NodoPersona * _ant){
        persona = _persona;
        siguiente = _sig;
        anterior = _ant;
    }
};

struct ListaDoble{
    NodoPersona * primerNodo;
    NodoPersona * ultimoNodo;

    ListaDoble(){
        primerNodo = ultimoNodo = NULL;
    }

    int largo();
    bool isEmpty();
    void insertarAlInicio (Persona* _persona);
    void insertarAlFinal (Persona* _persona);
    string imprimir();
    string imprimirAmigos();
    void insertionSort(Persona* _persona);
    NodoPersona* BuscarEnPos(int posicion);
    NodoPersona* BuscarPorID(int ID);
    void listaBlackDwarf(Persona* _persona);

};

#endif // LISTADOBLE_H
