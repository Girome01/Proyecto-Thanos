#include "listadoble.h"

int ListaDoble::largo(){
    NodoPersona * temp = primerNodo;
    int largo = 0;
    while(temp != 0) {
        largo++;
        temp = temp->siguiente;
    }
    return largo;
}

bool ListaDoble::isEmpty(){
    return primerNodo == NULL;
}

void ListaDoble::insertarAlInicio (Persona* _persona){
    if (isEmpty())
        primerNodo = ultimoNodo = new NodoPersona (_persona);
    else{
        NodoPersona * nuevo = new NodoPersona(_persona);
        nuevo->siguiente = primerNodo;
        primerNodo->anterior = nuevo;
        primerNodo = nuevo;
    }
}

void ListaDoble::insertarAlFinal (Persona* _persona){
    if (isEmpty())
        primerNodo = ultimoNodo = new NodoPersona (_persona);
    else{
        NodoPersona * nuevo = new NodoPersona(_persona);
        nuevo->anterior = ultimoNodo;
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}

string ListaDoble::imprimir(){
    string texto = "";
    NodoPersona * tmp = primerNodo;
    while (tmp != NULL){
        texto += tmp->persona->imprimir()+"\n";
        tmp = tmp->siguiente;
    }
    return texto;
}

string ListaDoble::imprimirAmigos(){
    string texto = "";
    NodoPersona * tmp = primerNodo;
    while (tmp != NULL){
        texto += tmp->persona->imprimirAmigos()+"\n";
        tmp = tmp->siguiente;
    }
    return texto;
}

void ListaDoble::insertionSort(Persona* _persona){
    if(isEmpty()){
        insertarAlInicio(_persona);
    }else if(primerNodo->persona->ID > _persona->ID){
        insertarAlInicio(_persona);
    }else if(ultimoNodo->persona->ID < _persona->ID){
        insertarAlFinal(_persona);
    }else{
        NodoPersona* temp = primerNodo;
        while(temp->persona->ID < _persona->ID){
            //cout<<temp->persona->ID<<"---"<<_persona->ID<<endl;
            temp = temp->siguiente;
        }
        NodoPersona * nuevo = new NodoPersona(_persona);
        nuevo->siguiente = temp;
        nuevo->anterior = temp->anterior;
        temp->anterior->siguiente = nuevo;
        temp->anterior = nuevo;
    }
}

NodoPersona* ListaDoble::BuscarEnPos(int posicion){
        if (posicion <= 0){
            return primerNodo;
        }
        else if( posicion >= largo() ){
            return ultimoNodo;
        }
        else{
            NodoPersona * temp = primerNodo;
            for(int i = 1; i < posicion; i++){
                temp = temp->siguiente;
            }
            return temp->siguiente;
        }
    }

NodoPersona* ListaDoble::BuscarPorID(int ID){
    if (primerNodo->persona->ID == ID){
        return primerNodo;
    }
    else if(ultimoNodo->persona->ID == ID){
        return ultimoNodo;
    }
    else{
        NodoPersona * temp = primerNodo;
        for(int i = 1; i < largo(); i++){
            if(temp->siguiente->persona->ID == ID){
                return temp->siguiente;
            }
            temp = temp->siguiente;
        }
    }
    return NULL;
}

void ListaDoble::listaBlackDwarf(Persona* _persona){
    if(isEmpty()){
        insertarAlInicio(_persona);
    }else{
        insertarAlFinal(_persona);
    }
}

void ListaDoble::hacerPecar(){
    NodoPersona * temp = primerNodo;
    for(int i = 1; i < largo(); i++){
        temp->persona->pecados->modificarCantidad();
        temp = temp->siguiente;
    }
}

void ListaDoble::hacerAccionesBuenas(){
    NodoPersona * temp = primerNodo;
    for(int i = 1; i < largo(); i++){
        temp->persona->virtudes->modificarCantidad();
        temp = temp->siguiente;
    }
}

ListaArbol *ListaDoble::nodosArbol(int secuencia, int cant){
    ListaArbol *newList=new ListaArbol();

    if(primerNodo!=NULL){
        cout<<"ENTRO AL IF"<<endl;
        NodoPersona *tmp = primerNodo;
        int contador=secuencia-1;
        /*for(int i = 0; i < cant; i++){
            if(secuencia*1 > largo()){ // Si se pasa del largo de la lista se coloca el ultimo lugar
                newList->agregarHumanos(BuscarEnPos(largo()));
            }else{
                newList->agregarHumanos(BuscarEnPos(secuencia*i));
            }
        }*/
        do{
            contador++;
            if(contador==secuencia){
                cout<<"AGREGO HUMANO"<<endl;
                newList->agregarHumanos(tmp);
                cout<<"Logro agregar el humano"<<endl;
                contador=0;
            }
            tmp=tmp->siguiente;
        }while(tmp!=NULL);
    }
    return newList;
}
