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

void Archivo::enviarCorreo(string archivoTxt){
    string nombreArchivo="pls.txt";
    string exe="D:\\Documents\\ProyectoThanos\\ProyectoThanos\\EnviarCorreosQT1.exe";
    string q=" D:/Documents/ProyectoThanos/ProyectoThanos/";
    q.append(archivoTxt);
    exe.append(q);
    exe.append(" 0 1 ");
    system("D:\\Documents\\ProyectoThanos\\ProyectoThanos\\EnviarCorreosQT1.exe D:/Documents/ProyectoThanos/ProyectoThanos/pls.txt 0 1 ");
    system(exe.c_str());
}
