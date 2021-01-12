#include "salvahumanos.h"

salvaHumanos::salvaHumanos(Arbol *arbol)
{
    arbolHumanidad=arbol;
    colaNivel=new Cola();
}


void salvaHumanos::recorrerArbolHormigas(int cantidadHorm){ //Primera funcion de Antman
    NodoArbol *temp=arbolHumanidad->raiz; //Raiz
    for(int i=0; i<cantidadHorm;i++){ //Cantidad de hormigas que se desean crear, INPUT
        while(temp!=NULL){
            int indice=int(QRandomGenerator::global()->bounded(0, 2)); //Un random de 0 a 1
            if(indice==0){
                temp=temp->hijoizquierdo; //Si es igual a cero, entonces se va por la izq
                temp->cantRecorridoHormiga++; //Aumenta en 1 el recorrido pasado por ese nodo
                temp->hormiga=true; //Contiene una feromona
            }else{
                temp=temp->hijoderecho; //Sino, por la derecha
                temp->cantRecorridoHormiga++; //Aumenta en 1 el recorrido pasado por ese nodo
                temp->hormiga=true; //Contiene una feromona
            }
            /*
            temp->cantRecorridoHormiga++; //Aumenta en 1 el recorrido pasado por ese nodo
            temp->hormiga=true; //Contiene una feromona
            */
        }
    }
}

void salvaHumanos::mejorCaminoAntMan(NodoArbol *nodo){ //Tercera funcion
    for(int i=0; i<2; i++){ //Necesario recorrerlo dos veces para encontrar los dos mejores caminos y marcarlos
        if (nodo != NULL){
          if(nodo->hijoizquierdo->cantRecorridoHormiga>nodo->hijoderecho->cantRecorridoHormiga
          && nodo->hijoizquierdo->hijoderecho==NULL && nodo->hijoizquierdo->hijoizquierdo==NULL){ //Basicamente si es el camino con mayor recorrido y si es una hoja en el lado izq
             nodo->hijoizquierdo->mejorCamino=true;
             nodo->hijoizquierdo->cantRecorridoHormiga=0; //Lo iguala a cero porque sino siempre va a tomar este como el mejor camino.

          }else if(nodo->hijoderecho->cantRecorridoHormiga>nodo->hijoizquierdo->cantRecorridoHormiga
           && nodo->hijoderecho->hijoderecho==NULL && nodo->hijoderecho->hijoizquierdo==NULL){ //Basicamente si es el camino con mayor recorrido y si es una hoja en el lado der
              nodo->hijoderecho->mejorCamino=true;
              nodo->hijoderecho->cantRecorridoHormiga=0; //Lo iguala a cero porque sino siempre va a tomar este como el mejor camino.
          }
          salvarAntman(nodo->hijoizquierdo);
          salvarAntman(nodo->hijoderecho);
        }
    }
}

void salvaHumanos::salvarAntman(NodoArbol* nodo){ //Segunda funcion
    mejorCaminoAntMan(nodo); //Marca los dos mejores caminos
    if (nodo != NULL){
         if(nodo->hijoizquierdo->mejorCamino){
             //Pendiente
         }else{

         }
         salvarAntman(nodo->hijoizquierdo);
         salvarAntman(nodo->hijoderecho);
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

//PENDIENTE
void salvaHumanos::salvarHijos(NodoPersona *primerNodo){ //Cuarta funcion de IronMan
    NodoPersona *temp=primerNodo;
    while(temp!=NULL){
        if(!temp->persona->vivo){
            temp->persona->vivo=true;
        }
    }
}

//PENDIENTE
void salvaHumanos::salvarIronman(){ //Tercera funcion de IronMan
   NodoSalvar *temp=listaHumanidad->primerNodo;
   while(temp!=NULL){
       if(temp->nodoA->detonarBomba){
           NodoPersona *nodoFamDer=temp->nodoA->hijoderecho->persona->persona->hijos->primerNodo;
           NodoPersona *nodoFamIzq=temp->nodoA->hijoizquierdo->persona->persona->hijos->primerNodo;
           salvarHijos(nodoFamDer); //Salvar hijos
           salvarHijos(nodoFamDer->persona->hijos->primerNodo); //Salvar hijos de los hijos
           salvarHijos(nodoFamIzq);
           salvarHijos(nodoFamIzq->persona->hijos->primerNodo);
       }
   }
}

void salvaHumanos::encontrarNiveles(NodoArbol *nodoA, int clevel,int nivelSalvado, Cola *colaNivel){ //Segunda funcion de Thor
    if (clevel == nivelSalvado) {
      colaNivel->encolar(nodoA);
    }else {
      if (nodoA->hijoderecho != NULL)
        encontrarNiveles(nodoA->hijoderecho, clevel + 1, nivelSalvado, colaNivel);
      if (nodoA->hijoizquierdo != NULL)
        encontrarNiveles(nodoA->hijoizquierdo, clevel + 1, nivelSalvado, colaNivel);
    }
 }

//PENDIENTE
void salvaHumanos::salvarThor(){ //Primera funcion de Thor
    int nivel=int(QRandomGenerator::global()->bounded(1,arbolHumanidad->profundidad(arbolHumanidad->raiz))); //Profundidad del arbol para saber que tan lejos puede ir el random
    encontrarNiveles(arbolHumanidad->raiz, 0, nivel, colaNivel); //Encontrar los nodos con ese nivel y guardarlos en una cola
    Nodo *temp=colaNivel->frente; //Recorrer la cola
    while(temp!=NULL){
        NodoPersona *temp2=temp->nodo->persona;
        while(temp2!=NULL){
            if(!temp->nodo->persona->persona->vivo){
                temp->nodo->persona->persona->vivo=true;
            }
            temp2=temp2->siguiente;
        }
        temp=temp->siguiente;
    }
}

void salvaHumanos::recorrerArbolAranna(NodoArbol *nodo){
    NodoArbol *temp=arbolHumanidad->raiz;
    cantidadTelarannas=0;
    temp->telaranna=true;
    if (nodo != NULL){
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
}

//PENDIENTE
void salvaHumanos::salvarSpiderman(NodoArbol *nodo){
    if (nodo != NULL){
      if(nodo->hijoizquierdo->telaranna
      && nodo->hijoizquierdo->hijoderecho==NULL && nodo->hijoizquierdo->hijoizquierdo==NULL){ //Si tiene teleranna y si es una hoja en el lado izq
        //Salvar de la derecha hacia atras
      }else if(nodo->hijoderecho->telaranna
       && nodo->hijoderecho->hijoderecho==NULL && nodo->hijoderecho->hijoizquierdo==NULL){ //Si tiene teleranna si es una hoja en el lado der
         //Salvar de la derecha hacia atras
      }
      salvarSpiderman(nodo->hijoizquierdo);
      salvarSpiderman(nodo->hijoderecho);

    }
}
