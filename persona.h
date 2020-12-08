#ifndef PERSONA_H
#define PERSONA_H

struct ListaPecVir;
struct ListaDoble;
struct ListaSimple;
#include "listapecvir.h"
#include "listadoble.h"
#include "listasimple.h"

#include <QList>
#include <cstdlib>
#include <iostream>
using namespace std;

struct Persona{
    int ID;
    string nombre;
    string apeelido;
    bool genero; // true = femenino false = masculino
    string creencia;
    string profesion;
    string nacDia;
    string nacMes;
    string nacAno;
    ListaPecVir* pecados;
    ListaPecVir* virtudes;
    string rangoEtario;
    ListaSimple* paises;
    ListaDoble* amigos;
    string estadoMarital;
    Persona* esposa;
    ListaDoble* hijos;
    int ejerPorSema;
    ListaSimple* deportes;
    string paisVive;
    string continenteVive;

    Persona();
};

#endif // PERSONA_H
