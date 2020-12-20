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

string linea="";
string texto="";
int contador=0;

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

        linea="";
        texto="";
        contador=0;
        string arregloPaises[194];
        //std::vector<int> arr;


        ifstream archivo3("C:/Users/dpere/Desktop/PrograNueva/ProyectoThanos/Paises.txt");//aqui va el path de la carpeta donde estan los archivos
            while (getline(archivo3,linea)){
                texto= texto + linea + "\n";
                arregloPaises[contador]=texto;
                contador++;
                texto="";
                linea="";
            }

            archivo3.close();


            std::uniform_int_distribution<int> randomNum(0,50);
            int randomCantPaises= randomNum(*QRandomGenerator::global());
            cout << "Los paises visitados son: " << randomCantPaises << endl;
            if(0<= randomCantPaises && randomCantPaises <=2){
                for(int i=0; i <= randomCantPaises ; i++) {
                    return arregloPaises[i];
                }
            }

            else if(3<= randomCantPaises && randomCantPaises <=10){
                for(int i=0; i <= randomCantPaises ; i++) {
                    return arregloPaises[i];
                }
            }
            else if(11<= randomCantPaises && randomCantPaises <=15){
                for(int i=0; i <= randomCantPaises ; i++) {
                    return arregloPaises[i];
                }
            }
            else if(16<= randomCantPaises && randomCantPaises <=25){
                for(int i=0; i <= randomCantPaises ; i++) {
                    return arregloPaises[i];
                }
            }
            else{
                for(int i=0; i <= randomCantPaises ; i++) {
                    return arregloPaises[i];
                }
            }

            return 0;

 //--------------------------------Esta parte la hizo Gil-----------------------------

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
        if(tmp->persona->apellido == padre->apellido){
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


//QString meses[]={"xsasa","sdsd"};
int Randomize::aletorioDia(){
    std::uniform_int_distribution<int> distribucion(1,29);
    int dia= distribucion(*QRandomGenerator::global());
    return dia;
}

int Randomize::aleatorioMes(){
    string meses[12]={"enero", "febrero","marzo","abril","mayo","junio","julio","agosto","setiembre","octubre","noviembre","diciembre"};
    std::uniform_int_distribution<int> mes1(0,11);
    int mes= mes1(*QRandomGenerator::global());
    return mes;
}

int Randomize::aletorioAno(){
    std::uniform_int_distribution<int> ano1(1900,2020);
    int ano= ano1(*QRandomGenerator::global());
    edad(ano);
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

int Randomize::edad(int ano){
    //int ano = aletorioAno();
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
        return "Divorsiado";
}
string Randomize::RandomCreencia(){
    linea="";
    texto="";
    contador=0;
    string arregloCreencias[10];

    ifstream archivo("C:/Users/dpere/Desktop/PrograNueva/ProyectoThanos/ArchivoCreencias.txt");//aquí va el path de la carpeta donde está el archivo txt
        while (getline(archivo,linea)){
            texto= texto + linea + "\n";
            arregloCreencias[contador]=texto;
            //cout << "contador: " << contador << endl;
            //cout << "El contenido del arreglo en la pocision " << contador << "es: " << arregloCreencias[contador] << endl;
            contador++;
            texto="";
            linea="";

        }
        archivo.close();
        QString qArchivo = QString::fromStdString(texto);

        std::uniform_int_distribution<int> random(0,9);
        int randomCreencia= random(*QRandomGenerator::global());
        cout << "El numero random es: " << randomCreencia << endl;
        cout << "La creecia aleatoria que se escogio es: " << arregloCreencias[randomCreencia] << endl;

        return arregloCreencias[randomCreencia];
}

string Randomize::RandomProfesion(){
    linea="";
    texto="";
    contador=0;
    string arregloProfesiones[89];

    ifstream archivo2("C:/Users/dpere/Desktop/PrograNueva/ProyectoThanos/Profesiones.txt");//aquí va el path de la carpeta donde está el archivo txt
        while (getline(archivo2,linea)){
            texto= texto + linea + "\n";
            arregloProfesiones[contador]=texto;
            //cout << "contador: " << contador << endl;
            //cout << "El contenido del arreglo en la pocision " << contador << "es: " << arregloProfesiones[contador] << endl;
            contador++;
            texto="";
            linea="";

        }
        archivo2.close();
        QString qArchivo2 = QString::fromStdString(texto);
        //cout << "El contenido del arreglo de profesiones en la pocision 4 es:  "<<arregloProfesiones[4] << endl;
        std::uniform_int_distribution<int> random1(0,88);
        int randomProfesiones= random1(*QRandomGenerator::global());
        cout << "El numero random es: " << randomProfesiones << endl;
        cout << "La profesion aleatoria que se escogio es: " << arregloProfesiones[randomProfesiones] << endl;

        return arregloProfesiones[randomProfesiones];
}
