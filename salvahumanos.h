#ifndef SALVAHUMANOS_H
#define SALVAHUMANOS_H

#include "arbol.h"
#include "cola.h"
#include "listasalvahumanos.h"

struct salvaHumanos{
    Arbol *arbolHumanidad;
    Cola *colaNivel;
    ListaSalvaHumanos *listaHumanidad;
    int cantidadTelarannas;

    salvaHumanos(Arbol *arbol);

    void recorrerArbolHormigas(int cantidadHorm);
    NodoArbol * mejorCaminoAntMan();
    void salvarAntman();
    void generarListaHumanidad(NodoArbol *nodo);
    void detonarBomba();
    void salvarHijos(NodoPersona *primerNodo);
    void salvarIronman();
    void encontrarNiveles(NodoArbol *nodoA, int clevel,int nivelSalvado, Cola *colaNivel);
    void salvarThor();
    void recorrerArbolAranna();
    void recorrerTeleranna(NodoArbol *nodo);
    void salvarSpiderman(NodoPersona *nodo);
};

#endif // SALVAHUMANOS_H
