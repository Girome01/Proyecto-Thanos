#include "arbol.h"
#include <math.h>

Arbol::Arbol(){
    raiz = NULL;
}

int Arbol::obtenerPor(int largoLista){
    int unoPorciento = largoLista * 0.01; // Obtiene el porcentaje de las personas 01%
    int total = 0; // Para calcular que el arbol este lleno al 100%
    int i = 0; //Indice para elevar
    while ( total < unoPorciento) {
        total = pow(2,i)-1; // 2^profundidad - 1 (profundidad = i)
        i++;
    }
    return total; // retorna el total de personas para obtener un arbol completo
}

void Arbol::crearArray(int _posicion, int largoLista){
    int lugar = largoLista / _posicion; // obtiene la cantidad de posiciones que recorre para obtener el lugar
    //cout<<"Lugar   "<<lugar<<endl;
    for(int i = 0; i < _posicion; i++){
        if(lugar*1 > largoLista){ // Si se pasa del largo de la lista se coloca el ultimo lugar
            this->posiciones.append(largoLista); // se agrega la posicion
            //cout<<"Posiciones   "<<i<<" = "<<largoLista<<endl;
        }else{
            this->posiciones.append(lugar*i); // se agrega la posicion dnode deberia estar
            //cout<<"Posiciones   "<<i<<" = "<<lugar*i<<endl;
        }
    }
}

void Arbol::imprimirArray(){
    cout<<"Imprimir QList "<<endl;
    for(int i = 0; i < posiciones.length();i++){
        cout<<posiciones.at(i)<<" -> "<<endl;
    }
}

QList<int> Arbol::listaMenores(QList<int> _posiciones, int pos){
    QList<int> menores = {};
    for(int i = 0; i < pos; i++){
        menores.append(_posiciones.at(i)); // Retorna los menores
    }
    return menores;
}

QList<int> Arbol::listaMayores(QList<int> _posiciones, int pos){
    QList<int> mayores = {};
    for(int i = pos+1; i < _posiciones.size(); i++){
        mayores.append(_posiciones.at(i)); // retorna los mayores
    }
    return mayores;
}

NodoArbol *Arbol::agregarNodo(NodoArbol *nodo, NodoPersona *personaAgregar){
    if(nodo==NULL){
        return new NodoArbol(personaAgregar);
    }else if(nodo->persona->persona->ID > personaAgregar->persona->ID){
        nodo->hijoizquierdo = agregarNodo(nodo->hijoizquierdo, personaAgregar);
    }else{
        nodo->hijoderecho = agregarNodo(nodo->hijoderecho, personaAgregar);
    }
    return nodo;
}

void Arbol::insertarNodo(NodoListaArbol *NodoPersona){
    raiz = agregarNodo(raiz,NodoPersona->persona);
}

void Arbol::llenarArbol(ListaArbol *lista){
    insertarNodo(lista->centroLista());
    if(lista->largoLista() > 1){
        //cout<<"PEIMER MITAD"<<endl;
        lista->primerMitad()->imprimir();
        llenarArbol(lista->primerMitad());
        //cout<<"SEGUNDA MITAD"<<endl;
        lista->segundaMitad()->imprimir();
        llenarArbol(lista->segundaMitad());
    }
}

void Arbol::crearArbol(int largoLista, ListaDoble *listaHumanidad){
    int cantidadNodos=obtenerPor(largoLista);
    //cout<<"CANTIDADNODOS"<<cantidadNodos<<endl;
    double secuencia=ceil((largoLista*1.0)/(cantidadNodos*1.0));
    //cout<<"secuencias"<<secuencia<<endl;
    ListaArbol *listaNodos = listaHumanidad->nodosArbol(secuencia,cantidadNodos);
    listaNodos->imprimir();

    llenarArbol(listaNodos);
}

void Arbol::inOrden(NodoArbol* nodo){
    //Un in orden normal
   if (nodo != NULL){
     inOrden(nodo->hijoizquierdo);
     cout << nodo->persona->persona->imprimir()<< " -> ";
     inOrden(nodo->hijoderecho);
   }
}

void Arbol::print2DUtil(NodoArbol* root, int space){
    // Base case
    if (root == NULL){
        return;
    }

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    //cout<<"Procesa un hijo derecho"<<endl;
    print2DUtil(root->hijoderecho, space);

    // Print current node after space
    // count
    arbolS += "\n";
    cout<<endl;
    for (int i = COUNT; i < space; i++){
        arbolS += " ";
        cout<<" ";
    }
    stringstream buff;
    buff << root->persona->persona->ID;
    string id = buff.str();
    arbolS += id+"\n";
    cout<<root->persona->persona->ID<<"\n";

    // Process left child
    print2DUtil(root->hijoizquierdo, space);
}

// Wrapper over print2DUtil()
void Arbol::print2D(NodoArbol* root){
    // Pass initial space count as 0
    cout<<"Entra al print2D"<<endl;
    print2DUtil(root, 0);
}

int Arbol::profundidad(NodoArbol *raiz){
    if (raiz == NULL)
           return 0;
   else {
       int alturaIzq = profundidad(raiz->hijoizquierdo);
       int alturaDer = profundidad(raiz->hijoizquierdo);
       if (alturaIzq >= alturaDer)
            return alturaIzq + 1;
       else
            return alturaDer + 1;
   }

}

void Arbol::encontrarNiveles(NodoArbol *nodoA, int clevel,int nivelEscogido){
    if (clevel == nivelEscogido) {
      tempNumNivel++;
      nodoA->marcaNodo=tempNumNivel;
    }else {
      if (nodoA->hijoizquierdo != NULL)
        encontrarNiveles(nodoA->hijoizquierdo, clevel + 1, nivelEscogido);
      }if (nodoA->hijoderecho != NULL)
        encontrarNiveles(nodoA->hijoderecho, clevel + 1, nivelEscogido);
 }

void Arbol::marcarNiveles(){
    for(int i=0;i<profundidad(raiz);i++){
        encontrarNiveles(raiz, 0, i);
    }
}
