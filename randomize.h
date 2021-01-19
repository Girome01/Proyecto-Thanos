#ifndef RANDOMIZE_H
#define RANDOMIZE_H

#include "persona.h"
#include "listapecvir.h"
#include <QRandomGenerator>
#include "listadeportes.h"

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
    bool validarPadres(Persona *hijo, Persona *padre);
    void agregarHijos(ListaDoble *personas, Persona *persona);
    int aletorioDia();
    string  aleatorioMes();
    int aletorioAno();
    bool aleatorioGenero();
    int edad();
    string estadoMarital();
    void asignarPareja(ListaDoble *personas);
    string generarRangoEtario(int anno);
    bool comprobarExistencia(Persona *amigo, Persona *personaActual);
    bool comprobarAmigos(Persona *amigo, Persona *personaActual);
    void agregarAmigos(ListaDoble *personas, Persona *personaActual);
    string generarProfesion(vector<string> listaProfesion);
    string generarCreencia(vector<string> listaCreencia);
    void generarPaisesVisitados(vector<string> listaPaisesVisitados, ListaSimple *paises);
    void generarDeportes(vector<string> listaDeportes, ListaDeportes *listadeportes);
};


#endif // RANDOMIZE_H
