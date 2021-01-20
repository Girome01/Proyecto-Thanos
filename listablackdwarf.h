#ifndef LISTABLACKDWARF_H
#define LISTABLACKDWARF_H

#include "persona.h"

struct NodoBlackDwarf {
       Persona *personaBD;
       NodoBlackDwarf* siguiente;

       NodoBlackDwarf(Persona *_personaBD) {
         personaBD = _personaBD;
         siguiente = NULL;
       }
};

struct ListaBlackDwarf
{
    NodoBlackDwarf *primerNodo, *ultimoNodo;

    ListaBlackDwarf();

    void insertarAlInicio (Persona *_personaBD);
    void insertarAlFinal(Persona *_personaBD);
    string imprimir();
    int largoBD();
    NodoBlackDwarf* BuscarEnPos(int posicion);

};

#endif // LISTABLACKDWARF_H
