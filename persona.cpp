#include "persona.h"

Persona::Persona(){

}

void Persona::imprimir(){
    //Faltan los datos que son int
    // Ocupo pasarlos a ints y no se
    string texto = "";
    texto +="Nombre: "+nombre+"\tApellido: "+apeelido+"\nID: ";
    cout<<texto<<ID<<"\tGenero: "<<genero<<"\nCreencia: "<<creencia<<
          "\tProfesion: "<<profesion<<"\nFecha de nacimiento: "<<nacDia<<
          "-"<<nacMes<<"-"<<nacAno;
}
