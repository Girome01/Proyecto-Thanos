#include "arbol.h"
#include "personatest.h"
#include "mainwindow.h"

#include <QApplication>

#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    PersonaTest* personaT=new PersonaTest;
    personaT->pruebaPersona();
    //w.show();

    /*
    Arbol* arbol = new Arbol();
    int total = arbol->obtenerPor(1350);
    cout<<"Num total "<<total<<endl;
    arbol->crearArray(total, 1350);
    arbol->imprimirArray();
    */

    return a.exec();
}
