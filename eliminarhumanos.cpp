#include "eliminarhumanos.h"

EliminarHumanos::EliminarHumanos(){

}

NodoPersona* EliminarHumanos::obtenerHumNebula(ListaDoble* lista){
    int largo = int(QRandomGenerator::global()->bounded(0, lista->largo()));
    return lista->BuscarEnPos(largo);
}

void EliminarHumanos::eliminarHumaNebula(NodoPersona* eliminar){
    QString m_time = QTime::currentTime().toString();
    string time = m_time.toStdString();
    string texto = date+" "+time+" Soy Nebula mate a esre humano por ser amigo de "+
            eliminar->persona->imprimirAmigos()+"\t";
    if(maximoNebula > 0){
        if( eliminar->persona->amigos != NULL){
            for(int i = 0; i < eliminar->persona->amigos->largo();i++){
                NodoPersona* matar = eliminar->persona->amigos->BuscarEnPos(i);
                if(matar->persona->vivo){
                    matar->persona->vivo = false;
                    elimNebula += 1;
                    totalElimNebula += 1;
                    matar->persona->eliminado->insertarAlFinal(texto);
                    QString m_time = QTime::currentTime().toString();
                    string time = m_time.toStdString();
                    string mato = date +" "+ time+ " Mate al humano "+matar->persona->imprimirAmigos();
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
    elimNebula = 0;
    this->maximoNebula = lista->largo()/3;
    NodoPersona* persona = obtenerHumNebula(lista);
    eliminarHumaNebula(persona);
}

NodoPersona* EliminarHumanos::obtenerHumEbony(ListaDoble* lista){
    int id = int(QRandomGenerator::global()->bounded(0, 999999));
    return lista->BuscarPorID(id);
}

void EliminarHumanos::eliminarHumaEbony(NodoPersona* eliminar){
    QString m_time = QTime::currentTime().toString();
    string time = m_time.toStdString();
    string texto = date +" "+time+ " Soy Eboony Maw Mate a este humano por ser familia de "+
            eliminar->persona->imprimirAmigos()+"\t";
    if(eliminar != NULL){
        eliminar->persona->padre->vivo = false;
        elimEbony += 1;
        totalElimEbony += 1;
        eliminar->persona->padre->eliminado->insertarAlFinal(texto);
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        datosEbony +=date +" "+time+ " Mate al humano "+ eliminar->persona->padre->imprimirAmigos()
                +" por ser familia de "+eliminar->persona->imprimirAmigos()+"\t";
        eliminar->persona->esposa->vivo = false;
        elimEbony += 1;
        totalElimEbony += 1;
        eliminar->persona->esposa->eliminado->insertarAlFinal(texto);
        m_time = QTime::currentTime().toString();
        time = m_time.toStdString();
        datosEbony +=date +" "+time+ " Mate al humano "+ eliminar->persona->esposa->imprimirAmigos()
                +" por ser familia de "+eliminar->persona->imprimirAmigos()+"\t";
        eliminar->persona->madre->vivo = false;
        elimEbony += 1;
        totalElimEbony += 1;
        eliminar->persona->madre->eliminado->insertarAlFinal(texto);
        m_time = QTime::currentTime().toString();
        time = m_time.toStdString();
        datosEbony +=date +" " +time+ " Mate al humano "+ eliminar->persona->madre->imprimirAmigos()
                +" por ser familia de "+eliminar->persona->imprimirAmigos()+"\t";
        if(eliminar->persona->hijos != NULL){
            for(int i = 0; i  < eliminar->persona->hijos->largo(); i++){
                NodoPersona* temp = eliminar->persona->hijos->BuscarEnPos(i);
                temp->persona->vivo = false;
                elimEbony += 1;
                totalElimEbony += 1;
                temp->persona->eliminado->insertarAlFinal(texto);
                QString m_time = QTime::currentTime().toString();
                string time = m_time.toStdString();
                datosEbony +=date +" "+time+ " Mate al humano "+ temp->persona->imprimirAmigos()
                        +" por ser familia de "+eliminar->persona->imprimirAmigos()+"\t";
            }
        }
        datosEbony += "\n";
        datTotEbony += datosEbony+"\n";
    }
}

void EliminarHumanos::EbonyMaw(ListaDoble* lista){
    datosEbony = "";
    elimEbony += 0;
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
    QString m_time = QTime::currentTime().toString();
    string time = m_time.toStdString();
    string texto = date +" "+time+ " Soy Black Dwarf mate a este humano por practicar"+
            deporte+" "+_veces+" por semana"+"\t";
    int elim = eliminar->largo()*0.5;
    for (int i = 0; i < elim; i++ ) {
        int pos = int(QRandomGenerator::global()->bounded(0, eliminar->largo()-1));
        NodoPersona* temp = eliminar->BuscarEnPos(pos);
        temp->persona->vivo = false;
        elimBlack += 1;
        totalElimBlack += 1;
        temp->persona->eliminado->insertarAlFinal(texto);
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        datosBlack += date +" "+time+ " Mate al humano "+temp->persona->imprimirAmigos()+"por practicar"+
                deporte+" "+_veces+" por semana"+"\n";
    }
    datTotBlack += datosBlack;

}

vector<string>EliminarHumanos::generarlistaNombres(string texto){
    std::vector<string> listaNombres;
    std::string delimiter = "-";

    size_t last = 0;
    size_t next = 0;
    while ((next = texto.find(delimiter, last)) != string::npos) {
        //cout << texto.toStdString().substr(last, next-last) << endl;
        listaNombres.push_back(texto.substr(last, next-last));
        last = next + 1;
    }
    return listaNombres;
}

void EliminarHumanos::BlackDwarf(int veces , ListaDoble* mundo){
    int deportePractica = int(QRandomGenerator::global()->bounded(0, 163));
    string deporte = generarlistaNombres("").at(deportePractica);
    datosBlack = "";
    elimBlack = 0;
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
    QString m_time = QTime::currentTime().toString();
    string time = m_time.toStdString();
    string texto =date +" "+time+ " Soy Corvus Glaive mate a este humano por tener muchos pecados\t";
    int personasElim = eliminar->size * 0.05;
    for (int i = 0; i <= personasElim ; i++) {
        NodoPersona* temp = mundo->BuscarEnPos(eliminar->extractMaxCorvusGlaive());
        temp->persona->vivo = false;
        elimCorvus += 1;
        totalElimCorvus += 1;
        temp->persona->eliminado->insertarAlFinal(texto);
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        datosCorvus += date +" "+time+ " Mate a este humano "+temp->persona->imprimirAmigos()+"\n";
    }
    datTotCorvus += datosCorvus;

}

void EliminarHumanos::CorvusGlaive(ListaDoble* mundo){
    datosCorvus = "";
    elimCorvus = 0;
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
    QString m_time = QTime::currentTime().toString();
    string time = m_time.toStdString();
    string texto = date +" "+time+ " Soy Midnight mate a este humano por tener pocas acciones buenas\t";
    int personasElim = eliminar->size * 0.05;
    for (int i = 0; i <= personasElim ; i++) {
        NodoPersona* temp = mundo->BuscarEnPos(eliminar->extractMaxMidnight());
        temp->persona->vivo = false;
        elimMidnight += 1;
        totalElimMidnight += 1;
        temp->persona->eliminado->insertarAlFinal(texto);
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        datosMidnight += date +" "+time+ " Mate a este humano "+temp->persona->imprimirAmigos()+"\n";
    }
    datTotMidnight += datosMidnight;
}

void EliminarHumanos::Midnight(ListaDoble* mundo){
    datosMidnight = "";
    elimMidnight = 0;
    Heap* eliminar = crearListaMidnight( mundo);
    eliminarMidnight(eliminar, mundo);
}
