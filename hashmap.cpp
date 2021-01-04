#include "hashmap.h"

HashMap::HashMap(ListaDoble *poblacion){
    personas=poblacion;
}
void HashMap::generarHashMap(){
    int filas=(sizeof(hashtable)/sizeof(hashtable[0])); //Cant filas
    int columnas=(sizeof(hashtable[0])/sizeof(hashtable[0][0])); //Cant cols
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            hashtable[0][i]=*(new ListaHashMap()); //Se generan listas simples por cada campo con el fin de que guarden a las personas sin problema si hay colisiones
        }
    }
}

int HashMap::funcionHash(Persona *persona){
    int key=0; //La key inicializa en 0

    if(persona->virtudes->cantidadPecVir()>persona->pecados->cantidadPecVir()){ //1
        key++;
    }else{
        key--;
    }

    if(persona->amigos->largo()>=25){ //2
        key++;
    }else{
        key--;
    }

    if(persona->hijos->largo()>=2){ //3
        key++;
    }else{
        key--;
    }

    if(2021-std::stoi(persona->nacAno)<=34){ //4
        key++;
    }else{
        key--;
    }

    if(persona->estadoMarital=="Casado"){ //5
        key++;
    }else{
        key--;
    }

    if(persona->paisVive=="Costa Rica"){ //6
        key++;
    }else{
        key--;
    }

    if(persona->profesion=="Ingeniero"){ //7
        key++;
    }else{
        key--;
    }

    if(persona->deportes->largo()>=3){ //8
        key++;
    }else{
        key--;
    }

    if(persona->deportes->frecuenciaDeporte()>=5){ //9
        key++;
    }else{
        key--;
    }

    if(persona->continenteVive=="America"){ //10
        key++;
    }else{
        key--;
    }

    if(key<=0){ //Si la persona es muy shitty y da negativo, va a retornar 1
        return 1;
    }else{
        return key;
    }
}


void HashMap::generarAnnos(){
    int anno=1899;
    hashtable[0][0].insertarAlInicio(0); //La posicion 0,0 tendra un cero porque ahi van los nums del 1-10
    for (int i=1; i<121; i++){ //Se llenan las filas en la columna 0 con los annos
        anno++;
        hashtable[i][0].insertarAlInicio(anno);
    }
}

void HashMap::generarNum(){
    int num=0;
    for (int i=1; i<11; i++){ //Se llenan las columnas en la fila 0 con los nums
        num++;
        hashtable[0][i].insertarAlInicio(num);
    }
}

void HashMap::insertarElemento(Persona *persona){
    int key=funcionHash(persona);
    int filas=(sizeof (hashtable)/sizeof (hashtable[0]));
    int columnas=(sizeof(hashtable[0])/sizeof(hashtable[0][0]));
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){ //Se recorre la matriz
            if(hashtable[i][0].primerNodo->key==std::stoi(persona->nacAno) &&
            hashtable[0][j].primerNodo->key==key){ //Si la key del hashtable en el anno coincide con el anno de la persona y ademas coincide la key del num
                hashtable[i][j].insertarAlInicio(persona->ID); //Agregue a la persona en esa pos
            }

        }
    }
}

void HashMap::eliminarPersonasAnno(int key){
    int filas=(sizeof (hashtable)/sizeof (hashtable[0]));
    int columnas=(sizeof(hashtable[0])/sizeof(hashtable[0][0]));
    int filaEsp=0;
    for(int i=0; i<filas; i++){
            if(hashtable[i][0].primerNodo->key==key) //El anno
                filaEsp=i;
    }
   for(int j=0; j<columnas; j++){
            hashtable[filaEsp][j].matarPersonas(personas);
   }
}

void HashMap::eliminarPersonasNivel(int key){
    int filas=(sizeof (hashtable)/sizeof (hashtable[0]));
    int columnas=(sizeof(hashtable[0])/sizeof(hashtable[0][0]));
    int colEsp=0;
    for(int j=0; j<columnas; j++){
            if(hashtable[0][j].primerNodo->key==key) //El nivel
                colEsp=j;
    }
    for(int i=0; i<filas; i++){//Se recorre la matriz
            hashtable[i][colEsp].matarPersonas(personas);
   }
}

void HashMap::eliminarPersonasNivelAnno(int _keyA, int _keyN){
    int filas=(sizeof (hashtable)/sizeof (hashtable[0]));
    int columnas=(sizeof(hashtable[0])/sizeof(hashtable[0][0]));
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){ //Se recorre la matriz
            if(hashtable[i][0].primerNodo->key==_keyA && hashtable[0][j].primerNodo->key==_keyN){
                hashtable[i][j].matarPersonas(personas);
            }
        }
    }
}

void HashMap::imprimirHM(){
    //Pendiente
}
