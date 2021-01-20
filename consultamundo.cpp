#include "consultamundo.h"

ConsultaMundo::ConsultaMundo(ListaDoble *personasHumanidad, Arbol *arbolHumanidad)
{
    personas=personasHumanidad;
    arbolPersonas=arbolHumanidad;
}


ListaSimple *deportes = new ListaSimple();
ListaElimSalv *elimSal = new ListaElimSalv();

string ConsultaMundo::consultaHumanoID(int idConsultaHumano, NodoArbol *arbol){
    bool estaIdArbol=false;
    bool estaIdLista = false;
    //arbol = arbolPersonas->raiz;

    while (arbol != NULL) {
        if (arbol->persona->persona->ID == idConsultaHumano) { //si el idConsultaHumano es igual al elemento
            //aqui se deberia imprimir toda la informacion de la persona consultada
            /*cout<< "La persona que se intento buscar se encuentra entre las personas creadas en el arbol"<<endl<<endl;
            cout<<arbol->persona->persona->nombre<<" "<<arbol->persona->persona->apellido<<"   "<<arbol->persona->persona->ID<<" \n"<< arbol->persona->persona->continenteVive<<"  "<<arbol->persona->persona->nacDia<<"/"<<arbol->persona->persona->nacMes<<"/"<<arbol->persona->persona->nacAno<< "   " <<arbol->persona->persona->rangoEtario<< "   "<<arbol->persona->persona->creencia <<endl<< "Profesion: "<< arbol->persona->persona->profesion << endl<< "Vive en  "<<arbol->persona->persona->paisVive<<endl<<arbol->persona->persona->estadoMarital<<endl<<arbol->persona->persona->pecados->imprimir()<<endl;
            cout<<endl;*/
            estaIdArbol = true;
            return arbol->persona->persona->imprimir(); //Retorna la info de la persona

        }
        else if (arbol->persona->persona->ID < idConsultaHumano) { //se llama recursivamente a la funcion
            return consultaHumanoID(idConsultaHumano,arbol->hijoderecho);
        }
        else if (arbol->persona->persona->ID > idConsultaHumano) {
            return consultaHumanoID(idConsultaHumano,arbol->hijoizquierdo);
        }

    }

     if(estaIdArbol == false){
         NodoPersona *tempPrueba = personas->primerNodo;

         while (tempPrueba != NULL) {
             if (tempPrueba->persona->ID == idConsultaHumano) {
                 /*cout<<endl<<"//////////////////////////////////////";
                 cout<< "La persona que se intento buscar se encuentra entre las personas creadas en lista"<<endl<<endl;
                 //cout<<endl<< endl << "Persona #" << numeroPersona <<endl;
                 cout<<tempPrueba->persona->nombre<<" "<<tempPrueba->persona->apellido<<"   "<<tempPrueba->persona->ID<<" \n"<<tempPrueba->persona->continenteVive<<"  "<<tempPrueba->persona->nacDia<<"/"<<tempPrueba->persona->nacMes<<"/"<<tempPrueba->persona->nacAno<< "   " <<tempPrueba->persona->rangoEtario<< "   "<<tempPrueba->persona->creencia <<endl<< "Profesion: "<< tempPrueba->persona->profesion << endl<< "Vive en  "<<tempPrueba->persona->paisVive<<endl<<tempPrueba->persona->estadoMarital<<endl<<tempPrueba->persona->pecados->imprimir()<<endl;
                 cout<<endl;*/
                 estaIdLista=true;
                 return tempPrueba->persona->imprimir();//Retorna la info de la persona

             }

             tempPrueba=tempPrueba->siguiente;
         }
     }
     if (!estaIdArbol && !estaIdLista){
        //cout << "La persona que intenta buscar no esta creada ni en el arbol ni en la lista";
        return "No se encuentra la persona buscada. \n";
     }
     return "";
}//fin de consultaHumanoID

string ConsultaMundo::consultaFamiliaID(int ConsultaFamiliaId, NodoArbol *arbol){
    bool estaIdArbol= false;
    bool estaIdLista = false;
    //arbol = arbolPersonas->raiz;

    while (arbol != NULL) {
        if (arbol->persona->persona->ID==ConsultaFamiliaId) { //si el idConsultaHumano es igual al elemento
            //aqui se deberia imprimir toda la informacion de la familia de persona consultada
            /*cout<< "La persona que se intento buscar se encuentra entre las personas creadas en el arbol"<<endl<<endl;
            cout << arbol->persona->persona->esposa->nombre;
            cout << arbol->persona->persona->hijos->imprimir();
            cout<<endl;*/
            estaIdArbol=true;
            if(arbol->persona->persona->esposa!=NULL && !arbol->persona->persona->hijos->isEmpty()){
                return "Pareja: "+arbol->persona->persona->esposa->imprimir()+"\n"+
                        "Hijos: "+arbol->persona->persona->hijos->imprimir();
            }else if(!arbol->persona->persona->hijos->isEmpty()){
                return "Hijos: "+arbol->persona->persona->hijos->imprimir()+"\n";
            }else if(arbol->persona->persona->esposa!=NULL){
                return "Pareja: "+arbol->persona->persona->esposa->imprimir();
            }else{
                return "Esta persona no tiene pareja ni hijos.\n";
            }

            break;

        }
        else if (arbol->persona->persona->ID < ConsultaFamiliaId) { //se llama recursivamente a la funcion
            return consultaHumanoID(ConsultaFamiliaId,arbol->hijoderecho);
        }
        else if (arbol->persona->persona->ID > ConsultaFamiliaId) {
            return consultaHumanoID(ConsultaFamiliaId,arbol->hijoizquierdo);
        }

    }

     if(estaIdArbol == false){
         NodoPersona *tempPrueba = personas->primerNodo;

         while (tempPrueba != NULL) {
             if (tempPrueba->persona->ID == ConsultaFamiliaId) {
                 //aqui se deberia imprimir toda la informacion de la familia de persona consultada
                 cout<<endl<<"//////////////////////////////////////";
                 cout<< "La persona que se intento buscar se encuentra entre las personas creadas en lista"<<endl<<endl;
                 //cout << tempPrueba->persona->esposa->imprimir();
                 //cout << tempPrueba->persona->hijos->imprimir();
                 estaIdLista = true;
                 if(tempPrueba->persona->esposa!=NULL && !tempPrueba->persona->hijos->isEmpty()){
                     return "Pareja: "+tempPrueba->persona->esposa->imprimir()+"\n"+
                             "Hijos: "+tempPrueba->persona->hijos->imprimir();
                 }else if(!tempPrueba->persona->hijos->isEmpty()){
                     return "Hijos: "+tempPrueba->persona->hijos->imprimir()+"\n";
                 }else if(tempPrueba->persona->esposa!=NULL){
                     return "Pareja: "+tempPrueba->persona->esposa->imprimir();
                 }else{
                     return "Esta persona no tiene pareja ni hijos.\n";
                 }


             }

             tempPrueba=tempPrueba->siguiente;
         }

     }
     if (!estaIdArbol && !estaIdLista)  {
         cout << "La persona que intenta buscar no esta creada ni en el arbol ni en la lista";
         return "La familia buscada no se encuentra en el mundo. \n";
     }

    return "";
}//fin de consultaFailiaID

string ConsultaMundo::consultaAmigosID(int consultaAmigosId, NodoArbol *arbol){

    bool estaIdArbol=false;
    bool estaIdLista = false;
    //arbol = arbolPersonas->raiz;

    while (arbol != NULL) { //falta obtener el dato del arbol
        if (arbol->persona->persona->ID==consultaAmigosId) { //si el idConsultaHumano es igual al elemento
            //aqui se deberia imprimir todos los amigos de la persona consultada
            /*cout<< "La persona que se intento buscar se encuentra entre las personas creadas en el arbol"<<endl<<endl;
            cout << arbol->persona->persona->amigos->imprimirAmigos();
            cout<<endl;*/
            estaIdArbol=true;
            return arbol->persona->persona->amigos->imprimirAmigos();

        }
        else if (arbol->persona->persona->ID < consultaAmigosId) { // si el elemento es mayor que la raiz se llama recursivamente a la funcion llamando al hijo derecho
            return consultaHumanoID(consultaAmigosId,arbol->hijoderecho);
        }
        else if (arbol->persona->persona->ID > consultaAmigosId) { // si el elemento es menor que la raiz se llama recursivamente a la funcion llamando al hijo izquierdo
            return consultaHumanoID(consultaAmigosId,arbol->hijoizquierdo);
        }

    }

     if(estaIdArbol == false){
         NodoPersona *tempPrueba = personas->primerNodo;
         int w=1;
         while (tempPrueba != NULL) {
             if (tempPrueba->persona->ID == consultaAmigosId) {
                 //aqui se deberia imprimir todos los amigos de la persona consultada
                 /*cout<<endl<<"//////////////////////////////////////";
                 cout<< "La persona que se intento buscar se encuentra entre las personas creadas en lista"<<endl<<endl;
                 cout << tempPrueba->persona->amigos->imprimirAmigos();
                 cout << endl;*/
                 estaIdLista=true;
                 return  tempPrueba->persona->amigos->imprimirAmigos();

             }

             else {
                 cout << w;
                 cout<<" La persona que intenta buscar no existe. \n"<<endl;
             }
             w++;
             tempPrueba=tempPrueba->siguiente;
         }
     }
     else if (estaIdArbol == false && estaIdLista == false) {
         cout << "La persona que intenta buscar no esta creada ni en el arbol ni en la lista";
        return "No se encontro la persona buscada";
     }

    return "";
}//consultaAmigosID

string ConsultaMundo::consultaDeportes(string deporteConsultado){

    bool estaIdLista = false;
    string total = "";
    /*
    arbol = arbolPersonas->raiz;

    while (arbol != NULL) {
        NodoDeporte *tempDepor = arbol->persona->persona->deportes->primerNodo;
        if (tempDepor->nombre == deporteConsultado) {

        }
        while (tempDepor->nombre == deporteConsultado) {
            cout<< "La persona que se intento buscar se encuentra entre las personas creadas en el arbol"<<endl<<endl;
            cout<<arbol->persona->persona->nombre<<" "<<arbol->persona->persona->apellido<<"   "<<arbol->persona->persona->ID<<" \n"<< arbol->persona->persona->continenteVive<<"  "<<arbol->persona->persona->nacDia<<"/"<<arbol->persona->persona->nacMes<<"/"<<arbol->persona->persona->nacAno<< "   " <<arbol->persona->persona->rangoEtario<< "   "<<arbol->persona->persona->creencia <<endl<< "Profesion: "<< arbol->persona->persona->profesion << endl<< "Vive en  "<<arbol->persona->persona->paisVive<<endl<<arbol->persona->persona->estadoMarital<<endl<<arbol->persona->persona->pecados->imprimir()<<endl;
            cout<<endl;
            estaIdArbol=true;
            break;
            tempDepor=tempDepor->siguiente;
        }

        else if (arbol->persona->persona->ID < deporteConsultado) { // si el elemento es mayor que la raiz se llama recursivamente a la funcion llamando al hijo derecho
            return consultaHumanoID(deporteConsultado,arbol->hijoderecho);
        }
        else if (arbol->persona->persona->ID > deporteConsultado) { // si el elemento es menor que la raiz se llama recursivamente a la funcion llamando al hijo izquierdo
            return consultaHumanoID(deporteConsultado,arbol->hijoizquierdo);
        }


    }
    */
         cout<<"Entro idA"<<endl;
         NodoPersona *tempPrueba = personas->primerNodo;

         while (tempPrueba != NULL) {
             cout<<"TempPrueba"<<endl;
             NodoDeporte *tempDeporte = tempPrueba->persona->deportes->primerNodo;
             while (tempDeporte != NULL) {
                 //cout<<"TempDeporte"<<endl;
                 if (tempDeporte->nombre==deporteConsultado) {
                     /*cout<<endl<<"//////////////////////////////////////";
                     cout<< "La persona "<< tempPrueba->persona->nombre <<" "<<tempPrueba->persona->apellido<<" practica el deporte "<<deporteConsultado<<endl<<endl;
                     cout<<tempPrueba->persona->nombre<<" "<<tempPrueba->persona->apellido<<"   "<<tempPrueba->persona->ID<<" \n"<<tempPrueba->persona->continenteVive<<"  "<<tempPrueba->persona->nacDia<<"/"<<tempPrueba->persona->nacMes<<"/"<<tempPrueba->persona->nacAno<< "   " <<tempPrueba->persona->rangoEtario<< "   "<<tempPrueba->persona->creencia <<endl<< "Profesion: "<< tempPrueba->persona->profesion << endl<< "Vive en  "<<tempPrueba->persona->paisVive<<endl<<tempPrueba->persona->estadoMarital<<endl<<tempPrueba->persona->pecados->imprimir()<<endl;
                     cout<<endl;*/
                     estaIdLista=true;
                     total += tempPrueba->persona->imprimir();
                     //cout<<"Deporte"<<endl;
                     break;
                 }

                 tempDeporte= tempDeporte->siguiente;
             }//fin del while


             tempPrueba=tempPrueba->siguiente;
         }
     if (!estaIdLista) {
         cout << "Ninguna de las personas creadas practica el deporte que intento buscar";
         return "Ninguna persona encontrada que practique ese deporte. \n";
     }


    return total;


}//fin consultaDeportes

string ConsultaMundo::humanosVivos(){

    NodoPersona* temp = listaDoble->primerNodo;
    ListaDoble* listaTemp = new ListaDoble();

    while(temp != NULL){
        if(temp->persona->vivo){
            listaTemp->insertionSort(temp->persona);
        }
        temp = temp->siguiente;
    }

    return listaTemp->imprimir();

}//fin de humanos Vivos

string ConsultaMundo::humanosSalvados(){

    NodoPersona* temp = listaDoble->primerNodo;
    ListaDoble* listaTemp = new ListaDoble();

    while(temp != NULL){
        if(temp->persona->vivo && !temp->persona->revivido->isEmpty()){
            listaTemp->insertionSort(temp->persona);
        }
        temp = temp->siguiente;
    }

    return listaTemp->imprimir();

}//fin de HumanosSalvados

string ConsultaMundo::humanosEliminados(){

    NodoPersona* temp = listaDoble->primerNodo;
    ListaDoble* listaTemp = new ListaDoble();

    while(temp != NULL){
        if( !temp->persona->vivo){
            listaTemp->insertionSort(temp->persona);
        }
        temp = temp->siguiente;
    }

    return listaTemp->imprimir();

}//fin de humanosElimidados

string ConsultaMundo::humanosViviosSalvadosEliminados(){
    return "Humanos vivos\n"+humanosVivos()+
            "\nHumanos salvados\n"+humanosSalvados()+
            "\nHumanos eliminados\n"+humanosEliminados();
}

void ConsultaMundo::setArbolMundo(Arbol* _arbol, ListaDoble* _mundo){
    this->arbol = _arbol;
    this->listaDoble = _mundo;
}
