#ifndef SALVAHUMANOS_H
#define SALVAHUMANOS_H

#include "arbol.h"
#include "cola.h"
#include "listasalvahumanos.h"

#include <QDate>
#include <QTime>

struct salvaHumanos{
    Arbol *arbolHumanidad;
    Cola *colaNivel;
    ListaSalvaHumanos *listaHumanidad;

    QString m_date = QDate::currentDate().toString();
    string date = m_date.toStdString();

    //ANTMAN
    string recorridoHormiga="";
    string ramasSeleccionadas="";
    string rangoSeleccionado="";
    string datosAntman = "";
    string datTotAntman = "";
    int salvAntman = 0;
    int totalAntman = 0;

    //IRONMAN
    string recorridoBomba="";
    string bombasSeleccionadas="";
    string datosIronman = "";
    string datTotdatosIronman = "";
    int salvdatosIronman = 0;
    int totalIronman = 0;

    //THOR
    string nivelesSeleccionados= "";
    string datosThor = "";
    string datTotdatosThor = "";
    int salvdatosThor = 0;
    int totalThor = 0;

    //SPIDERMAN
    int cantidadTelarannas;
    string recorridoTelaranna="";
    string telarrannasSeleccionadas="";
    string datosSpiderman = "";
    string datTotdatosSpiderman = "";
    int salvdatosSpiderman = 0;
    int totalSpiderman = 0;


    salvaHumanos(Arbol *arbol);

    void recorrerArbolHormigas(int cantidadHorm);
    NodoArbol * mejorCaminoAntMan();
    void salvarAntman(int cantidadHormigas);
    void generarListaHumanidad(NodoArbol *nodo);
    void detonarBomba();
    void salvarEsposasPadres(NodoPersona *nodoPersona, string time);
    void salvarHijos(NodoPersona *primerNodo);
    void salvarIronman();
    void encontrarNiveles(NodoArbol *nodoA, int clevel,int nivelSalvado, Cola *colaNivel);
    void salvarAmigosDeEsposaPadres(Persona *nodoPersona, string time);
    void salvarAmigosDeHijos(NodoPersona *nodoPersona, string time);
    void salvarThor();
    void recorrerArbolAranna();
    void recorrerTeleranna(NodoArbol *nodo);
    void salvarSpiderman(NodoPersona *nodo);
};

#endif // SALVAHUMANOS_H
