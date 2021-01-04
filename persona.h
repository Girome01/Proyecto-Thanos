#ifndef PERSONA_H
#define PERSONA_H

struct ListaPecVir;
struct ListaDoble;
struct ListaSimple;
struct Randomize;
#include "listapecvir.h"
#include "listadeportes.h"
#include "listadoble.h"
#include "listasimple.h"
#include "randomize.h"
#include "listadeportes.h"

#include <sstream>
#include <QList>
#include <cstdlib>
#include <iostream>
using namespace std;

struct Persona{
    int ID; //DONE
    bool vivo=true; // True si esta vivo false si esta muerto || DONE
    string nombre; //DONE
    string apellido; //DONE
    bool genero; // true = femenino, false = masculino || DONE
    string creencia;
    string profesion;
    string nacDia; //DONE
    string nacMes; //DONE
    string nacAno; //DONE
    ListaPecVir* pecados; //DONE
    ListaPecVir* virtudes; //DONE
    string rangoEtario;
    ListaSimple* paises;
    ListaDoble* amigos;
    string estadoMarital; //DONE
    Persona* esposa; //*********Falta asignar esposa
    ListaDoble* hijos; //semi-done
    ListaDeportes* deportes;
    string paisVive;
    string continenteVive;

    bool esHijo = false; // boolean si es hijo de alguien o no
    Persona* padre;
    Persona* madre;
    Randomize* random;

    Persona();

    string imprimir();
    string imprimirAmigos();
    string obtenerGenero();
    string obtenerVivo();
    string verificarAmigos();
    string verificarEsposa();
    string verificarHijos();
};

#endif // PERSONA_H
