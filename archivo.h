#ifndef ARCHIVO_H
#define ARCHIVO_H

#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

struct Archivo{
    Archivo();

    //QT ES UNA MIERDA 2.0
    //Hi :)
    //TKM GIL
    // _archivo tiene que llevar la extencion .txt
    void escribir(string _texto, string _archivo);
    string leer(string _archivo);
    //qt es una mierda
};

#endif // ARCHIVO_H
