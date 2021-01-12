#include "arbol.h"
#include <math.h>

Arbol::Arbol(){
    raiz = NULL;
}

int Arbol::obtenerPor(int largoLista){
    int unoPorciento = largoLista * 0.01;
    int total = 0;
    int i = 0;
    while ( total < unoPorciento) {
        total = pow(2,i)-1;
        i++;
    }
    return total;
}

void Arbol::crearArray(int _posicion, int largoLista){
    int lugar = largoLista / _posicion;
    cout<<"Lugar   "<<lugar<<endl;
    for(int i = 0; i < _posicion; i++){
        if(lugar*1 > largoLista){
            this->posiciones.append(largoLista);
            cout<<"Posiciones   "<<i<<" = "<<largoLista<<endl;
        }else{
            this->posiciones.append(lugar*i);
            cout<<"Posiciones   "<<i<<" = "<<lugar*i<<endl;
        }
    }
}

void Arbol::imprimirArray(){
    cout<<"Imprimir QList "<<endl;
    for(int i = 0; i < posiciones.length();i++){
        cout<<posiciones.at(i)<<" -> "<<endl;
    }
}

QList<int> Arbol::listaMenores(QList<int> _posiciones, int pos){
    QList<int> menores = {};
    for(int i = 0; i < pos; i++){
        menores.append(_posiciones.at(i));
    }
    return menores;
}

QList<int> Arbol::listaMayores(QList<int> _posiciones, int pos){
    QList<int> mayores = {};
    for(int i = pos+1; i < _posiciones.size(); i++){
        mayores.append(_posiciones.at(i));
    }
    return mayores;
}

void Arbol::crearArbol(QList<int> lista, ListaDoble* personas, NodoArbol* nodo){
    int pos = lista.size()/2;
    if(nodo == NULL){
        nodo = new NodoArbol(personas->BuscarEnPos(lista.at(pos)));
    }
    if(lista.size() > 1){
        crearArbol(listaMayores(lista,pos),personas,nodo->hijoderecho);
        crearArbol(listaMenores(lista,pos),personas,nodo->hijoizquierdo);
    }
}

void Arbol::inOrden(NodoArbol* nodo)
{
   if (nodo != NULL)
   {
     inOrden(nodo->hijoizquierdo);
     cout << nodo->persona->persona->imprimir()<< " -> ";
     inOrden(nodo->hijoderecho);
   }
}

int Arbol::profundidad(NodoArbol *raiz){
    if (raiz == NULL)
           return 0;
   else {
       int alturaIzq = profundidad(raiz->hijoizquierdo);
       int alturaDer = profundidad(raiz->hijoizquierdo);
       if (alturaIzq >= alturaDer)
            return alturaIzq + 1;
       else
            return alturaDer + 1;
   }
}

