#include "salvahumanos.h"

salvaHumanos::salvaHumanos(Arbol *arbol)
{
    //cout<<"ACTUALIZO EL AROBL DE SALVAR"<<endl;
    arbolHumanidad=arbol;
    //cout<<"CREO LA COLA"<<endl;
    colaNivel=new Cola();
    //cout<<"CREO LA LISTA SALVA HUMANOS"<<endl;
    listaHumanidad=new ListaSalvaHumanos();
}

void salvaHumanos::recorrerArbolHormigas(int cantidadHorm){ //Primera funcion de Antman
    //for(int i=0; i<cantidadHorm;i++){ //Cantidad de hormigas que se desean crear, INPUT
    int contador=0;
    recorridoHormiga+="Soy una hormiga y este fue mi recorrido: \n";
        cout<<recorridoHormiga<<endl;
        NodoArbol *temp=arbolHumanidad->raiz; //Raiz
        while(temp!=NULL && contador<cantidadHorm){
            int indice=int(QRandomGenerator::global()->bounded(0, 2)); //Un random de 0 a 1
            //cout<<"Entra al while"<<endl;
            cout<<indice<<endl;
            if(indice==0){
                temp->cantRecorridoHormiga++; //Aumenta en 1 el recorrido pasado por ese nodo
                contador++;
                temp->hormiga=true; //Contiene una feromona
                temp=temp->hijoizquierdo; //Si es igual a cero, entonces se va por la izq
            }else{
                temp->cantRecorridoHormiga++; //Aumenta en 1 el recorrido pasado por ese nodo
                contador++;
                temp->hormiga=true; //Contiene una feromona
                temp=temp->hijoderecho; //Sino, por la derecha
            }
            if(temp!=NULL){
                recorridoHormiga+=to_string(temp->marcaNodo)+"-";
            }
        }
    //}
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

void salvaHumanos::salvarAntman(int cantidadHormigas){ //Segunda funcion
    recorrerArbolHormigas(cantidadHormigas);
    cout<<"Fin recorrido"<<endl;
    NodoArbol *inicioArbol=mejorCaminoAntMan();
    NodoArbol *destino=mejorCaminoAntMan();
    cout<<destino->persona->persona->ID<<endl;
    cout<<inicioArbol->persona->persona->ID<<endl;
    QString m_time = QTime::currentTime().toString();
    string time = m_time.toStdString();
    ramasSeleccionadas+="Las ramas seleccionadas son: "+to_string(inicioArbol->marcaNodo)+" y "+to_string(destino->marcaNodo);
    rangoSeleccionado+="El rango de personas salvadas es de "+to_string(inicioArbol->persona->persona->ID)+"->"+to_string(destino->persona->persona->ID);
    datTotAntman+="Soy Antman e implanté hormigas a este árbol: "+recorridoHormiga+". "+ramasSeleccionadas+rangoSeleccionado+"\n";

    NodoPersona *inicio=inicioArbol->persona;
    if(destino!=NULL && inicio!=NULL){
        while(inicio->persona->ID!=destino->persona->persona->ID){
                if(!inicio->persona->vivo){
                    inicio->persona->vivo=true;
                    datosAntman+=date +" "+time+" Soy Antman y salvé a esta persona de la muerte por estar entre las ramas: "+to_string(inicioArbol->marcaNodo)+" y "+to_string(destino->marcaNodo)+": "+inicio->persona->imprimir()+"\n";
                    inicio->persona->revivido->insertarAlFinal(datosAntman);
                    salvAntman++;
                    totalAntman++;
                    datTotAntman+=datosAntman;
                }
                inicio=inicio->siguiente;
        }
    }
    datTotAntman+="GRACIAS AL TRABAJO DE ANTMAN FUERON SALVADAS EN ESTA OCASION: "+to_string(salvAntman)+" PERSONAS Y EN TOTAL: "+to_string(totalAntman);
}

void salvaHumanos::generarListaHumanidad(NodoArbol *nodo){ //Primera funcion de IronMan
    if (nodo != NULL){ //Genera una lista con los nodos que contienen a la humanidad
        //listaHumanidad->insertarAlFinal(nodo->hijoderecho);
        generarListaHumanidad(nodo->hijoizquierdo);
        listaHumanidad->insertarAlFinal(nodo);
        //listaHumanidad->insertarAlFinal(nodo->hijoizquierdo);
        generarListaHumanidad(nodo->hijoderecho);
    }
}

void salvaHumanos::detonarBomba(){ //Segunda funcion de IronMan
    generarListaHumanidad(arbolHumanidad->raiz);
    NodoSalvar *temp=listaHumanidad->primerNodo;
    int contador=0;
    int porcentaje=int(QRandomGenerator::global()->bounded(40,61)); //Cuanto porciento va a explotar
    //cout<<"P"<<porcentaje<<endl;
    //cout<<listaHumanidad->largo()<<endl;
    double cantidadExplosion1=double(listaHumanidad->largo())*(porcentaje/100.0); //Cantidad de explosiones que se daran
    int cantidadExplosion=cantidadExplosion1;
    //cout<<"C "<<cantidadExplosion<<endl;
    recorridoBomba+="Los nodos con bombas detonadas ("+to_string(cantidadExplosion)+ ") fueron: \n";
    //for(int i=0; i<cantidadExplosion; i++){
        while(temp!=NULL && contador<cantidadExplosion){
            //cout<<"Cont"<<contador<<endl;
            int indice=int(QRandomGenerator::global()->bounded(0, 2)); //Random de 0 a 1
            cout<<indice<<endl;
            if(indice==0){ //Esto es para que no se detonen solo los primeros nodos
                temp->nodoA->detonarBomba=true; //Detona la bomba en este temp
                recorridoBomba+=to_string(temp->nodoA->marcaNodo)+"-";
                contador++;
                temp=temp->siguiente;
            }else{
                if(temp->siguiente!=NULL){
                    temp->siguiente->nodoA->detonarBomba=true; //Detona la bomba en el temp sig
                    recorridoBomba+=to_string(temp->siguiente->nodoA->marcaNodo)+"-";
                    contador++;
                }
                temp=temp->siguiente;
            }

        }
    //}
}

void salvaHumanos::salvarEsposasPadres(NodoPersona *nodoPersona, string time){
    if(nodoPersona->persona->esposa!=NULL){
        if(!nodoPersona->persona->esposa){
            nodoPersona->persona->esposa->vivo=true;
            datosIronman+=date +" "+time+" Soy Ironman y salvé a esta persona: "+nodoPersona->persona->esposa->imprimir()+"\n";
            nodoPersona->persona->esposa->revivido->insertarAlFinal(datosIronman);
            salvdatosIronman++;
            totalIronman++;
        }
    }

    if(nodoPersona->persona->padre!=NULL){
        if(!nodoPersona->persona->padre){
            nodoPersona->persona->padre->vivo=true;
            datosIronman+=date +" "+time+" Soy Ironman y salvé a esta persona: "+nodoPersona->persona->padre->imprimir()+"\n";
            nodoPersona->persona->padre->revivido->insertarAlFinal(datosIronman);
            salvdatosIronman++;
            totalIronman++;
        }
    }

    if(nodoPersona->persona->madre!=NULL){
        if(!nodoPersona->persona->madre){
            nodoPersona->persona->madre->vivo=true;
            datosIronman+=date +" "+time+" Soy Ironman y salvé a esta persona: "+nodoPersona->persona->madre->imprimir()+"\n";
            nodoPersona->persona->madre->revivido->insertarAlFinal(datosIronman);
            salvdatosIronman++;
            totalIronman++;
        }
    }
}

void salvaHumanos::salvarHijos(NodoPersona *primerNodo){ //Cuarta funcion de IronMan
    NodoPersona *temp=primerNodo;
    QString m_time = QTime::currentTime().toString();
    string time = m_time.toStdString();
    while(temp!=NULL){
        if(!temp->persona->vivo){
            temp->persona->vivo=true;
            datosIronman+=date +" "+time+" Soy Ironman y salvé a esta persona: "+temp->persona->imprimir()+"\n";
            temp->persona->revivido->insertarAlFinal(datosIronman);
            salvdatosIronman++;
            totalIronman++;
            salvarEsposasPadres(temp,time);
           for(int i=0;i<temp->persona->hijos->largo();i++){
               NodoPersona* temp2 = temp->persona->hijos->BuscarEnPos(i);
               if(!temp2->persona->vivo){
                    temp2->persona->vivo=true;
                    datosIronman+=date +" "+time+" Soy Ironman y salvé a esta persona: "+temp->persona->imprimir()+"\n";
                    temp2->persona->revivido->insertarAlFinal(datosIronman);
                    salvdatosIronman++;
                    totalIronman++;
                    salvarEsposasPadres(temp2,time);
                }

            }
        }
        temp=temp->siguiente;
    }
}

void salvaHumanos::salvarIronman(){ //Tercera funcion de IronMan
   salvdatosIronman=0;
   datosIronman="";
   detonarBomba();
   //cout<<"DETONO"<<endl;
   QString m_time = QTime::currentTime().toString();
   string time = m_time.toStdString();
   NodoSalvar *temp=listaHumanidad->primerNodo;
   NodoPersona *temp2=listaHumanidad->primerNodo->nodoA->persona;
   datTotdatosIronman+="Soy Ironman e implanté bombas que fueron detonadas a este árbol: "+recorridoBomba+"."+"\n";
   //cout<<"Antes del while salvar"<<endl;
   while(temp!=NULL){
       cout<<"Entro al while salvar"<<endl;
       if(temp->nodoA->detonarBomba){
           temp->nodoA->detonarBomba=false;
           //cout<<"Entro a detonarbomba"<<endl;
            while(temp2!=NULL && temp2->persona->ID!=temp->siguiente->nodoA->persona->persona->ID){
                //cout<<"Entro al otro while"<<endl;
                if(!temp2->persona->hijos->isEmpty()){
                    //cout<<"Hijos"<<endl;
                    salvarHijos(temp2->persona->hijos->primerNodo);
                }
                if(temp2->persona->esposa!=NULL){
                    //cout<<"Esposa"<<endl;
                    if(!temp2->persona->esposa->vivo){
                        //cout<<"ENTRA ESPOSA"<<endl;
                        temp2->persona->esposa->vivo=true;
                        datosIronman+=date +" "+time+" Soy Ironman y salvé a esta persona: "+temp2->persona->esposa->imprimir()+"\n";
                        temp2->persona->esposa->revivido->insertarAlFinal(datosIronman);
                        salvdatosIronman++;
                        totalIronman++;
                    }
                }

                if(temp2->persona->padre!=NULL){
                    //cout<<"Padre"<<endl;
                    if(!temp2->persona->padre->vivo){
                        temp2->persona->padre->vivo=true;
                        datosIronman+=date +" "+time+" Soy Ironman y salvé a esta persona: "+temp2->persona->padre->imprimir()+"\n";
                        temp2->persona->padre->revivido->insertarAlFinal(datosIronman);
                        salvdatosIronman++;
                        totalIronman++;
                    }
                }

                if(temp2->persona->madre!=NULL){
                    //cout<<"Madre"<<endl;
                    if(!temp2->persona->madre->vivo){
                        temp2->persona->madre->vivo=true;
                        datosIronman+=date +" "+time+" Soy Ironman y salvé a esta persona: "+temp2->persona->madre->imprimir()+"\n";
                        temp2->persona->madre->revivido->insertarAlFinal(datosIronman);
                        salvdatosIronman++;
                        totalIronman++;
                    }
                }

                temp2=temp2->siguiente;
            }
       }
       temp=temp->siguiente;
   }
   datTotdatosIronman+=datosIronman+"GRACIAS AL TRABAJO DE IRONMAN FUERON SALVADAS EN ESTA OCASION: "+to_string(salvdatosIronman)+" PERSONAS Y EN TOTAL: "+to_string(totalIronman);
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

void salvaHumanos::salvarAmigosDeEsposaPadres(Persona *persona, string time){
    Persona *temp=persona;
    cout<<"L"<<temp->amigos->largo()<<endl;
    for(int i=0;i<temp->amigos->largo();i++){
        NodoPersona* temp2 = temp->amigos->BuscarEnPos(i);
        if(!temp2->persona->vivo){
             temp2->persona->vivo=true;
             salvdatosThor++;
             totalThor++;
             datosThor+=date +" "+time+" Soy Thor y salvé a esta persona: "+temp2->persona->imprimir()+"\n";
             temp2->persona->revivido->insertarAlFinal(datosThor);
       }
    }
}

void salvaHumanos::salvarAmigosDeHijos(NodoPersona *nodoPersona, string time){
    NodoPersona *temp=nodoPersona->persona->hijos->primerNodo;
    while(temp!=NULL){
        for(int i=0;i<temp->persona->amigos->largo();i++){
            NodoPersona* temp2 = temp->persona->amigos->BuscarEnPos(i);
            if(!temp2->persona->vivo){
                 temp2->persona->vivo=true;
                 salvdatosThor++;
                 totalThor++;
                 datosThor+=date +" "+time+" Soy Thor y salvé a esta persona: "+temp2->persona->imprimir()+"\n";
                 temp2->persona->revivido->insertarAlFinal(datosThor);
            }
        }
        temp=temp->siguiente;
    }
}

void salvaHumanos::salvarThor(){ //Primera funcion de Thor
    datosThor="";
    salvdatosThor=0;
    colaNivel=new Cola();
    int nivel=int(QRandomGenerator::global()->bounded(1,arbolHumanidad->profundidad(arbolHumanidad->raiz))); //Profundidad del arbol para saber que tan lejos puede ir el random
    encontrarNiveles(arbolHumanidad->raiz, 0, nivel, colaNivel); //Encontrar los nodos con ese nivel y guardarlos en una cola
    cout<<nivel<<endl;
    Nodo *temp=colaNivel->frente; //Recorrer la cola
    colaNivel->imprimir();
    cout<<colaNivel->frente->nodo->marcaNodo<<endl;
    datTotdatosThor+="Soy Thor y salvé a las personas del nivel: "+to_string(nivel)+"\n";
    nivelesSeleccionados+="Los niveles seleccionados: \n";
    QString m_time = QTime::currentTime().toString();
    string time = m_time.toStdString();
    while(temp!=NULL){
        nivelesSeleccionados+=to_string(temp->nodo->marcaNodo)+"-";
        //cout<<"WHILE"<<endl;
        /*if(!temp->nodo->persona->persona->vivo){
            temp->nodo->persona->persona->vivo=true;
            salvdatosThor++;
            totalThor++;
            datosThor+=date +" "+time+" Soy Thor y salvé a esta persona: "+temp->nodo->persona->persona->imprimir()+"\n";
            temp->nodo->persona->persona->revivido->insertarAlFinal(datosThor);*/

            if(temp->nodo->persona->persona->esposa!=NULL){
                datosThor+=date +" "+time+" Soy Thor y salvé a esta persona: "+temp->nodo->persona->persona->esposa->imprimir()+"\n";
                temp->nodo->persona->persona->esposa->revivido->insertarAlFinal(datosThor);
                salvarAmigosDeEsposaPadres(temp->nodo->persona->persona->esposa,time);
            }
            if(temp->nodo->persona->persona->madre!=NULL){
                datosThor+=date +" "+time+" Soy Thor y salvé a esta persona: "+temp->nodo->persona->persona->madre->imprimir()+"\n";
                temp->nodo->persona->persona->madre->revivido->insertarAlFinal(datosThor);
                salvarAmigosDeEsposaPadres(temp->nodo->persona->persona->madre,time);
            }
            if(temp->nodo->persona->persona->padre!=NULL){
                datosThor+=date +" "+time+" Soy Thor y salvé a esta persona: "+temp->nodo->persona->persona->padre->imprimir()+"\n";
                temp->nodo->persona->persona->padre->revivido->insertarAlFinal(datosThor);
                salvarAmigosDeEsposaPadres(temp->nodo->persona->persona->padre,time);
            }
            if(temp->nodo->persona!=NULL){
                salvarAmigosDeHijos(temp->nodo->persona,time);
            }
           temp=temp->siguiente;
        }

    //}
    datTotdatosThor+=nivelesSeleccionados+"\n"+datosThor+"\n"+"GRACIAS AL TRABAJO DE THOR FUERON SALVADAS EN ESTA OCASION: "+to_string(salvdatosThor)+" PERSONAS Y EN TOTAL: "+to_string(totalThor);

}

void salvaHumanos::recorrerArbolAranna(){ //Primera funcion Spiderman
    NodoArbol *temp=arbolHumanidad->raiz;
    cantidadTelarannas=0;
    temp->telaranna=true;
    recorridoTelaranna+="Los nodos con telaranas: \n";
    while(temp!=NULL){
        int indice=int(QRandomGenerator::global()->bounded(0, 4)); //Randomly ira poniendo telerannas con nums del 0 al 3
        if(indice==0){ //Si es cero entonces por la izq
            temp->telaranna=true; //Tendra telaranna
            recorridoTelaranna+=to_string(temp->marcaNodo)+"-";
            cantidadTelarannas++;
            temp=temp->hijoizquierdo;
        }else if(indice==1){
            temp->telaranna=true; //Tendra teleranna
            recorridoTelaranna+=to_string(temp->marcaNodo)+"-";
            cantidadTelarannas++;
            temp=temp->hijoderecho; //Si es 1 entonces por la der
        }else if(indice==2){
            temp=temp->hijoizquierdo; //Si es 2 se va por la izq porque me da la gana, pero no va a poner telaranna
        }else{
            temp=temp->hijoizquierdo; //Lo mismo que arriba, pero con 3
        }
      }
    recorrerTeleranna(arbolHumanidad->raiz);
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
    QString m_time = QTime::currentTime().toString();
    string time = m_time.toStdString();
    datTotdatosSpiderman+="Soy Spiderman e implanté "+to_string(cantidadTelarannas)+" telaranas a este árbol: "+recorridoTelaranna+"\n";
    while(temp!=NULL && cantidadTelarannas>0){ //Recorre las personas hacia la derecha mientras se cumpla la cantidad de Telerannas deseada
        if(!temp->persona->vivo){
            temp->persona->vivo=true;
            salvdatosSpiderman++;
            totalSpiderman++;
            datosSpiderman+=date +" "+time+" Soy Spiderman y salvé a esta persona: "+temp->persona->imprimir()+"\n";
            temp->persona->revivido->insertarAlFinal(datosThor);
            cantidadTelarannas--;
        }
        temp=temp->anterior; //Derecha, o sea los menores
    }
    datTotdatosSpiderman+=datosSpiderman+"\n"+"GRACIAS AL TRABAJO DE SPIDERMAN FUERON SALVADAS EN ESTA OCASION: "+to_string(salvdatosSpiderman)+" PERSONAS Y EN TOTAL: "+to_string(totalSpiderman)+"\n";
}

string salvaHumanos::salvarHumanos(){
    return "Soy Ant Man salve a estos humanos \n"+datTotAntman+"\nSoy Ironman salve a estos humanos\n"+
            datTotdatosIronman+"\nSoy Thor salve a estos humanos\n"+datTotdatosThor+
            "\nSoy Spiderman salve a estos humanos\n"+datTotdatosSpiderman;
}
