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
    void mejorCaminoAntMan(NodoArbol *nodo);
    void salvarAntman(NodoArbol *nodo);
    void generarListaHumanidad(NodoArbol *nodo);
    void detonarBomba();
    void salvarHijos(NodoPersona *primerNodo);
    void salvarIronman();
    void encontrarNiveles(NodoArbol *nodoA, int clevel,int nivelSalvado, Cola *colaNivel);
    void salvarThor();
    void recorrerArbolAranna(NodoArbol *nodo);
    void salvarSpiderman(NodoArbol *nodo);
};

#endif // SALVAHUMANOS_H
