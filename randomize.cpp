#include "randomize.h"
#include "persona.h"
Randomize::Randomize()
{

}

string Randomize::generarNombresM(vector<string> listaNombresM){
    int indice=int(QRandomGenerator::global()->bounded(0, 221)); //CAMBIAR POR 500 CUANDO YA ESTEN LOS 500
    for (int i=0; i<int(listaNombresM.size());i++){
        if(i==indice){
            string nombre=listaNombresM.at(i); //VECTOR
            return nombre;
        }
    }
    return NULL;
}

string Randomize::generarNombresF(vector<string> listaNombresF){
    int indice=int(QRandomGenerator::global()->bounded(0, 115)); //CAMBIAR POR 500 CUANDO YA ESTEN LOS 500
    for (int i=0; i<int(listaNombresF.size());i++){
        if(i==indice){
            string nombre=listaNombresF.at(i); //VECTOR
            return nombre;
        }
    }
    return NULL;
}

string Randomize::generarApellidos(vector<string> listaApellidos){
    int indice=int(QRandomGenerator::global()->bounded(0, 193)); //CAMBIAR POR 500 CUANDO YA ESTEN LOS 500
    for (int i=0; i<int(listaApellidos.size()); i++){
        if(i==indice){
            string nombre=listaApellidos.at(i); //VECTOR
            return nombre;
        }
    }
    return NULL;
}

bool Randomize::estaID(ListaDoble *personas, int id){
    NodoPersona * tmp = personas->primerNodo;
    while (tmp != NULL){
            if(id==tmp->persona->ID){
                return true;
            }
             tmp = tmp->siguiente;
    }
    return false;
}

int Randomize::generarId(ListaDoble *personas){
    int id=int(QRandomGenerator::global()->bounded(0, 999999));
    if(!personas->isEmpty()){
        NodoPersona * tmp = personas->primerNodo;
        while (tmp != NULL && !estaID(personas, id)){
            if(estaID(personas, id)){
                Randomize::generarId(personas);
            }
            tmp=tmp->siguiente;
        }
    }
    return id;
}

string Randomize::generarContinente(){
    int continente=int(QRandomGenerator::global()->bounded(0, 6));

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
    int indice=int(QRandomGenerator::global()->bounded(0, 192));
    for (int i=0; i<=int(listaPaises.size()); i++){
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
        int sumaIncidencia=int(QRandomGenerator::global()->bounded(0, 100));
        tmp->cantidad+=sumaIncidencia;
        tmp=tmp->siguiente;
    }
}

bool Randomize::esHijoPosible(Persona *hijo, Persona *padre){
    if(padre!=NULL){
        if(2021-std::stoi(padre->nacAno)>=20 && 2021-std::stoi(padre->nacAno)<=24
             && 2021-std::stoi(hijo->nacAno)<=4){
              return true;
          }else if(2021-std::stoi(padre->nacAno)>=25 && 2021-std::stoi(padre->nacAno)<=34
             && 2021-std::stoi(hijo->nacAno)<=14){
              return true;
          }else if(2021-std::stoi(padre->nacAno)>=35 && 2021-std::stoi(padre->nacAno)<=64
             && 2021-std::stoi(hijo->nacAno)>=15 && 2021-std::stoi(hijo->nacAno)<=34 ){
              return true;
          }else if(2021-std::stoi(padre->nacAno)<=65
             && 2021-std::stoi(hijo->nacAno)>=25 && 2021-std::stoi(hijo->nacAno)<=64 ){
             return true;
          }else{
              return false;
          }
    }
    return false;
}

bool Randomize::validarPadres(Persona *hijo, Persona *padre){
    if(padre!=NULL){
        if(hijo->apellido==padre->apellido){
            if(hijo->paisVive==padre->paisVive){
                if(esHijoPosible(hijo,padre)){
                    if(!hijo->esHijo){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Randomize::agregarHijos(ListaDoble *personas, Persona *padre){
    int cantidadHijos=int(QRandomGenerator::global()->bounded(0, 5));;
    NodoPersona * tmp = personas->primerNodo;
    for(int i=0; i<cantidadHijos;i++){
        while(tmp!=NULL){
                if(tmp->persona->ID!=padre->ID){
                    if(validarPadres(tmp->persona, padre)){
                        if(padre->hijos->largo()<cantidadHijos){
                            tmp->persona->esHijo=true;
                            tmp->persona->padre=padre;
                            padre->hijos->insertarAlInicio(tmp->persona);
                            if(padre->esposa!=NULL){
                                if(tmp->persona->ID!=padre->esposa->ID){
                                tmp->persona->esHijo=true;
                                tmp->persona->madre=padre->esposa;
                                padre->esposa->hijos->insertarAlInicio(tmp->persona);
                                }
                            }
                        }
                    }
                }
                tmp=tmp->siguiente;
        }
    }

}
void Randomize::asignarPareja(ListaDoble *personas){
    NodoPersona * tmp = personas->primerNodo;
    while (tmp != NULL){
        if(tmp->persona->estadoMarital=="Casado" && !tmp->persona->tienePareja){
            for(int i=0;i<personas->largo();i++){
                 NodoPersona * tmp2=personas->BuscarEnPos(i);
                 if(tmp2->persona->estadoMarital=="Casado" && !tmp2->persona->tienePareja &&
                         tmp2->persona->ID!=tmp->persona->ID){
                     tmp2->persona->tienePareja=true;
                     tmp2->persona->esposa=tmp->persona;
                     tmp->persona->tienePareja=true;
                     tmp->persona->esposa=tmp2->persona;
                 }
            }

        }
         tmp=tmp->siguiente;
    }
}

int Randomize::aletorioDia(){
    int dia=int(QRandomGenerator::global()->bounded(0, 30));
    return dia;
}

string Randomize::aleatorioMes(){
    string meses[12]={"enero", "febrero","marzo","abril","mayo","junio","julio","agosto","setiembre","octubre","noviembre","diciembre"};
    int mesInt=int(QRandomGenerator::global()->bounded(0, 11));
    return meses[mesInt];
}

int Randomize::aletorioAno(){

    int ano=int(QRandomGenerator::global()->bounded(1900,2021));
    //int edad = 2021-ano;
    return ano;
}

bool Randomize::aleatorioGenero(){
     std::uniform_int_distribution<int> genero1(1,2);
    int genero= genero1(*QRandomGenerator::global());
    if(genero==1){
        //Masculino
        return false;
    }
    else{
        //Femenino
        return true;
    }
}

int Randomize::edad(){
    int ano = aletorioAno();
    int edad=2020-ano;
    return edad;
}

string Randomize::estadoMarital(){
    int estadoMarital=int(QRandomGenerator::global()->bounded(0, 101));

    if(estadoMarital <= 10){
        return "Soltero";
    }else if(10 <= estadoMarital && estadoMarital<= 90){
        return "Casado";
    }else
        return "Divorciado";
}

string Randomize::generarRangoEtario(int anno){
    int edad=2020-anno;
    if(edad<=1){
        return "Infantil";
    }else if(edad>=2 && edad<=4){
        return "Pre-escolar";
    }else if(edad>=5 && edad<=10){
        return "Escolar";
    }else if(edad>=11 && edad<=14){
        return "Pubertad";
    }else if(edad>=15 && edad<=19){
        return "Adolescencia";
    }else if(edad>=20 && edad<=24){
        return "Joven";
    }else if(edad>=25 && edad<=34){
        return "Adulto joven";
    }else if(edad>=35 && edad<=64){
        return "Adulto maduro";
    }else if(edad>=65){
        return "Adulto mayor";
    }else{
        return 0;
    }
}

bool Randomize::comprobarExistencia(Persona *amigo, Persona *personaActual){
    Persona * tmp = personaActual;
    if(personaActual->amigos->isEmpty() || amigo->amigos->isEmpty()){
        return false; //No esta el amigo en la lista
    }else{
        for(int i=0;i<tmp->amigos->largo();i++){
            NodoPersona *amigoActual=tmp->amigos->BuscarEnPos(i);
            if(amigoActual->persona->ID==amigo->ID){
                return true; //El amigo ya esta en la lista
            }
        }
        return false; //El amigo no esta en la lista
    }
}

bool Randomize::comprobarAmigos(Persona *amigo, Persona *personaActual){
    NodoPersona * tmp = personaActual->amigos->primerNodo;
    NodoPersona * tmp2 = amigo->amigos->primerNodo;
    if(tmp==NULL || tmp2==NULL){
        return false; //No hay amigos en comun
    }else{
        while(tmp!=NULL){
            for(int i=0;i<amigo->amigos->largo();i++){
                NodoPersona *amigoActual=amigo->amigos->BuscarEnPos(i);
                if(amigoActual->persona->ID==tmp->persona->ID){
                    return true; //Hay amigos en comun
                }
            }
            tmp=tmp->siguiente;
        }
        return false;
    }
}

void Randomize::agregarAmigos(ListaDoble *personas,  Persona *personaActual){ //Agrega a algunos varias veces, revisar logica. Consulta?
    int cantidadAmigos=int(QRandomGenerator::global()->bounded(0, 51));
    int probabilidadPais=int(QRandomGenerator::global()->bounded(0, 101));
    int probabilidadComun=int(QRandomGenerator::global()->bounded(0, 101));
    NodoPersona * tmp;
    for(int i=0; i<cantidadAmigos; i++){
        //while (tmp != NULL){
        int posicionRandom=int(QRandomGenerator::global()->bounded(0, personas->largo()));
        tmp=personas->BuscarEnPos(posicionRandom);
            if(tmp->persona->ID!=personaActual->ID){
                if(!comprobarExistencia(tmp->persona, personaActual)){
                    if(tmp->persona->paisVive==personaActual->paisVive || probabilidadPais<=40){
                        personaActual->amigos->insertarAlInicio(tmp->persona);
                            if(!comprobarExistencia(personaActual, tmp->persona)){
                               tmp->persona->amigos->insertarAlInicio(personaActual);
                            }
                    }else if(comprobarAmigos(tmp->persona,personaActual) || probabilidadComun<=70){
                        personaActual->amigos->insertarAlInicio(tmp->persona);
                        if(!comprobarExistencia(personaActual, tmp->persona)){
                           tmp->persona->amigos->insertarAlInicio(personaActual);
                        }
                    }
                }
            }
            //tmp=tmp->siguiente;
        //}
    }
}



string Randomize::generarProfesion(vector<string> listaProfesion){
    int indice=int(QRandomGenerator::global()->bounded(0, 89));
    for (int i=0; i<int(listaProfesion.size());i++){
        if(i==indice){
            string profesion=listaProfesion.at(i);
            return profesion;
        }
    }
    return 0;
}

string Randomize::generarCreencia(vector<string> listaCreencia){
    int indice=int(QRandomGenerator::global()->bounded(0, 17));
    for (int i=0; i<int(listaCreencia.size());i++){
        if(i==indice){
            string nombre=listaCreencia.at(i);
            return nombre;
        }
    }
    return 0;
}

void Randomize::generarPaisesVisitados(vector<string> listaPaisesVisitados, ListaSimple *paises){
    int indice = int(QRandomGenerator::global()->bounded(0, 30));
    if(indice == 0){
         paises->insertarAlFinal("No ha visitado ningún país.");
    }//if
    else{
        for(int i=0; i<=indice; i++){
            int visitado= int(QRandomGenerator::global()->bounded(0, 192));
            string visi=listaPaisesVisitados.at(visitado);
            paises->insertarAlFinal(visi);
        }//for
    }//else
}//generarPaisesVisiatdos

void Randomize::generarDeportes(vector<string> listaDeportes, ListaDeportes *listadeportes){
    int indice = int(QRandomGenerator::global()->bounded(0, 7));
    if(indice == 0){
        listadeportes->insertarAlFinal(indice,"No practica ningún deporte en la semana");
    }//if
    else{
        for (int i=0; i<=indice;i++){
            int deportePractica = int(QRandomGenerator::global()->bounded(0, 97));
            int vecesSemana = int(QRandomGenerator::global()->bounded(1,7));
            string deporte=listaDeportes.at(deportePractica);
            listadeportes->insertarAlFinal(vecesSemana,deporte);
        }//for
    }//else
}//generarDeportes

