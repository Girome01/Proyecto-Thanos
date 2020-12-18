#include "insertSort.h"

insertSort::insertSort(){

}

void insertSort::insertionSort(ListaDoble* lista,Persona* _persona){
    if(lista->isEmpty()){
        lista->insertarAlInicio(_persona);
    }else if(lista->primerNodo->persona->ID > _persona->ID){
        lista->insertarAlInicio(_persona);
    }else if(lista->primerNodo->persona->ID < _persona->ID){
        lista->insertarAlFinal(_persona);
    }else{
        NodoPersona* temp = lista->primerNodo->siguiente;
        while(temp->siguiente->persona->ID < _persona->ID){
            temp = temp->siguiente;
        }
        NodoPersona * nuevo = new NodoPersona(_persona);
        nuevo->siguiente = temp->siguiente;
        nuevo->anterior = temp;
        temp->siguiente->anterior = nuevo;
        temp->siguiente = nuevo;
    }

    /*
  for (int step = 1; step < lista->largo(); step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }*/
}
