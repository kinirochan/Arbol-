#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include <iostream>
#include "Nodo.h"
#include "Aeropuerto.h"

using namespace std;

class Arbol_binario {

  private:
    Nodo* raiz;

  private:
    Nodo* borrar (Nodo* nodo);
    Nodo* agregar (string codigo_IAT, Aeropuerto* datos_aeropuerto, Nodo* nodo_actual);

  public:
    Arbol_binario ();
    ~Arbol_binario ();
    void agregar (string codigo_IAT, Aeropuerto* datos_aeropuerto);
};

#endif
