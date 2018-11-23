#include "Nodo.h"

Nodo::Nodo (string codigo_IAT, Tipo* datos_aeropuerto){
 this -> codigo_IAT = codigo_IAT;
 this -> datos_aeropuerto = datos_aeropuerto;
 this -> hijo_izquierdo = NULL;
 this -> hijo_derecho = NULL;
}
