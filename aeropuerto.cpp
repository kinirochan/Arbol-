#include "aeropuerto.h"

Aeropuerto::Aeropuerto(){

	this->nombre_aeropuerto='\0';
	this->nombre_ciudad='\0';
	this->pais='\0';
	this->superficie=0;
	this->cantidad_terminales=0;
	this->destinos_nacionales=0;
	this->destinos_internacionales=0;

}

void Aeropuerto::asignar_nombre_aeropuerto(string nombre_aeropuerto) {

	this->nombre_aeropuerto = nombre_aeropuerto;

}

void Aeropuerto::asignar_nombre_ciudad(string nombre_ciudad) {

	this->nombre_ciudad = nombre_ciudad;

}

void Aeropuerto::asignar_pais(string pais) {

	this->pais = pais;

}

void Aeropuerto::asignar_superficie(double superficie) {

	this->superficie = superficie;

}

void Aeropuerto::asignar_terminales(int cantidad_terminales) {

	this->cantidad_terminales = cantidad_terminales;

}

void Aeropuerto::asignar_destinos(int destinos_nacionales,int destinos_internacionales) {

	this->destinos_nacionales = destinos_nacionales;
	this->destinos_internacionales = destinos_internacionales;

}

string Aeropuerto::obtener_nombre_aeropuerto() {

	return this->nombre_aeropuerto;

}

string Aeropuerto::obtener_nombre_ciudad() {

	return this->nombre_ciudad;

}

string Aeropuerto::obtener_pais() {

	return this->pais;

}

double Aeropuerto::obtener_superficie() {

	return this->superficie;

}

int Aeropuerto::obtener_cantidad_terminales() {

	return this->cantidad_terminales;

}

int Aeropuerto::obtener_destinos_nacionales() {

	return this->destinos_nacionales;

}

int Aeropuerto::obtener_destinos_internacionales() {

	return this->destinos_internacionales;

}
