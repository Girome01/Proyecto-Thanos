#ifndef CONSULTAMUNDO_H
#define CONSULTAMUNDO_H
#include "arbol.h"
#include "listadoble.h"
#include "listadeportes.h"
#include "listaelimsalv.h"


struct ConsultaMundo{

    ConsultaMundo();
    Arbol *arbol= new Arbol();
    ListaDoble *listaDoble = new ListaDoble();

    string consultaHumanoID(int idConsultaHumano,NodoArbol *arbol);
    string consultaFamiliaID(int ConsultaFamiliaId, NodoArbol *arbol);
    string consultaAmigosID(int consultaAmigosId, NodoArbol *arbol);
    string consultaDeportes(string deporteConsultado);
    string humanosVivos();
    string humanosEliminados();
    string humanosSalvados();
};

#endif // CONSULTAMUNDO_H
