#include "persona.h"

Persona::Persona(){
    pecados=new ListaPecVir;
    virtudes=new ListaPecVir;
    hijos=new ListaDoble;
    amigos=new ListaDoble;

}

string Persona::obtenerGenero(){
    if(this->genero)
        return "Femenino";
    return "Masculino";
}

string Persona::obtenerVivo(){
    if(this->vivo)
        return "Vivo";
    return "Muerto";
}

string Persona::imprimirAmigos(){
    string texto = "";
    texto +="Nombre: "+this->nombre+"\tApellido: "+this->apellido+"\nID: "+"\tEstado: "+
            this->obtenerVivo();
    return texto;
}

string Persona::verificarAmigos(){
    if( !this->amigos->isEmpty())
        return this->amigos->imprimirAmigos();
    return "No tiene amigos";
}

string Persona::verificarHijos(){
    if( !this->hijos->isEmpty())
        return this->hijos->imprimirAmigos();
    return "";
}

string Persona::verificarEsposa(){
    if(this->esposa != NULL)
        return this->esposa->imprimirAmigos();
    return "";
}

string Persona::imprimir(){
    stringstream buff;
    buff << this->ID;
    string id = buff.str();
    //Faltan los datos que son int
    // Ocupo pasarlos a ints y no se
    string texto = "";
    texto +="Nombre: "+this->nombre+"\tApellido: "+this->apellido+"\nID: "+id+"\t";
/*         Estado: "+
            this->obtenerVivo()+"\nFecha de nacimiento: "+this->nacDia+"-"+this->nacMes+
            "-"+this->nacAno+"\t"+this->rangoEtario+"\nGenero: "+this->obtenerGenero()+
            "\nContinente donde vive: "+this->continenteVive+"\tPais donde vive: "+this->paisVive+
            "\nEstado marital: "+this->estadoMarital+"\n Esposa: "+this->verificarEsposa()+
            "Hijos: "+this->verificarHijos()+"\nCreencia: "+this->creencia+"\tProfesion: "+
            this->profesion+"\n Pecados: \n"+this->pecados->imprimir()+"\nVistudes: \n"+
            this->virtudes->imprimir()+"\nPaises visitados: \n"+this->paises->imprimir()+
            "Amigos: "+this->verificarAmigos()+"Ejercicio: "+this->deportes->imprimir();
                    */
    return texto;
}
