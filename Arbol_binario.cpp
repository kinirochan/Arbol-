#include "Arbol_binario.h"

Nodo* Arbol_binario::borrar (Nodo* nodo) {
  if (nodo != NULL){
    borrar (nodo -> obtener_hijo(HIJO_DERECHO));
    borrar (nodo -> obtener_hijo(HIJO_IZQUIERDO));
    delete nodo;
  }
  return NULL;
}

Nodo* Arbol_binario::agregar (string codigo_IAT, Aeropuerto* datos_aeropuerto, Nodo* nodo_actual) {

  if (nodo_actual == NULL) {
    nodo_actual = new Nodo (codigo_IAT, datos_aeropuerto);
  } else if ( codigo_IAT.compare( nodo_actual -> obtener_codigo_IAT() ) < 0 ) {
    nodo_actual -> obtener_hijo(HIJO_DERECHO) = agregar (codigo_IAT, datos_aeropuerto, nodo_actual -> obtener_hijo (HIJO_DERECHO) );
  } else if ( codigo_IAT.compare( nodo_actual -> obtener_codigo_IAT() ) > 0 ) {
    nodo_actual -> obtener_hijo(HIJO_IZQUIERDO) = agregar (codigo_IAT, datos_aeropuerto, nodo_actual -> obtener_hijo (HIJO_IZQUIERDO) );
  }

  return nodo_actual;
}

Arbol_binario::Arbol_binario () {
  this -> raiz = NULL;
}

Arbol_binario::~Arbol_binario (){
  this -> raiz = borrar (raiz);
}

void Arbol_binario::agregar (string codigo_IAT, Aeropuerto* datos_aeropuerto){
  raiz = agregar (codigo_IAT, datos_aeropuerto, raiz);
}
