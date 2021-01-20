#ifndef ELIMINARHUMANOS_H
#define ELIMINARHUMANOS_H

struct ListaDoble;
#include "listadoble.h"
#include "listadeportes.h"
#include "heap.h"
#include "archivo.h"
#include "listablackdwarf.h"

#include <QDate>
#include <QTime>
#include <cstdlib>
#include <iostream>
using namespace std;

struct EliminarHumanos{
    int maximoNebula;
    Archivo archivoDeportes;
    string deporte;

    QString m_date = QDate::currentDate().toString();
    string date = m_date.toStdString();

    string datosNebula = "";
    string datTotNebula = "";
    int elimNebula = 0;
    int totalElimNebula = 0;

    string datosEbony = "";
    string datTotEbony = "";
    int elimEbony = 0;
    int totalElimEbony = 0;

    string datosBlack = "";
    string datTotBlack = "";
    int elimBlack = 0;
    int totalElimBlack = 0;

    string datosCorvus = "";
    string datTotCorvus = "";
    int elimCorvus = 0;
    int totalElimCorvus = 0;

    string datosMidnight = "";
    string datTotMidnight = "";
    int elimMidnight = 0;
    int totalElimMidnight = 0;

    EliminarHumanos();

    NodoPersona* obtenerHumNebula(ListaDoble* lista);
    void eliminarHumaNebula(NodoPersona* eliminar);
    void Nebula(ListaDoble* lista);

    NodoPersona* obtenerHumEbony(ListaDoble* lista,int id);
    void eliminarHumaEbony(NodoPersona* eliminar);
    void EbonyMaw(ListaDoble* lista, int id);

    ListaBlackDwarf* buscarHumBlack(int veces, string deporte, ListaDoble* mundo);
    void eliminarBlackDwarf(ListaBlackDwarf* eliminar, int veces, string deporte);
    vector<string>generarlistaNombres(string texto);
    void BlackDwarf(int veces /*, ListaDeportes* deportes*/, ListaDoble* mundo);

    Heap* crearListaCorvus(ListaDoble* mundo);
    void eliminarCorvus(Heap* eliminar,ListaDoble* mundo);
    void CorvusGlaive(ListaDoble* mundo);

    Heap* crearListaMidnight(ListaDoble* mundo);
    void eliminarMidnight(Heap* eliminar,ListaDoble* mundo);
    void Midnight(ListaDoble* mundo);

    string eliminarHumanos();

};

#endif // ELIMINARHUMANOS_H
