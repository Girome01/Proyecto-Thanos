#ifndef LISTADEPORTES_H
#define LISTADEPORTES_H

#include <sstream>
#include <cstdlib>
#include <iostream>

using namespace std;

struct NodoDeporte {
    string nombre;
    int vecesSemana;
    NodoDeporte* siguiente;

    NodoDeporte(int _vecesSemana, string _nombre) {
        vecesSemana = _vecesSemana;
        nombre = _nombre;
        siguiente = NULL;
    }
};


struct ListaDeportes {
    NodoDeporte *primerNodo, *ultimoNodo;

    ListaDeportes();

    void insertarAlInicio (int vecesSemana, string nombre);
    void insertarAlFinal(int vecesSemana, string nombre);
    int largo();
    int frecuenciaDeporte();
    bool esta(string deporte);
    NodoDeporte* obtener(string deporte);
    string imprimir();

};

#endif // LISTADEPORTES_H
