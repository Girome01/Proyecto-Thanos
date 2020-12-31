#include "heap.h"

Heap::Heap(ListaDoble* _lista){
    lista = _lista;

}

bool Heap::isEmpty(){
    return size == 0;
}

int Heap::getMax(){
    if( !isEmpty() )
        return vect[1];
    return -1;
}

void Heap::shiftUp(int i){

    if( i > size)
        return;
    if( i == 1)
        return;
    if(vect[i] > vect[padre(i)]){
        std::swap(vect[padre(i)],vect[i]);
    }
    shiftUp(padre(i));
}

void Heap::insertar(int val){
    if(size+1 >= vect.size()){
        vect.push_back(0);
    }
    vect[++size] = val;
    shiftUp(size);
}

void Heap::shiftDown(int i){
    if( i > size)
        return;
    int swapID = i;
    if( hijoIzquierdo(i) <= size && vect[i] < vect[hijoIzquierdo(i)]){
        swapID = hijoIzquierdo(i);
    }
    if( hijoDerecho(i) <= size && vect[swapID] < vect[hijoDerecho(i)]){
        swapID = hijoDerecho(i);
    }
    if(swapID != i){
        std::swap(vect[i],vect[swapID]);
        shiftDown(swapID);
    }
    return;

}

int Heap::extractMax(){
    int maxNum = vect[1];
    std::swap(vect[1],vect[size--]);
    shiftDown(1);
    return maxNum;
}

void Heap::shiftUpCorvusGlaive(int i){

    if( i > size)
        return;
    if( i == 1)
        return;
    if(lista->BuscarEnPos(vect[i])->persona->pecados->total() >
            lista->BuscarEnPos(vect[padre(i)])->persona->pecados->total()){
        std::swap(vect[padre(i)],vect[i]);
    }
    shiftUpCorvusGlaive(padre(i));
}

void Heap::insertarCorvusGlaive(int val){
    if(size+1 >= vect.size()){
        vect.push_back(0);
    }
    vect[++size] = val;
    shiftUpCorvusGlaive(size);
}

void Heap::shiftDownCorvusGlaive(int i){
    if( i > size)
        return;
    int swapID = i;
    if( hijoIzquierdo(i) <= size &&
            lista->BuscarEnPos(vect[i])->persona->pecados->total() <
            lista->BuscarEnPos(vect[hijoIzquierdo(i)])->persona->pecados->total()){
        swapID = hijoIzquierdo(i);
    }
    if( hijoDerecho(i) <= size &&
        lista->BuscarEnPos(vect[swapID])->persona->pecados->total() <
        lista->BuscarEnPos(vect[hijoDerecho(i)])->persona->pecados->total()){
        swapID = hijoDerecho(i);
    }
    if(swapID != i){
        std::swap(vect[i],vect[swapID]);
        shiftDownCorvusGlaive(swapID);
    }
    return;

}

int Heap::extractMaxCorvusGlaive(){
    int maxNum = vect[1];
    std::swap(vect[1],vect[size--]);
    shiftDownCorvusGlaive(1);
    return maxNum;
}

void Heap::shiftUpMidnight(int i){

    if( i > size)
        return;
    if( i == 1)
        return;
    if(lista->BuscarEnPos(vect[i])->persona->virtudes->total() <
            lista->BuscarEnPos(vect[padre(i)])->persona->virtudes->total()){
        std::swap(vect[padre(i)],vect[i]);
    }
    shiftUpMidnight(padre(i));
}

void Heap::insertarMidnight(int val){
    if(size+1 >= vect.size()){
        vect.push_back(0);
    }
    vect[++size] = val;
    shiftUpMidnight(size);
}

void Heap::shiftDownMidnight(int i){
    if( i > size)
        return;
    int swapID = i;
    if( hijoIzquierdo(i) <= size &&
            lista->BuscarEnPos(vect[i])->persona->virtudes->total() >
            lista->BuscarEnPos(vect[hijoIzquierdo(i)])->persona->virtudes->total()){
        swapID = hijoIzquierdo(i);
    }
    if( hijoDerecho(i) <= size &&
        lista->BuscarEnPos(vect[swapID])->persona->virtudes->total() >
        lista->BuscarEnPos(vect[hijoDerecho(i)])->persona->virtudes->total()){
        swapID = hijoDerecho(i);
    }
    if(swapID != i){
        std::swap(vect[i],vect[swapID]);
        shiftDownMidnight(swapID);
    }
    return;

}

int Heap::extractMaxMidnight(){
    int maxNum = vect[1];
    std::swap(vect[1],vect[size--]);
    shiftDownMidnight(1);
    return maxNum;
}
