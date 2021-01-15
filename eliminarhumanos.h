#ifndef ELIMINARHUMANOS_H
#define ELIMINARHUMANOS_H

struct ListaDoble;
#include "listadoble.h"
#include "listadeportes.h"
#include "heap.h"

#include <QDate>
#include <QTime>
#include <cstdlib>
#include <iostream>
using namespace std;

struct EliminarHumanos{
    int maximoNebula;
    QTime time = QTime();

    string datosNebula = "";
    string datTotNebula = "";

    string datosEbony = "";
    string datTotEbony = "";

    string datosBlack = "";
    string datTotBlack = "";

    string datosCorvus = "";
    string datTotCorvus = "";

    string datosMidnight = "";
    string datTotMidnight = "";

    EliminarHumanos();

    NodoPersona* obtenerHumNebula(ListaDoble* lista);
    void eliminarHumaNebula(NodoPersona* eliminar);
    void Nebula(ListaDoble* lista);

    NodoPersona* obtenerHumEbony(ListaDoble* lista);
    void eliminarHumaEbony(NodoPersona* eliminar);
    void EbonyMaw(ListaDoble* lista);

    ListaDoble* buscarHumBlack(int veces, string deporte, ListaDoble* mundo);
    void eliminarBlackDwarf(ListaDoble* eliminar, int veces, string deporte);
    //Falta agregar uno funcion que obtenga un deporte random
    void BlackDwarf(int veces /*, ListaDeportes* deportes*/, ListaDoble* mundo);

    Heap* crearListaCorvus(ListaDoble* mundo);
    void eliminarCorvus(Heap* eliminar,ListaDoble* mundo);
    void CorvusGlaive(ListaDoble* mundo);

    Heap* crearListaMidnight(ListaDoble* mundo);
    void eliminarMidnight(Heap* eliminar,ListaDoble* mundo);
    void Midnight(ListaDoble* mundo);

};

#endif // ELIMINARHUMANOS_H
