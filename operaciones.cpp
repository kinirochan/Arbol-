#include "operaciones.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string pedir_palabra(string campo);
string pedir_codigo();
double pedir_numero(string campo);

void consultar_aeropuerto(BST* arbol) {

	system("clear");

	string codigo = pedir_codigo();
	Node* buscado = arbol->search(codigo);

	if (!buscado) {

		cout << "No se encontro el aeropuerto" << endl;
		return;

	}

	cout << "Nombre: " << buscado->datos_aeropuerto->obtener_nombre_aeropuerto() << endl;
	cout << "Ciudad: " << buscado->datos_aeropuerto->obtener_nombre_ciudad() << endl;
	cout << "Pais: " << buscado->datos_aeropuerto->obtener_pais() << endl;
	cout << "Superficie: " << buscado->datos_aeropuerto->obtener_superficie() << endl;
	cout << "Terminales: " << buscado->datos_aeropuerto->obtener_cantidad_terminales() << endl;
	cout << "Destinos nacionales: " << buscado->datos_aeropuerto->obtener_destinos_nacionales() << endl;
	cout << "Destinos internacionales: " << buscado->datos_aeropuerto->obtener_destinos_internacionales() << endl;

}

void agregar_aeropuerto(BST* arbol) {

	system("clear");

	Aeropuerto* aeropuerto = new Aeropuerto();
	string codigo = pedir_codigo();

	aeropuerto->asignar_nombre_aeropuerto(pedir_palabra("Nombre aeropuerto"));
	aeropuerto->asignar_nombre_ciudad(pedir_palabra("Nombre ciudad"));
	aeropuerto->asignar_pais(pedir_palabra("Pais"));
	aeropuerto->asignar_superficie(pedir_numero("Superficie"));
	aeropuerto->asignar_terminales((int)pedir_numero("Terminales"));
	aeropuerto->asignar_destinos((int)pedir_numero("Destinos nacionales"), (int)pedir_numero("Destinos internacionales"));

	arbol->add(codigo, aeropuerto);

}

void eliminar_aeropuerto(BST* arbol) {

	system("clear");

	string codigo = pedir_codigo();

	if (arbol->deleteValue(codigo)) {
		cout << "Listo" << endl;
	} else {
		cout << "Error al borrar" << endl;
	}

}

void listar_aeropuertos(BST* arbol) {

	system("clear");

	cout << "Listado de aeropuertos:" << endl;
	arbol->print();

}

string pedir_palabra(string campo) {

	string palabra;
	cout << campo << ": ";

	cin.clear(); // Borro el buffer
	getline(cin, palabra);

	return (string)palabra;

}

double pedir_numero(string campo) {

	double numero;
	cout << campo << ": ";
	cin >> numero;

	if (!cin.good()) { // Comprobar que sea un numero

		cin.clear();
		cin.ignore();
		cout << "Por favor ingrese un numero" << endl;
		return pedir_numero(campo);

	}

	return numero;
}

string pedir_codigo() {

	string codigo;
	cout << "Codigo IATA: ";
	cin.ignore();
	getline(cin, codigo);

	if (codigo.length() != 3) {

		cout << "El codigo debe tener 3 cifras" << endl;
		return pedir_codigo();

	}

	return codigo;

}
