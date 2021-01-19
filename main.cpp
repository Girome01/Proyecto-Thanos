#include "arbol.h"
#include "personatest.h"
#include "mainwindow.h"
#include "heap.h"

#include <QApplication>

#include <QDate>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* MainWindow w;
    PersonaTest* personaT=new PersonaTest;
    personaT->pruebaPersona();
    //w.show();*/

    /*
    Arbol* arbol = new Arbol();
    int total = arbol->obtenerPor(1350);
    cout<<"Num total "<<total<<endl;
    arbol->crearArray(total, 1350);
    arbol->imprimirArray();
    Heap* P = new Heap();
    if(P->isEmpty()){
        cout<<"Respuesta correcta"<<endl;
    }else{
        cout<<"Error con nuestra funcion isEmpty"<<endl;
    }
    P->insertar(10);
    P->insertar(120);
    P->insertar(34);
    P->insertar(41);
    P->insertar(5);
    cout<< P->getMax()<<endl;
    P->extractMax();
    cout<< P->getMax()<<endl;

    if(P->isEmpty()){
        cout<<"Error con nuestra funcion isEmpty"<<endl;
    }else{
        cout<<"Respuesta correcta"<<endl;
    }*/
    /*
    QString m_date = QDate::currentDate().toString();
    string str = m_date.toStdString();
    cout<<str<<endl;

    QString m_time = QTime::currentTime().toString();
    string time = m_time.toStdString();
    cout<< time << endl;

    string nombreArchivo="pls.txt";
    string exe="D:\\Documents\\ProyectoThanos\\ProyectoThanos\\EnviarCorreosQT1.exe";
    string q=" D:/Documents/ProyectoThanos/ProyectoThanos/";
    q.append(nombreArchivo);
    exe.append(q);
    exe.append(" 0 1 ");
    //system("D:\\Documents\\ProyectoThanos\\ProyectoThanos\\EnviarCorreosQT1.exe D:/Documents/ProyectoThanos/ProyectoThanos/pls.txt 0 1 ");
    system(exe.c_str());
    */
    PersonaTest *persona=new PersonaTest();
    persona->crearPersona(10);

    return 1;

}
