#ifndef HASHMAP_H
#define HASHMAP_H

#include <unordered_map>
#include "persona.h"
#include "listahashmap.h"

struct HashMap{
    ListaDoble *personas;
    ListaHashMap hashtable [122][11];
    /*Se genera una matriz de 122 (filas -) y 11 (columnas |), esto con la idea de
     * que los annos van del 1900 al 2021, y existe una fila y columna extra con los annos
     * y los numeros del 1 al 10 */

    string datosThanos = "";
    string datTotThanos= "";
    int elimThanos = 0;
    int totalElimThanos = 0;

  HashMap(ListaDoble *poblacion);

  void generarHashMap();
  void generarAnnos();
  void generarNum();
  int funcionHash(Persona *persona);
  void insertarElemento(Persona *persona);
  void eliminarPersonasAnno(int _key);
  void eliminarPersonasNivel(int _key);
  void eliminarPersonasNivelAnno(int _keyA, int keyN);
  void imprimirHM();
};

#endif // HASHMAP_H
