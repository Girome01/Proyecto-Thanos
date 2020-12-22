#include "randomize.h"

Randomize::Randomize()
{

}

string Randomize::generarNombresM(vector<string> listaNombresM){
    int indice=int(QRandomGenerator::global()->bounded(0, 6)); //CAMBIAR POR 500 CUANDO YA ESTEN LOS 500
    for (int i=0; i<int(listaNombresM.size());i++){
        if(i==indice){
            string nombre=listaNombresM.at(i); //VECTOR
            return nombre;
        }
    }
    return 0;
}

string Randomize::generarNombresF(vector<string> listaNombresF){
    int indice=int(QRandomGenerator::global()->bounded(0, 6)); //CAMBIAR POR 500 CUANDO YA ESTEN LOS 500
    for (int i=0; i<int(listaNombresF.size());i++){
        if(i==indice){
            string nombre=listaNombresF.at(i); //VECTOR
            return nombre;
        }
    }
    return 0;
}

string Randomize::generarApellidos(vector<string> listaApellidos){
    int indice=int(QRandomGenerator::global()->bounded(0, 6)); //CAMBIAR POR 500 CUANDO YA ESTEN LOS 500
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
    int indice=int(QRandomGenerator::global()->bounded(0, 4)); //CAMBIAR POR 100 CUANDO YA ESTEN LOS 100
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
    std::uniform_int_distribution<int> soltero1(0,100);
    int estadoMarital= soltero1(*QRandomGenerator::global());

    if( 0 <= estadoMarital && estadoMarital <= 10){
        return "Soltero";
    }else if(10 <= estadoMarital && estadoMarital<= 90){
        return "Casado";
    }else
        return "Divorciado";
}
