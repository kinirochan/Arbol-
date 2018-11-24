#ifndef NODO_H
#define NODO_H

#include <iostream>
#include "Aeropuerto.h"

using namespace std;

typedef Aeropuerto Tipo;

const char HIJO_IZQUIERDO = 'I';
const char HIJO_DERECHO = 'D';

const int ERROR = -1;

class Nodo {

		private:

				string codigo_IAT;
				Nodo* hijo_izquierdo;
        Nodo* hijo_derecho;
        Tipo* datos_aeropuerto;

		public:

				//pre: recibe un string codigo_IAT y un puntero a los datos del aeropuerto
				//pos: crea un nodo con los datos
				Nodo (string codigo_IAT, Tipo* datos_aeropuerto);

				//pre: debe haber un nodo creado
				//pos: devuelve un puntero a los datos del aeropuerto
				Tipo* obtener_datos_aeropuerto ();

				string obtener_codigo_IAT ();

				//pre: recive un char I(hijo_izquierdo) o D(hijo_derecho) segun que nodo hijo se quiera buscar
				//pos: devuelve el puntero al nodo hijo pedido;
				Nodo* obtener_hijo (char hijo);

				//pre: tiene que haber un nodo creado
				//pos: hace que el puntero al siguente nodo apuente a siguente
				int asignar_hijo (Nodo* hijo, char pocicion);
};

#endif
