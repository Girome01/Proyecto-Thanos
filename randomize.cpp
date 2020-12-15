#include "randomize.h"

Randomize::Randomize()
{

}

// GENERACIÓN DE LA LISTA DE NOMBRES MASCULINOS DESDE ARCHIVOS. LÓGICA SE UTILIZA PARA TODOS LOS ARCHIVOS!!!!
//UTILIZA VECTOR.
//EL DELIMITADOR ENTRE NOMBRES ES #.

/*
 * QString texto=leerArchivo();
    std::vector<string> listaNombres;
    if(texto!=NULL){
        std::string delimiter = "#";

        size_t last = 0;
        size_t next = 0;
        while ((next = texto.toStdString().find(delimiter, last)) != string::npos) {
            //cout << texto.toStdString().substr(last, next-last) << endl;
            listaNombres.push_back(texto.toStdString().substr(last, next-last));
            last = next + 1;
        }
        cout << texto.toStdString().substr(last) << endl;
        return listaNombres;

*/

// *****************VALIDACIÓN DIVISIÓN ENTRE 0*************************

string Randomize::generarNombresM(vector<string> listaNombresM){
    std::uniform_int_distribution<int> dist(0,999);
    int indice=dist(*QRandomGenerator::global())%999;
    for (int i=0; i<=listaNombresM.size();i++){
        if(i==indice){
            string nombre=listaNombresM.at(i); //VECTOR
            return nombre;
        }
    }
    return 0;
}

string Randomize::generarNombresF(vector<string> listaNombresF){
    std::uniform_int_distribution<int> dist(0,999);
    int indice=dist(*QRandomGenerator::global())%999;
    for (int i=0; i<=listaNombresF.size();i++){
        if(i==indice){
            string nombre=listaNombresF.at(i); //VECTOR
            return nombre;
        }
    }
    return 0;
}

string Randomize::generarApellidos(vector<string> listaApellidos){
    std::uniform_int_distribution<int> dist(0,99);
    int indice=dist(*QRandomGenerator::global())%99;
    for (int i=0; i<=listaApellidos.size(); i++){
        if(i==indice){
            string nombre=listaApellidos.at(i); //VECTOR
            return nombre;
        }
    }
    return 0;

}

bool Randomize::estaID(ListaDoble *personas, int id){
    NodoPersona * tmp = personas->primerNodo;
    while (tmp != NULL){
            if(id==tmp->persona->ID){
                return true;
            }
             tmp = tmp->siguiente;
    }

}

int Randomize::generarId(ListaDoble *personas){
    std::uniform_int_distribution<int> dist(0,999999);
    int id=dist(*QRandomGenerator::global())%999999;

    NodoPersona * tmp = personas->primerNodo;
    while (tmp != NULL){
            if(estaID(personas, id)){
                Randomize::generarId(personas);
            }

            tmp=tmp->siguiente;
    }
    return id;
}

string Randomize::generarContinente(){
    std::uniform_int_distribution<int> dist(0,5);
    int continente=dist(*QRandomGenerator::global())%5;

    switch(continente){
    case 0:
        return "America";
        break;
    case 1:
        return "Europa";
        break;
    case 2:
        return "Asia";
        break;
    case 3:
        return "Africa";
        break;
    case 4:
        return "Oceania";
        break;
    case 5:
        return "Antartida";
        break;
   default:
        return 0;
    }
}

string Randomize::generarPais(vector<string> listaPaises){

    //Generar ***lista*** países en otro lugar.
    //La lógica es igual que la función comentada de arriba. :)

    std::uniform_int_distribution<int> dist(0,100);
    int indice=dist(*QRandomGenerator::global())%100;
    for (int i=0; i<=listaPaises.size(); i++){
        if(i==indice){
            string nombreP=listaPaises.at(i); //VECTOR
            return nombreP;
        }
    }
    return 0;
}

void Randomize::generarPecados(ListaPecVir *listapecvir){
    PecadoVirtud * tmp = listapecvir->primerNodo;
    while (tmp != NULL){
        std::uniform_int_distribution<int> dist(0,99);
        int sumaIncidencia=dist(*QRandomGenerator::global())%99;
        tmp->cantidad+=sumaIncidencia;
        tmp=tmp->siguiente;
    }
}

bool Randomize::esHijoPosible(Persona *hijo, Persona *padre){
      if(2020-std::stoi(padre->nacAno)>=20 && 2020-std::stoi(padre->nacAno)<=24
         && 2020-std::stoi(hijo->nacAno)<=4){
          return true;
      }else if(2020-std::stoi(padre->nacAno)>=25 && 2020-std::stoi(padre->nacAno)<=34
         && 2020-std::stoi(hijo->nacAno)<=14){
          return true;
      }else if(2020-std::stoi(padre->nacAno)>=35 && 2020-std::stoi(padre->nacAno)<=64
         && 2020-std::stoi(hijo->nacAno)>=15 && 2020-std::stoi(hijo->nacAno)<=34 ){
          return true;
      }else if(2020-std::stoi(padre->nacAno)<=65
         && 2020-std::stoi(hijo->nacAno)>=25 && 2020-std::stoi(hijo->nacAno)<=64 ){
         return true;
      }else{
          return false;
      }
}

void Randomize::agregarHijos(ListaDoble *personas, Persona *padre){
    std::uniform_int_distribution<int> dist(0,4);
    int indice=dist(*QRandomGenerator::global())%4;
    int contador=0;
    NodoPersona * tmp = personas->primerNodo;
    while (tmp != NULL){
        if(tmp->persona->apeelido==padre->apeelido){
            if(esHijoPosible(tmp->persona, padre)){
                    if(tmp->persona->paisVive==padre->paisVive){
                        /*
                         * if(!tmp->persona->esHijo) Esto podría ser un bool true si ya tiene padres asignados
                         *                           false sino. (¿?) Incluso tener quién es el padre y la madre.
                        */
                        if(contador<=indice){
                            padre->hijos->insertarAlInicio(tmp->persona);
                            padre->esposa->hijos->insertarAlInicio(tmp->persona);
                            contador++;
                        }
                    }
            }

        }
        tmp=tmp->siguiente;
    }
}

