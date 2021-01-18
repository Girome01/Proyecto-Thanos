#include "consultamundo.h"

ConsultaMundo::ConsultaMundo()
{

}
ListaDoble *personas=new ListaDoble();
Arbol *arbolPersonas = new Arbol();
ListaSimple *deportes = new ListaSimple();
ListaElimSalv *elimSal = new ListaElimSalv();
ListaDeportes *dprt = new ListaDeportes();

string ConsultaMundo::consultaHumanoID(int idConsultaHumano, NodoArbol *arbol){
    bool estaIdArbol=false;
    bool estaIdLista = false;
    arbol = arbolPersonas->raiz;
    
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
     else if (estaIdArbol == false && estaIdLista == false) {
        //cout << "La persona que intenta buscar no esta creada ni en el arbol ni en la lista";
        return "No se encuentra la persona buscada";
     }
     return "";
}//fin de consultaHumanoID

string ConsultaMundo::consultaFamiliaID(int ConsultaFamiliaId, NodoArbol *arbol){
    
    bool estaIdArbol=false;
    bool estaIdLista = false;
    arbol = arbolPersonas->raiz;
    
    while (arbol != NULL) {
        if (arbol->persona->persona->ID==ConsultaFamiliaId) { //si el idConsultaHumano es igual al elemento
            //aqui se deberia imprimir toda la informacion de la familia de persona consultada
            /*cout<< "La persona que se intento buscar se encuentra entre las personas creadas en el arbol"<<endl<<endl;
            cout << arbol->persona->persona->esposa->nombre;
            cout << arbol->persona->persona->hijos->imprimir();
            cout<<endl;*/
            estaIdArbol=true;
            return arbol->persona->persona->esposa->imprimir()+"\n"+
                    arbol->persona->persona->hijos->imprimir();
            
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
                 cout << tempPrueba->persona->esposa->imprimir();
                 cout << tempPrueba->persona->hijos->imprimir();
                 cout << endl;
                 estaIdLista = true;
                 return tempPrueba->persona->esposa->imprimir()+"\n"+
                         tempPrueba->persona->hijos->imprimir();
 
             }

             tempPrueba=tempPrueba->siguiente;
         }
     }
    
     else if (estaIdArbol == false && estaIdLista == false) {
         //cout << "La persona que intenta buscar no esta creada ni en el arbol ni en la lista";
         return "La familia buscada no se encuentra en el mundo";
     }

    return "";
}//fin de consultaFailiaID

string ConsultaMundo::consultaAmigosID(int consultaAmigosId, NodoArbol *arbol){
    
    bool estaIdArbol=false;
    bool estaIdLista = false;
    arbol = arbolPersonas->raiz;
    
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
                 cout<<" La persona que intenta buscar no existe"<<endl;
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
    
    bool estaIdArbol=false;
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
     if(estaIdArbol == false){
         NodoPersona *tempPrueba = personas->primerNodo;
         
         while (tempPrueba != NULL) {
             NodoDeporte *tempDeporte = tempPrueba->persona->deportes->primerNodo;
             while (tempDeporte != NULL) {
                 if (tempDeporte->nombre==deporteConsultado) {
                     /*cout<<endl<<"//////////////////////////////////////";
                     cout<< "La persona "<< tempPrueba->persona->nombre <<" "<<tempPrueba->persona->apellido<<" practica el deporte "<<deporteConsultado<<endl<<endl;
                     cout<<tempPrueba->persona->nombre<<" "<<tempPrueba->persona->apellido<<"   "<<tempPrueba->persona->ID<<" \n"<<tempPrueba->persona->continenteVive<<"  "<<tempPrueba->persona->nacDia<<"/"<<tempPrueba->persona->nacMes<<"/"<<tempPrueba->persona->nacAno<< "   " <<tempPrueba->persona->rangoEtario<< "   "<<tempPrueba->persona->creencia <<endl<< "Profesion: "<< tempPrueba->persona->profesion << endl<< "Vive en  "<<tempPrueba->persona->paisVive<<endl<<tempPrueba->persona->estadoMarital<<endl<<tempPrueba->persona->pecados->imprimir()<<endl;
                     cout<<endl;*/
                     estaIdLista=true;
                     total += tempPrueba->persona->imprimir();
                     break;
                 }                 
                 
                 tempDeporte= tempDeporte->siguiente;
             }//fin del while

             
             tempPrueba=tempPrueba->siguiente;
         }
     }
     else if (estaIdArbol == false && estaIdLista == false) {
         cout << "Ninguna de las personas creadas practica el deporte que intento buscar";
         return "Ninguna persona encontrada que practique ese deporte";
     }
    

    return total;


}//fin consultaDeportes

string ConsultaMundo::humanosVivos(){
    
    NodoDato *temp = elimSal->primerNodo;
    
    if (elimSal->isEmpty()) {
        //no hay ninguna persona viva
        ListaElimSalv().insertarAlFinal("No hay personas vivas");
        cout<<"No hay persona vivas"<<endl;
    }
    else {
        cout<<"------------------------Lista de persona vivas-------------------"<<endl;
        while (temp != NULL) {
            cout<<temp->datos<<endl;
            temp=temp->siguiente;
        }
        //ListaElimSalv().imrpimir();
    }
    return 0;

}//fin de humanos Vivos

string ConsultaMundo::humanosSalvados(){
    NodoDato *temp= elimSal->primerNodo;
    if (elimSal->isEmpty()) {
        //no ha salvado a ninguna persona
        ListaElimSalv().insertarAlFinal("No hay personas salvadas");
    }
    else {
        cout<<"------------------------Lista de persona salvadas-------------------"<<endl;
        while (temp != NULL) {
            cout<<temp->datos<<endl;
            temp=temp->siguiente;
        }
        //ListaElimSalv().imrpimir();
    }
    return 0;

}//fin de HumanosSalvados

string ConsultaMundo::humanosEliminados(){
    NodoDato *temp= elimSal->primerNodo;
    if (elimSal->isEmpty()) {
        //no ha eliminado a ninguna persona
        ListaElimSalv().insertarAlFinal("No hay personas eliminadas");
    }
    else {
        cout<<"------------------------Lista de persona eliminadas-------------------"<<endl;
        while (temp != NULL) {
            cout<<temp->datos<<endl;
            temp=temp->siguiente;
        }
        ListaElimSalv().imrpimir();
    }
    return 0;

}//fin de humanosElimidados
