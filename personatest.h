#ifndef PERSONATEST_H
#define PERSONATEST_H
#include "persona.h"
#include "archivo.h"
#include "arbol.h"
#include <sstream>
#include <QList>
#include <cstdlib>
#include <iostream>
using namespace std;



struct PersonaTest{
    Archivo archivito;
    ListaDoble *personas;
    PersonaTest(ListaDoble *mundo);

    vector<string> generarlistaNombres(string urlArchivo);
    void crearPersona(int cantidad);

};

#endif // PERSONATEST_H
