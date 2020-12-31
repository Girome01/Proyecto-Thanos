#include "eliminarhumanos.h"

EliminarHumanos::EliminarHumanos(){

}

NodoPersona* EliminarHumanos::obtenerHumNebula(ListaDoble* lista){
    int largo = int(QRandomGenerator::global()->bounded(0, lista->largo()));
    return lista->BuscarEnPos(largo);
}

void EliminarHumanos::eliminarHumaNebula(NodoPersona* eliminar){
    if(maximoNebula > 0){
        if( eliminar->persona->amigos != NULL){
            for(int i = 0; i < eliminar->persona->amigos->largo();i++){
                NodoPersona* matar = eliminar->persona->amigos->BuscarEnPos(i);
                if(matar->persona->vivo){
                    matar->persona->vivo = false;
                }
                eliminarHumaNebula(matar);
                maximoNebula--;// Si no funciona cambiarlo por que solo mate a los amigos de la persona si la persona esta viva
            }
        }
    }
}

void EliminarHumanos::Nebula(ListaDoble* lista){
    this->maximoNebula = lista->largo()/3;
    NodoPersona* persona = obtenerHumNebula(lista);
    eliminarHumaNebula(persona);
}

NodoPersona* EliminarHumanos::obtenerHumEbony(ListaDoble* lista){
    int id = int(QRandomGenerator::global()->bounded(0, 999999));
    return lista->BuscarPorID(id);
}

void EliminarHumanos::eliminarHumaEbony(NodoPersona* eliminar){
    if(eliminar != NULL){
        eliminar->persona->padre->vivo = false;
        eliminar->persona->esposa->vivo = false;
        if(eliminar->persona->hijos != NULL){
            for(int i = 0; i  < eliminar->persona->hijos->largo(); i++){
                eliminar->persona->hijos->BuscarEnPos(i)->persona->vivo = false;
            }
        }
    }
}

void EliminarHumanos::EbonyMaw(ListaDoble* lista){
    NodoPersona* persona = obtenerHumEbony(lista);
    eliminarHumaEbony(persona);
}

ListaDoble* EliminarHumanos::buscarHumBlack(int veces, string deporte, ListaDoble* mundo){
    ListaDoble* refTemp = new ListaDoble();
    NodoPersona* temp = mundo->primerNodo;
    for (int i = 0; i < mundo->largo() ; i++) {
        if(temp->persona->deportes->esta(deporte) &&
                temp->persona->deportes->obtener(deporte)->vecesSemana >= veces){
            refTemp->listaBlackDwarf(temp->persona);
        }

    }
    return refTemp;
}

void EliminarHumanos::eliminarBlackDwarf(ListaDoble* eliminar){
    int elim = eliminar->largo()*0.5;
    for (int i = 0; i < elim; i++ ) {
        int pos = int(QRandomGenerator::global()->bounded(0, eliminar->largo()-1));
        eliminar->BuscarEnPos(pos)->persona->vivo = false;
    }

}

void EliminarHumanos::BlackDwarf(int veces /*, ListaDeportes* deportes*/, ListaDoble* mundo){
    string deporte = "";
    ListaDoble* eliminar = buscarHumBlack(veces,deporte,mundo);
    eliminarBlackDwarf(eliminar);
}

Heap* EliminarHumanos::crearListaCorvus(ListaDoble* mundo){
    Heap* listaCorvus = new Heap(mundo);
    for (int i = 0; i < mundo->largo() ; i++) {
        listaCorvus->insertarCorvusGlaive(i);
    }
    return listaCorvus;
}

void EliminarHumanos::eliminarCorvus(Heap* eliminar,ListaDoble* mundo){
    int personasElim = eliminar->size * 0.05;
    for (int i = 0; i <= personasElim ; i++) {
        NodoPersona* temp = mundo->BuscarEnPos(eliminar->extractMaxCorvusGlaive());
        temp->persona->vivo = false;
    }

}

void EliminarHumanos::CorvusGlaive(ListaDoble* mundo){
    Heap* eliminar = crearListaCorvus( mundo);
    eliminarCorvus(eliminar, mundo);
}

Heap* EliminarHumanos::crearListaMidnight(ListaDoble* mundo){
    Heap* listaMidnight = new Heap(mundo);
    for (int i = 0; i < mundo->largo() ; i++) {
        listaMidnight->insertarMidnight(i);
    }
    return listaMidnight;
}

void EliminarHumanos::eliminarMidnight(Heap* eliminar,ListaDoble* mundo){
    int personasElim = eliminar->size * 0.05;
    for (int i = 0; i <= personasElim ; i++) {
        NodoPersona* temp = mundo->BuscarEnPos(eliminar->extractMaxMidnight());
        temp->persona->vivo = false;
    }

}

void EliminarHumanos::Midnight(ListaDoble* mundo){
    Heap* eliminar = crearListaMidnight( mundo);
    eliminarMidnight(eliminar, mundo);
}
