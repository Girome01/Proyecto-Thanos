#include "archivo.h"

Archivo::Archivo(){

}

void Archivo::escribir(string _texto, string _archivo){
    ofstream archivo;

    archivo.open(_archivo.c_str(),ios::out);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
    }else{
        archivo<<_texto<<endl;
        cout<<"Se guardo el archivo"<<endl;
    }
    archivo.close();
}

string Archivo::leer(string _archivo){
    ifstream archivo;
    string texto="",linea="";

    archivo.open(_archivo.c_str(),ios::in);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        texto="";
    }else{
        while(!archivo.eof()){
            getline(archivo,linea);
            texto+=linea;
        }
        cout<<"Se leyo el archivo"<<endl;
    }
    archivo.close();
    return texto;
}
