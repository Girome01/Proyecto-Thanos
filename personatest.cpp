#include "personatest.h"

PersonaTest::PersonaTest(ListaDoble *mundo)
{
    personas=mundo;

}
vector<string> PersonaTest::generarlistaNombres(string texto){
    std::vector<string> listaNombres;
    std::string delimiter = "-";

    size_t last = 0;
    size_t next = 0;
    while ((next = texto.find(delimiter, last)) != string::npos) {
        //cout << texto.toStdString().substr(last, next-last) << endl;
        listaNombres.push_back(texto.substr(last, next-last));
        last = next + 1;
    }
    return listaNombres;
}

void PersonaTest::crearPersona(int cantidad){

        //LISTA NOMBRES FEMENINOS
        string texto0=archivito.leer("C:\\Users\\Gilberth\\Desktop\\TEC\\2 Semestre\\Estructura de datos\\Tareas\\Proyecto Thanos\\Proyecto\\ProyectoThanos\\NombreMujeres.txt");
        std::vector<string> listaNombresF;
        listaNombresF=generarlistaNombres(texto0);

        //LISTA NOMBRES MASCULINOS
        string texto1=archivito.leer("C:\\Users\\Gilberth\\Desktop\\TEC\\2 Semestre\\Estructura de datos\\Tareas\\Proyecto Thanos\\Proyecto\\ProyectoThanos\\NombreHombres.txt");
        std::vector<string> listaNombresM;
        listaNombresM=generarlistaNombres(texto1);

        //LISTA APELLIDOS
        string texto2=archivito.leer("C:\\Users\\Gilberth\\Desktop\\TEC\\2 Semestre\\Estructura de datos\\Tareas\\Proyecto Thanos\\Proyecto\\ProyectoThanos\\Apellidos.txt");
        std::vector<string> listaApellidos;
        listaApellidos=generarlistaNombres(texto2);

        //LISTA PAISES
        string texto3=archivito.leer("C:\\Users\\Gilberth\\Desktop\\TEC\\2 Semestre\\Estructura de datos\\Tareas\\Proyecto Thanos\\Proyecto\\ProyectoThanos\\Paises.txt");
        std::vector<string> listaPaises;
        listaPaises=generarlistaNombres(texto3);
        cout<<listaPaises.size()<<endl;

        //LISTA PROFESIONES
        string texto4=archivito.leer("C:\\Users\\Gilberth\\Desktop\\TEC\\2 Semestre\\Estructura de datos\\Tareas\\Proyecto Thanos\\Proyecto\\ProyectoThanos\\Profesiones.txt");
        std::vector<string> listaProfesiones;
        listaProfesiones=generarlistaNombres(texto4);

        //LISTA CREENCIAS
        string texto5=archivito.leer("C:\\Users\\Gilberth\\Desktop\\TEC\\2 Semestre\\Estructura de datos\\Tareas\\Proyecto Thanos\\Proyecto\\ProyectoThanos\\Creencias.txt");
        std::vector<string> listaCreencias;
        listaCreencias=generarlistaNombres(texto5);

        //LISTA DEPORTES
        string texto6=archivito.leer("C:\\Users\\Gilberth\\Desktop\\TEC\\2 Semestre\\Estructura de datos\\Tareas\\Proyecto Thanos\\Proyecto\\ProyectoThanos\\Deportes.txt");
        std::vector<string> listaDeportes;
        listaDeportes=generarlistaNombres(texto6);
        cout<<listaDeportes.size()<<endl;

        for(int i=0;i<cantidad;i++){
            Persona *personita=new Persona();
            //GENERO
            personita->genero=personita->random->aleatorioGenero();

            if(personita->genero){
                //NOMBRES FEMENINOS
                personita->nombre=personita->random->generarNombresF(listaNombresF);
           }else{
                //NOMBRES MASCULINOS
                personita->nombre=personita->random->generarNombresM(listaNombresM);
            }
                //APELLIDO
                personita->apellido=personita->random->generarApellidos(listaApellidos);

                //CONTINENTE
                personita->continenteVive=personita->random->generarContinente();
                //PAIS DONDE VIVE
                personita->paisVive=personita->random->generarPais(listaPaises);

                //PECADOS
                personita->pecados->insertarAlFinal(0,"Lujuria"); //1
                personita->pecados->insertarAlInicio(0,"Envidia"); //2
                personita->pecados->insertarAlInicio(0,"Gula"); //3
                personita->pecados->insertarAlInicio(0,"Ira"); //4
                personita->pecados->insertarAlInicio(0,"Orgullo"); //5
                personita->pecados->insertarAlInicio(0,"Pereza"); //6
                personita->pecados->insertarAlInicio(0,"Codicia"); //7
                personita->random->generarPecados(personita->pecados);

                //VIRTUDES
                personita->virtudes->insertarAlFinal(0,"Castidad"); //1
                personita->virtudes->insertarAlInicio(0,"Ayuno"); //2
                personita->virtudes->insertarAlInicio(0,"Donacion"); //3
                personita->virtudes->insertarAlInicio(0,"Diligencia"); //4
                personita->virtudes->insertarAlInicio(0,"Calma"); //5
                personita->virtudes->insertarAlInicio(0,"Solidaridad"); //6
                personita->virtudes->insertarAlInicio(0,"Humildad"); //7
                personita->random->generarPecados(personita->virtudes);

                //DIA DE NACIMIENTO
                personita->nacDia=std::to_string(personita->random->aletorioDia());
                //MES DE NACIMIENTO
                personita->nacMes=personita->random->aleatorioMes();
                //ANNO DE NACIMIENTO
                int anno=personita->random->aletorioAno();
                //RANGO ETARIO
                personita->rangoEtario=personita->random->generarRangoEtario(anno);
                //ANNO DE NACIMIENTO
                personita->nacAno=std::to_string(anno);
                //ESTADO MARITAL
                personita->estadoMarital=personita->random->estadoMarital();

                //CREENCIA
                personita->creencia=personita->random->generarCreencia(listaCreencias);
                //PROFESION
                personita->profesion=personita->random->generarProfesion(listaProfesiones);
                //PAISES VISITADOS
                personita->random->generarPaisesVisitados(listaPaises, personita->paises);
                //DEPORTES
                personita->random->generarDeportes(listaDeportes, personita->deportes);
                //PAREJA
                personita->random->asignarPareja(personas);

                //ID
                personita->ID = personita->random->generarId(personas);

                //INSERTA PERSONA A LA LISTA
                personas->insertionSort(personita);

        }
        cout<<"..."<<endl;

        NodoPersona *tmp=personas->primerNodo;
        while(tmp!=NULL){
            tmp->persona->random->agregarHijos(personas,tmp->persona);
            tmp->persona->random->agregarAmigos(personas,tmp->persona);
            tmp=tmp->siguiente;
            cout<<"*"<<endl;
       }
        //tmp=personas->primerNodo;

        /*//Para recorrer la lista y ver los resultados
        while(tmp!=NULL){
            cout<<tmp->persona->nombre<<" "<<tmp->persona->apellido<<" "<<tmp->persona->ID<<" "<<tmp->persona->continenteVive<<" "<<tmp->persona->nacDia<<"/"<<tmp->persona->nacMes<<"/"<<tmp->persona->nacAno<<" "<<tmp->persona->rangoEtario<<endl<<tmp->persona->paisVive<<endl<<tmp->persona->estadoMarital<<endl<<tmp->persona->pecados->imprimir()<<"CANTIDAD HIJOS:"<<to_string(tmp->persona->hijos->largo())+" *****"<<endl;
            if(!tmp->persona->amigos->isEmpty()){
                cout<<tmp->persona->amigos->imprimir()<<endl;
            }
            tmp=tmp->siguiente;
       }*/


}


