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

		//pre: Resibe un double con el valor de la superficie
		//pos: Le asigna el valor al aeropuerto
		void asignar_superficie(double superficie);
		
		//pre:	Resibe un int con la cantidad de terminales
		//pos:	Le asigna el numero de terminales al aeropuerto
		void asignar_terminales(int cantidad_terminales);
		void asignar_destinos(int destinos_nacionales,int destinos_internacionales);
		string obtener_nombre_aeropuerto();
		string obtener_nombre_ciudad();
		string obtener_pais();
		double obtener_superficie();
		int obtener_cantidad_terminales();
		int obtener_destinos_nacionales();
		int obtener_destinos_internacionales();
		// ~Aeropuerto();

};

#endif
