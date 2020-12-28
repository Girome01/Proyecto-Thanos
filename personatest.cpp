#include "personatest.h"

PersonaTest::PersonaTest()
{

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

void PersonaTest::pruebaPersona(){
        ListaDoble *personas=new ListaDoble();
        for(int i=0;i<5;i++){
            Persona *personita=new Persona();
            personita->genero=personita->random->aleatorioGenero();
            cout<<personita->genero<<endl;
            if(personita->genero){
                string texto=archivito.leer("C:\\Users\\monic\\OneDrive - Estudiantes ITCR\\ProyectoThanos\\ProyectoThanos\\NombreMujeres.txt");
                std::vector<string> listaNombres;
                listaNombres=generarlistaNombres(texto);
                personita->nombre=personita->random->generarNombresF(listaNombres);
           }else{
                string texto=archivito.leer("C:\\Users\\monic\\OneDrive - Estudiantes ITCR\\ProyectoThanos\\ProyectoThanos\\NombresHombres.txt");
                std::vector<string> listaNombres;
                listaNombres=generarlistaNombres(texto);
                personita->nombre=personita->random->generarNombresM(listaNombres);
            }
                string texto2=archivito.leer("C:\\Users\\monic\\OneDrive - Estudiantes ITCR\\ProyectoThanos\\ProyectoThanos\\Apellidos.txt");
                std::vector<string> listaApellidos;
                listaApellidos=generarlistaNombres(texto2);
                string texto3=archivito.leer("C:\\Users\\monic\\OneDrive - Estudiantes ITCR\\ProyectoThanos\\ProyectoThanos\\Paises.txt");
                std::vector<string> listaPaises;
                listaPaises=generarlistaNombres(texto3);

                personita->apellido=personita->random->generarApellidos(listaApellidos);
                personita->continenteVive=personita->random->generarContinente();
                personita->paisVive=personita->random->generarPais(listaPaises);

                personita->pecados->insertarAlFinal(0,"Lujuria");
                personita->pecados->insertarAlInicio(0,"Envidia");
                personita->pecados->insertarAlInicio(0,"Gula");
                personita->pecados->insertarAlInicio(0,"Ira");
                //Misma logica a Virtudes.

                personita->random->generarPecados(personita->pecados);

                personita->nacDia=std::to_string(personita->random->aletorioDia());
                personita->nacMes=personita->random->aleatorioMes();
                int anno=personita->random->aletorioAno();
                personita->rangoEtario=personita->random->generarRangoEtario(anno);
                personita->nacAno=std::to_string(anno);

                personita->estadoMarital=personita->random->estadoMarital();

                personas->insertarAlInicio(personita);


                personita->random->generarId(personas);
        }

        NodoPersona *tmp=personas->primerNodo;
        while(tmp!=NULL){
            //tmp->persona->random->agregarHijos(personas,tmp->persona);
            //tmp->persona->random->agregarAmigos(personas,tmp->persona);
            cout<<tmp->persona->nombre<<" "<<tmp->persona->apellido<<" "<<tmp->persona->ID<<" "<<tmp->persona->continenteVive<<" "<<tmp->persona->nacDia<<"/"<<tmp->persona->nacMes<<"/"<<tmp->persona->nacAno<<tmp->persona->rangoEtario<<endl<<tmp->persona->paisVive<<endl<<tmp->persona->estadoMarital<<endl<<tmp->persona->pecados->imprimir()<<endl;
            tmp=tmp->siguiente;
        }


}


