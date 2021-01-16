#include "salvahumanos.h"

salvaHumanos::salvaHumanos(Arbol *arbol)
{
    arbolHumanidad=arbol;
    colaNivel=new Cola();
    listaHumanidad=new ListaSalvaHumanos();
}

void salvaHumanos::recorrerArbolHormigas(int cantidadHorm){ //Primera funcion de Antman
    for(int i=0; i<cantidadHorm;i++){ //Cantidad de hormigas que se desean crear, INPUT
        recorridoHormiga+="Soy la hormiga "+to_string(i)+" y este fue mi recorrido: \n";
        NodoArbol *temp=arbolHumanidad->raiz; //Raiz
        while(temp!=NULL){
            int indice=int(QRandomGenerator::global()->bounded(0, 2)); //Un random de 0 a 1
            if(indice==0){
                temp->cantRecorridoHormiga++; //Aumenta en 1 el recorrido pasado por ese nodo
                temp->hormiga=true; //Contiene una feromona
                temp=temp->hijoizquierdo; //Si es igual a cero, entonces se va por la izq
            }else{
                temp->cantRecorridoHormiga++; //Aumenta en 1 el recorrido pasado por ese nodo
                temp->hormiga=true; //Contiene una feromona
                temp=temp->hijoderecho; //Sino, por la derecha
            }
            recorridoHormiga+=to_string(temp->marcaNodo)+"-";

        }
    }
}

NodoArbol * salvaHumanos::mejorCaminoAntMan(){ //Tercera funcion
    int cantidadMayor=0;
    generarListaHumanidad(arbolHumanidad->raiz);
    NodoSalvar *temp=listaHumanidad->primerNodo;
    NodoArbol *nodoMayor=NULL;
    while(temp!=NULL){
        if(temp->nodoA->cantRecorridoHormiga>cantidadMayor){
            cantidadMayor=temp->nodoA->cantRecorridoHormiga;
            temp->nodoA->cantRecorridoHormiga=0;
            nodoMayor=temp->nodoA;
        }
        temp=temp->siguiente;
    }
    return nodoMayor;
}

void salvaHumanos::salvarAntman(){ //Segunda funcion
    NodoArbol *destino=mejorCaminoAntMan();
    NodoArbol *inicioArbol=mejorCaminoAntMan();
    ramasSeleccionadas+="Las ramas seleccionadas son: "+to_string(inicioArbol->marcaNodo)+" y "+to_string(destino->marcaNodo);
    NodoPersona *inicio=inicioArbol->persona;
    if(destino!=NULL && inicio!=NULL){
        while(inicio->persona->ID!=destino->persona->persona->ID){
                if(!inicio->persona->vivo){
                    inicio->persona->vivo=true;
                }
                inicio=inicio->siguiente;
        }
    }
}

void salvaHumanos::generarListaHumanidad(NodoArbol *nodo){ //Primera funcion de IronMan
    if (nodo != NULL){ //Genera una lista con los nodos que contienen a la humanidad
        //listaHumanidad->insertarAlFinal(nodo->hijoderecho);
        generarListaHumanidad(nodo->hijoderecho);
        listaHumanidad->insertarAlFinal(nodo);
        //listaHumanidad->insertarAlFinal(nodo->hijoizquierdo);
        generarListaHumanidad(nodo->hijoizquierdo);
    }
}

void salvaHumanos::detonarBomba(){ //Segunda funcion de IronMan
    NodoSalvar *temp=listaHumanidad->primerNodo;
    int porcentaje=int(QRandomGenerator::global()->bounded(40,61)); //Cuanto porciento va a explotar
    int cantidadExplosion=listaHumanidad->largo()*(porcentaje/100); //Cantidad de explosiones que se daran
    for(int i=0; i<cantidadExplosion; i++){
        while(temp!=NULL){
            int indice=int(QRandomGenerator::global()->bounded(0, 2)); //Random de 0 a 1
            if(indice==0){ //Esto es para que no se detonen solo los primeros nodos
                temp->nodoA->detonarBomba=true; //Detona la bomba en este temp
                temp=temp->siguiente;
            }else{
                if(temp->siguiente!=NULL)
                    temp->siguiente->nodoA->detonarBomba=true; //Detona la bomba en el temp sig
                temp=temp->siguiente;
            }
        }
    }
}

void salvaHumanos::salvarHijos(NodoPersona *primerNodo){ //Cuarta funcion de IronMan
    NodoPersona *temp=primerNodo;
    while(temp!=NULL){
        if(!temp->persona->vivo){
            temp->persona->vivo=true;
            NodoPersona *temp2=temp->persona->hijos->primerNodo;
            while(temp2!=NULL){
                if(!temp->persona->vivo){
                    temp->persona->vivo=true;
                }
            }
        }
    }
}

void salvaHumanos::salvarIronman(){ //Tercera funcion de IronMan
   NodoSalvar *temp=listaHumanidad->primerNodo;
   NodoPersona *temp2=listaHumanidad->primerNodo->nodoA->persona;
   while(temp!=NULL){
       if(temp->nodoA->detonarBomba){
            while(temp2->persona->ID!=temp->siguiente->nodoA->persona->persona->ID){
                salvarHijos(temp2->persona->hijos->primerNodo);
                temp2=temp2->siguiente;
            }
       }
       temp=temp->siguiente;
   }
}

void salvaHumanos::encontrarNiveles(NodoArbol *nodoA, int clevel,int nivelSalvado, Cola *colaNivel){ //Segunda funcion de Thor
    if (clevel == nivelSalvado) {
      colaNivel->encolar(nodoA);
    }else {
      if (nodoA->hijoizquierdo != NULL)
        encontrarNiveles(nodoA->hijoizquierdo, clevel + 1, nivelSalvado, colaNivel);
      }if (nodoA->hijoderecho != NULL)
        encontrarNiveles(nodoA->hijoderecho, clevel + 1, nivelSalvado, colaNivel);
 }

void salvaHumanos::salvarThor(){ //Primera funcion de Thor
    int nivel=int(QRandomGenerator::global()->bounded(1,arbolHumanidad->profundidad(arbolHumanidad->raiz))); //Profundidad del arbol para saber que tan lejos puede ir el random
    encontrarNiveles(arbolHumanidad->raiz, 0, nivel, colaNivel); //Encontrar los nodos con ese nivel y guardarlos en una cola
    Nodo *temp=colaNivel->frente; //Recorrer la cola
    while(temp!=NULL){
        NodoPersona *temp2=temp->nodo->persona;
        while(temp2->persona->ID!=temp->nodo->hijoderecho->persona->persona->ID){
            //COMO DETENER EL RECORRIDO?????????***************************
            if(!temp->nodo->persona->persona->vivo){
                temp->nodo->persona->persona->vivo=true;
            }
            temp2=temp2->siguiente;
        }
        temp=temp->siguiente;
    }
}

void salvaHumanos::recorrerArbolAranna(){ //Primera funcion Spiderman
    NodoArbol *temp=arbolHumanidad->raiz;
    cantidadTelarannas=0;
    temp->telaranna=true;
    while(temp!=NULL){
        int indice=int(QRandomGenerator::global()->bounded(0, 4)); //Randomly ira poniendo telerannas con nums del 0 al 3
        if(indice==0){ //Si es cero entonces por la izq
            temp=temp->hijoizquierdo;
            temp->telaranna=true; //Tendra telaranna
            cantidadTelarannas++;
        }else if(indice==1){
            temp=temp->hijoderecho; //Si es 1 entonces por la der
            temp->telaranna=true; //Tendra teleranna
            cantidadTelarannas++;
        }else if(indice==2){
            temp=temp->hijoizquierdo; //Si es 2 se va por la izq porque me da la gana, pero no va a poner telaranna
        }else{
            temp=temp->hijoizquierdo; //Lo mismo que arriba, pero con 3
        }
      }
}

void salvaHumanos::recorrerTeleranna(NodoArbol *nodo){ //Segunda funcion Spiderman
    if (nodo != NULL){ //Recorrido InOrden
      recorrerTeleranna(nodo->hijoizquierdo);
      if(nodo->telaranna && nodo->hijoderecho==NULL && nodo->hijoizquierdo==NULL){ //Si el nodo es hoja y tiene telaranna
         salvarSpiderman(nodo->persona); //Envia el nodo persona que se encuentre alli
      }
      recorrerTeleranna(nodo->hijoderecho);
    }
}

void salvaHumanos::salvarSpiderman(NodoPersona *nodo){ //Tercera funcion Spiderman
    NodoPersona *temp=nodo;
    while(temp!=NULL && cantidadTelarannas>0){ //Recorre las personas hacia la derecha mientras se cumpla la cantidad de Telerannas deseada
        temp->persona->vivo=true;
        temp=temp->anterior; //Derecha, o sea los menores
        cantidadTelarannas--;
    }
}
