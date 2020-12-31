#ifndef HEAP_H
#define HEAP_H

#include "listadoble.h"

#include <qvector.h>

#include <cstdlib>
#include <iostream>
using namespace std;

struct Heap{
    int size = 0;
    QVector<int> vect = {-1};
    ListaDoble* lista;

    Heap(ListaDoble* _lista);

    int padre(int i){ return (i/2); }//i>>1
    int hijoIzquierdo(int i ){ return (i*2); }//i<<1
    int hijoDerecho(int i ){ return (i*2)+1; }//(i<<1)+1

    bool isEmpty();
    int getMax();
    void shiftUp(int i);
    void insertar(int val);
    int extractMax();
    void shiftDown(int i);

    void shiftUpCorvusGlaive(int i);
    void insertarCorvusGlaive(int val);
    void shiftDownCorvusGlaive(int i);
    int extractMaxCorvusGlaive();

    void shiftUpMidnight(int i);
    void insertarMidnight(int val);
    void shiftDownMidnight(int i);
    int extractMaxMidnight();

};

#endif // HEAP_H
