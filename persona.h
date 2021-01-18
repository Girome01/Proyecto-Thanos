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
#include "listaelimsalv.h"

#include <sstream>
#include <QList>
#include <cstdlib>
#include <iostream>
using namespace std;

struct Persona{
    int ID; //DONE
    int key;
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
    Persona* esposa=NULL; //*********Falta asignar esposa
    ListaDoble* hijos; //DONE
    ListaDeportes* deportes;
    string paisVive;
    string continenteVive;

    bool esHijo = false; // boolean si es hijo de alguien o no
    bool tienePareja=false;
    Persona* padre=NULL;
    Persona* madre=NULL;
    Randomize* random;

    ListaElimSalv* eliminado;
    ListaElimSalv* revivido;

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
