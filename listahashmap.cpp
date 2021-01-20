#include "listahashmap.h"

ListaHashMap::ListaHashMap()
{
    primerNodo = ultimoNodo = NULL;
}

void ListaHashMap::insertarAlInicio (int _key){
    if (primerNodo == NULL){
        primerNodo = new NodoHashMap(_key);
        ultimoNodo = primerNodo;
    }
    else{
        NodoHashMap *nuevo = new NodoHashMap(_key);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

Persona* ListaHashMap::encontrarPorID(ListaDoble *personas, int id){
    NodoPersona *temp=personas->primerNodo;
    while(temp!=NULL){
        if(temp->persona->ID==id)
            return temp->persona;
        temp=temp->siguiente;
    }
    return NULL;
}
void ListaHashMap::matarPersonas(ListaDoble *personas){
    elimThanos=0;
    datosThanos="";
    NodoHashMap *temp=primerNodo;
    while(temp!=NULL){
        //cout<<"Entro al while"<<endl;
        Persona *matar=encontrarPorID(personas, temp->key);
        //cout<<"Encontro x id"<<endl;
        if(matar!=NULL){
            //cout<<"No NULL"<<endl;
            if(matar->vivo){
                matar->vivo=false;
                QString m_time = QTime::currentTime().toString();
                string time = m_time.toStdString();
                elimThanos++;
                totalElimThanos++;
                datosThanos += date+" "+time+" Soy Thanos mate a este humano por ser parte de la key: "+
                to_string(temp->key)+"y el anno: "+matar->nacAno+": "+matar->imprimir()+"\n";
                matar->eliminado->insertarAlFinal(datosThanos);
            }
        }
        temp=temp->siguiente;
    }
    datTotThanos+=datosThanos+"Thanos ha matado: "+to_string(elimThanos)+" personas y en total: "+to_string(totalElimThanos)+"\n";
}

void ListaHashMap::insertarAlFinal (int _key){
    if (primerNodo == NULL){
        primerNodo = new NodoHashMap(_key);
        ultimoNodo = primerNodo;
    }
    else{
        NodoHashMap *nuevo = new NodoHashMap(_key);
        ultimoNodo->siguiente = nuevo;
        ultimoNodo = nuevo;
    }
}
