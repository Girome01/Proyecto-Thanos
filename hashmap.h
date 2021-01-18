#ifndef HASHMAP_H
#define HASHMAP_H

#include <unordered_map>
#include "persona.h"
#include "QDate"
#include "listahashmap.h"

struct HashMap{
    ListaDoble *personas;
    ListaHashMap hashtable [122][11];
    /*Se genera una matriz de 122 (filas -) y 11 (columnas |), esto con la idea de
     * que los annos van del 1900 al 2021, y existe una fila y columna extra con los annos
     * y los numeros del 1 al 10 */

  HashMap(ListaDoble *poblacion);

  void generarHashMap(); //1
  void generarAnnos(); //2
  void generarNum(); //3
  int funcionHash(Persona *persona);
  void insertarElemento(Persona *persona); // Hacer una funcion para crear
  void eliminarPersonasAnno(int _key);
  void eliminarPersonasNivel(int _key);
  void eliminarPersonasNivelAnno(int _keyA, int keyN);
  void imprimirHM();
  void crearHashmap(ListaDoble* mundo);
};

#endif // HASHMAP_H
