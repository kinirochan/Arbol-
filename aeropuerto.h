#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include <iostream>
#include <string>

using namespace std;

class Aeropuerto {
	private:
		string nombre_aeropuerto;
		string nombre_ciudad;
		string pais;
		double superficie;
		int cantidad_terminales;
		int destinos_nacionales;
		int destinos_internacionales;

	public:
		//pre: -
		//pos: Crea un aeropuerto con todos los valores inicializados en 0 y los string con el valor '\0'
		Aeropuerto();

		//pre: Recibe un string con el nombre del aeropuerto
		//pos: Le asigna el nombre al aeropuerto
		void asignar_nombre_aeropuerto(string nombre_aeropuerto);

		//pre: Recibe un string con el nombre de la ciudad
		//pos: Le asigna el nombre de la ciudad al aeropuerto
		void asignar_nombre_ciudad(string nombre_ciudad);

		//pre:	Recibe un string con el nombre del pais
		//pos:	Le asigna el pais al aeropuerto
		void asignar_pais(string pais);

		//pre: Recibe un double con el valor de la superficie
		//pos: Le asigna el valor al aeropuerto
		void asignar_superficie(double superficie);

		//pre: Recibe un int con la cantidad de terminales
		//pos: Le asigna el numero de terminales al aeropuerto
		void asignar_terminales(int cantidad_terminales);

		//pre: Recibe los destinos nacionales e internacionales a asignar
		//pos: Asigna los destinos internacionales y nacionales
		void asignar_destinos(int destinos_nacionales,int destinos_internacionales);

		//pre: -
		//pos: obtiene el nombre del aeropuerto del aeropuerto
		string obtener_nombre_aeropuerto();

		//pre: -
		//pos: obtiene el nombre de la ciudad del aeropuerto
		string obtener_nombre_ciudad();

		//pre: -
		//pos: obtiene el nombre del pais del aeropuerto
		string obtener_pais();

		//pre: -
		//pos: obtiene la superficie del aeropuerto
		double obtener_superficie();

		//pre: -
		//pos: obtiene la cantidad de terminales del aeropuerto
		int obtener_cantidad_terminales();

		//pre: -
		//pos: obtiene destinos nacionales del aeropuerto
		int obtener_destinos_nacionales();

		//pre: -
		//pos: obtiene los destinos internacionales del aeropuerto
		int obtener_destinos_internacionales();


		// ~Aeropuerto();

};

#endif
