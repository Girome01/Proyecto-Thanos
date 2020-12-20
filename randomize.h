#ifndef RANDOMIZE_H
#define RANDOMIZE_H

#include<fstream>
#include "persona.h"
#include "listapecvir.h"
#include <QRandomGenerator>

struct Randomize{
    Randomize(); //¿Tener la lista de personas en su constructor en vez de pasarla por todo lado como parámetro?

    string generarNombresM(vector<string> listaNombresM);
    string generarNombresF(vector<string> listaNombresF);
    string generarApellidos(vector<string> listaApellidos);
    bool estaID(ListaDoble *personas, int id);
    int generarId(ListaDoble *personas);
    string generarContinente();
    string generarPais(vector<string> listaPaises);
    void generarPecados(ListaPecVir *listapecvir);
    bool esHijoPosible(Persona *padre, Persona *hijo);
    void agregarHijos(ListaDoble *personas, Persona *persona);
    int aletorioDia();
    int aleatorioMes();
    int aletorioAno();
    bool aleatorioGenero();
    int edad(int ano);
    string estadoMarital();
    string RandomCreencia();
    string RandomProfesion();

};


#endif // RANDOMIZE_H
