#include "eliminarhumanos.h"

EliminarHumanos::EliminarHumanos(){

}

NodoPersona* EliminarHumanos::obtenerHumNebula(ListaDoble* lista){
    int largo = int(QRandomGenerator::global()->bounded(0, lista->largo()));
    return lista->BuscarEnPos(largo);
}

void EliminarHumanos::eliminarHumaNebula(NodoPersona* eliminar){
    string texto = "Soy Nebula mate a esre humano por ser amigo de "+
            eliminar->persona->imprimirAmigos();
    if(maximoNebula > 0){
        if( eliminar->persona->amigos != NULL){
            for(int i = 0; i < eliminar->persona->amigos->largo();i++){
                NodoPersona* matar = eliminar->persona->amigos->BuscarEnPos(i);
                if(matar->persona->vivo){
                    matar->persona->vivo = false;
                    matar->persona->eliminado->insertarAlFinal(texto);
                    string mato = "Mate al humano "+matar->persona->imprimirAmigos();
                    datosNebula += mato+"\n";
                    datTotNebula += mato+"\n";
                }
                eliminarHumaNebula(matar);
                maximoNebula--;// Si no funciona cambiarlo por que solo mate a los amigos de la persona si la persona esta viva
            }
        }
    }
}

void EliminarHumanos::Nebula(ListaDoble* lista){
    datosNebula = "";
    this->maximoNebula = lista->largo()/3;
    NodoPersona* persona = obtenerHumNebula(lista);
    eliminarHumaNebula(persona);
}

NodoPersona* EliminarHumanos::obtenerHumEbony(ListaDoble* lista){
    int id = int(QRandomGenerator::global()->bounded(0, 999999));
    return lista->BuscarPorID(id);
}

void EliminarHumanos::eliminarHumaEbony(NodoPersona* eliminar){
    string texto = "Soy Eboony Maw Mate a este humano por ser familia de "+
            eliminar->persona->imprimirAmigos();
    if(eliminar != NULL){
        eliminar->persona->padre->vivo = false;
        eliminar->persona->padre->eliminado->insertarAlFinal(texto);
        datosEbony +="Mate al humano "+ eliminar->persona->padre->imprimirAmigos()
                +" por ser familia de "+eliminar->persona->imprimirAmigos()+"\n";
        eliminar->persona->esposa->vivo = false;
        eliminar->persona->esposa->eliminado->insertarAlFinal(texto);
        datosEbony +="Mate al humano "+ eliminar->persona->esposa->imprimirAmigos()
                +" por ser familia de "+eliminar->persona->imprimirAmigos()+"\n";
        eliminar->persona->madre->vivo = false;
        eliminar->persona->madre->eliminado->insertarAlFinal(texto);
        datosEbony +="Mate al humano "+ eliminar->persona->madre->imprimirAmigos()
                +" por ser familia de "+eliminar->persona->imprimirAmigos()+"\n";
        if(eliminar->persona->hijos != NULL){
            for(int i = 0; i  < eliminar->persona->hijos->largo(); i++){
                NodoPersona* temp = eliminar->persona->hijos->BuscarEnPos(i);
                temp->persona->vivo = false;
                temp->persona->eliminado->insertarAlFinal(texto);
                datosEbony +="Mate al humano "+ temp->persona->imprimirAmigos()
                        +" por ser familia de "+eliminar->persona->imprimirAmigos()+"\n";
            }
        }
        datTotEbony += datosEbony;
    }
}

void EliminarHumanos::EbonyMaw(ListaDoble* lista){
    datosEbony = "";
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

void EliminarHumanos::eliminarBlackDwarf(ListaDoble* eliminar, int veces, string deporte){
    stringstream buff;
    buff << veces;
    string _veces = buff.str();
    string texto = "Soy Black Dwarf mate a este humano por practicar"+
            deporte+" "+_veces+" por semana";
    int elim = eliminar->largo()*0.5;
    for (int i = 0; i < elim; i++ ) {
        int pos = int(QRandomGenerator::global()->bounded(0, eliminar->largo()-1));
        NodoPersona* temp = eliminar->BuscarEnPos(pos);
        temp->persona->vivo = false;
        temp->persona->eliminado->insertarAlFinal(texto);
        datosBlack += "Mate al humano "+temp->persona->imprimirAmigos()+"por practicar"+
                deporte+" "+_veces+" por semana"+"\n";
    }
    datTotBlack += datosBlack;

}

void EliminarHumanos::BlackDwarf(int veces /*, ListaDeportes* deportes*/, ListaDoble* mundo){
    string deporte = "";
    datosBlack = "";
    ListaDoble* eliminar = buscarHumBlack(veces,deporte,mundo);
    eliminarBlackDwarf(eliminar,veces, deporte);
}

Heap* EliminarHumanos::crearListaCorvus(ListaDoble* mundo){
    Heap* listaCorvus = new Heap(mundo);
    for (int i = 0; i < mundo->largo() ; i++) {
        listaCorvus->insertarCorvusGlaive(i);
    }
    return listaCorvus;
}

void EliminarHumanos::eliminarCorvus(Heap* eliminar,ListaDoble* mundo){
    string texto = "Soy Corvus Glaive mate a este humano por tener muchos pecados";
    int personasElim = eliminar->size * 0.05;
    for (int i = 0; i <= personasElim ; i++) {
        NodoPersona* temp = mundo->BuscarEnPos(eliminar->extractMaxCorvusGlaive());
        temp->persona->vivo = false;
        temp->persona->eliminado->insertarAlFinal(texto);
        datosCorvus += "Mate a este humano "+temp->persona->imprimirAmigos()+"\n";
    }
    datTotCorvus += datosCorvus;

}

void EliminarHumanos::CorvusGlaive(ListaDoble* mundo){
    datosCorvus = "";
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
    string texto = "Soy Midnight mate a este humano por tener pocas acciones buenas";
    int personasElim = eliminar->size * 0.05;
    for (int i = 0; i <= personasElim ; i++) {
        NodoPersona* temp = mundo->BuscarEnPos(eliminar->extractMaxMidnight());
        temp->persona->vivo = false;
        temp->persona->eliminado->insertarAlFinal(texto);
        datosMidnight += "Mate a este humano "+temp->persona->imprimirAmigos()+"\n";
    }
    datTotMidnight += datosMidnight;
}

void EliminarHumanos::Midnight(ListaDoble* mundo){
    datosMidnight = "";
    Heap* eliminar = crearListaMidnight( mundo);
    eliminarMidnight(eliminar, mundo);
}
