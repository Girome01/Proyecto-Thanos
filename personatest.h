#ifndef PERSONATEST_H
#define PERSONATEST_H
#include "persona.h"
#include "archivo.h"
#include <sstream>
#include <QList>
#include <cstdlib>
#include <iostream>
using namespace std;



struct PersonaTest{
    Archivo archivito;
    PersonaTest();

    vector<string> generarlistaNombres(string urlArchivo);
    void pruebaPersona();

};

#endif // PERSONATEST_H
