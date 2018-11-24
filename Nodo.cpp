#include "Nodo.h"

Nodo::Nodo (string codigo_IAT, Tipo* datos_aeropuerto){
 this -> codigo_IAT = codigo_IAT;
 this -> datos_aeropuerto = datos_aeropuerto;
 this -> hijo_izquierdo = NULL;
 this -> hijo_derecho = NULL;
}

Tipo* Nodo::obtener_datos_aeropuerto (){
  return this -> datos_aeropuerto;
}

Nodo* Nodo::obtener_hijo (char hijo){

  if (hijo == HIJO_IZQUIERDO)
    return this -> hijo_izquierdo;
  if (hijo == HIJO_DERECHO)
    return this -> hijo_derecho;

  return NULL;
}


int Nodo::asignar_hijo (Nodo* hijo, char pocicion){

  if (pocicion == HIJO_IZQUIERDO) {
    this -> hijo_izquierdo = hijo;
    return 0;
  } if (pocicion == HIJO_DERECHO) {
    this -> hijo_derecho = hijo;
    return 0;
  }

  return ERROR;
}
