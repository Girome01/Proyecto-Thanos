
#include "listaarbol.h"

ListaArbol::ListaArbol(){
    primerNodo = NULL;
}

NodoListaArbol *ListaArbol::centroLista(){
    NodoListaArbol *tmp=primerNodo;
    if(largoLista()==1){
        return tmp;
    }
    //cout<<largoLista()/2<<endl;
    for(int i=0; i<largoLista()/2;i++){
        //cout<<"DENTRO DEL FOR DE CENTROLISTA"<<endl;
        tmp = tmp->siguiente;
    }
    return tmp;
}

ListaArbol *ListaArbol::primerMitad(){
    //cout<<"ENTRO A PRIMER MITAS"<<endl;
    ListaArbol *newList=new ListaArbol();
    NodoListaArbol *tmp = primerNodo;
    while(tmp != centroLista()){
        //cout<<"DENTRO DEL WHILE DE PRIMER MITAD"<<endl;
        newList->agregarHumanos(tmp->persona);
        //cout<<tmp->persona->persona->ID<<endl;
        tmp=tmp->siguiente;
    }
    return newList;
}

ListaArbol *ListaArbol::segundaMitad(){
    ListaArbol *newList=new ListaArbol();
    NodoListaArbol *tmp = centroLista()->siguiente;

    do{
        newList->agregarHumanos(tmp->persona);
        tmp=tmp->siguiente;
    }while(tmp!=NULL);
    return newList;
}

void ListaArbol::agregarHumanos(NodoPersona* persona){
    if (primerNodo == NULL){
        primerNodo = new NodoListaArbol(persona);
        ultimoNodo = primerNodo;
    }
    else{
        NodoListaArbol *nuevo = new NodoListaArbol(persona);
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}

int ListaArbol::largoLista(){
    NodoListaArbol * temp = primerNodo;
    int largo = 0;
    while(temp != 0) {
        largo++;
        temp = temp->siguiente;
    }
    return largo;
}

void ListaArbol::imprimir(){
    NodoListaArbol * temp = primerNodo;
    while(temp!=0){
        //cout<<temp->persona->persona->ID<<" -> ";
        temp = temp->siguiente;
    }
    cout<<endl<<endl;
}
