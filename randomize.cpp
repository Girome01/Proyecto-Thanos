#include "randomize.h"
#include "persona.h"
Randomize::Randomize()
{

}

string Randomize::generarNombresM(vector<string> listaNombresM){
    int indice=int(QRandomGenerator::global()->bounded(0, 10)); //CAMBIAR POR 500 CUANDO YA ESTEN LOS 500
    for (int i=0; i<int(listaNombresM.size());i++){
        if(i==indice){
            string nombre=listaNombresM.at(i); //VECTOR
            return nombre;
        }
    }
    return 0;
}

string Randomize::generarNombresF(vector<string> listaNombresF){
    int indice=int(QRandomGenerator::global()->bounded(0, 10)); //CAMBIAR POR 500 CUANDO YA ESTEN LOS 500
    for (int i=0; i<int(listaNombresF.size());i++){
        if(i==indice){
            string nombre=listaNombresF.at(i); //VECTOR
            return nombre;
        }
    }
    return 0;
}

string Randomize::generarApellidos(vector<string> listaApellidos){
    int indice=int(QRandomGenerator::global()->bounded(0, 25)); //CAMBIAR POR 500 CUANDO YA ESTEN LOS 500
    for (int i=0; i<int(listaApellidos.size()); i++){
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
                tmp->persona->ID=id;

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
    int indice=int(QRandomGenerator::global()->bounded(0, 194)); //CAMBIAR POR 100 CUANDO YA ESTEN LOS 100
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
    int indice=int(QRandomGenerator::global()->bounded(0, 5));;
    int contador=0;
    NodoPersona * tmp = personas->primerNodo;
    while (tmp != NULL){
        if(tmp->persona->apellido == padre->apellido){
            if(esHijoPosible(tmp->persona, padre)){
                    if(tmp->persona->paisVive==padre->paisVive || tmp->persona->paisVive==padre->esposa->paisVive){
                         if(!tmp->persona->esHijo){
                            if(contador<=indice){
                                padre->hijos->insertarAlInicio(tmp->persona);
                                padre->esposa->hijos->insertarAlInicio(tmp->persona);
                                tmp->persona->esHijo=true;
                                contador++;
                            }
                        }
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
    //`int edad = 2021-ano;
    return ano;
}

bool Randomize::aleatorioGenero(){
     std::uniform_int_distribution<int> genero1(1,2);
    int genero= genero1(*QRandomGenerator::global());
    if(genero==1){
        cout << "El genero de la persona es masculino:" << genero;
        return false;
    }
    else{
        cout << "El genero de la persona es femenino: "<< genero;
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
    NodoPersona * tmp = amigo->amigos->primerNodo;
    NodoPersona * tmp2 = personaActual->amigos->primerNodo;
    if(tmp==NULL || tmp2==NULL)
        return false;
    while(tmp!=NULL){
        while(tmp2!=NULL){
            if(tmp->persona->ID==tmp2->persona->ID)
                return true;
            tmp2=tmp2->siguiente;
        }
        tmp=tmp->siguiente;
    }
    return false;
}

bool Randomize::comprobarAmigos(Persona *amigo, Persona *personaActual){
    NodoPersona * tmp = amigo->amigos->primerNodo;
    NodoPersona * tmp2 = personaActual->amigos->primerNodo;
    if(tmp==NULL || tmp2==NULL)
        return false;
    while(tmp!=NULL){
        while(tmp2!=NULL){
            if(tmp->persona==tmp2->persona)
                    return true;
            tmp2=tmp2->siguiente;
        }
        tmp=tmp->siguiente;
    }
    return false;
}

void Randomize::agregarAmigos(ListaDoble *personas,  Persona *personaActual){ //Agrega a algunos varias veces, revisar logica. Consulta?
    int cantidadAmigos=int(QRandomGenerator::global()->bounded(0, 51));
    int probabilidadPais=int(QRandomGenerator::global()->bounded(0, 101));
    int probabilidadComun=int(QRandomGenerator::global()->bounded(0, 101));
    NodoPersona * tmp = personas->primerNodo;
    for(int i=0; i<cantidadAmigos; i++){
        while (tmp != NULL){
            if((personaActual->paisVive==tmp->persona->paisVive &&
               personaActual->ID!=tmp->persona->ID) || probabilidadPais<=40){
                if(!comprobarExistencia(tmp->persona, personaActual)){
                    personaActual->amigos->insertarAlFinal(tmp->persona);
                    tmp->persona->amigos->insertarAlFinal(personaActual);
                }
            }else if(comprobarAmigos(tmp->persona,personaActual)
              && personaActual->ID!=tmp->persona->ID){
                if(probabilidadComun<=70){
                    if(!comprobarExistencia(tmp->persona, personaActual)){
                     personaActual->amigos->insertarAlFinal(tmp->persona);\
                     tmp->persona->amigos->insertarAlFinal(personaActual);
                    }
                }
            }
            tmp=tmp->siguiente;
        }
    }
}

string Randomize::generarProfesion(vector<string> listaProfesion){
    int indice=int(QRandomGenerator::global()->bounded(0, 90));
    for (int i=0; i<int(listaProfesion.size());i++){
        if(i==indice){
            string profesion=listaProfesion.at(i);
            return profesion;
        }
    }
    return 0;
}

string Randomize::generarCreencia(vector<string> listaCreencia){
    int indice=int(QRandomGenerator::global()->bounded(0, 16));
    for (int i=0; i<int(listaCreencia.size());i++){
        if(i==indice){
            string nombre=listaCreencia.at(i);
            return nombre;
        }
    }
    return 0;
}
/*
string Randomize::generarPaisesVisitados(vector<string> listaPaisesVisitados){
    int cantPaisesVisitados=int(QRandomGenerator::global()->bounded(0, 30));
    for(int i = 0; i <=){
        for (int i=0; i<=int(listaPaisesVisitados.size()); i++){
            int PaisVisitado=int(QRandomGenerator::global()->bounded(0, 194));
            if(i==PaisVisitado){
                string visitado=listaPaisesVisitados.at(i); //VECTOR
                return visitado;
            }
        }
        return 0;
    }
    return 0;

}

                std::vector<string> listaApellidos;
                listaApellidos=generarlistaNombres(texto2);.

*/

string Randomize::generarPaisesVisitados(vector<string> listaPaisesVisitados){
    int indice = int(QRandomGenerator::global()->bounded(0, 30));
    if(indice == 0){
        ListaSimple().insertarAlFinal("No ha visitado ningún país");
    }//if
    else{
        for ( int j=0; j <= indice; j++ ){
            int visitado= int(QRandomGenerator::global()->bounded(0, 194));
            string visi=listaPaisesVisitados.at(visitado);
            ListaSimple().insertarAlFinal(visi);
        }//for
    }//else
    return 0;
}//generarPaisesVisiatdos

string Randomize::generarDeportes(vector<string> listaDeportes){
    int indice = int(QRandomGenerator::global()->bounded(0, 7));
    if(indice == 0){
        ListaDeportes().insertarAlFinal(indice,"No practica ningún deporte en la semana");
    }//if
    else{
        for (int i=0; i<=indice;i++){
            int deportePractica = int(QRandomGenerator::global()->bounded(0, 163));
            int vecesSemana = int(QRandomGenerator::global()->bounded(1,7));
            string deporte=listaDeportes.at(deportePractica);
            ListaDeportes().insertarAlFinal(vecesSemana,deporte);
            return deporte;

        }//for
    }//else
    return 0;
}//generarDeportes

