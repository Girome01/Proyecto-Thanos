#include "mainwindow.h"

#include <QApplication>
#include "personatest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    PersonaTest* personaT=new PersonaTest;
    personaT->pruebaPersona();
    //w.show();

    return a.exec();
}
