#include <iostream>
#include <fstream>
#include "aeropuerto.h"
#include "arbol.h"
#include "operaciones.h"
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MINIMO_NUMERO_MENU = 1;
const int MAXIMO_NUMERO_MENU = 5;

//Pre: necesita un arbol binario creado y un archivo aeropuertos.txt previamente cargado y bien formado
//Pos: devuelve el arbol completamente cargado con los datos de un archivo 
void cargar_arbol(BST* arbol);

//Pre: necesita un string que tenga una linea del archivo aeropuertos.txt
//Pos: devuelve el dato le
void pasar_datos(string linea_leida, BST* arbol);

//Pre: necesita la posicion de inicio de lectura y el char donde dejar de leer ambos validos
//Pos: devuelve el dato que se encuentra en la posicion del string pedida 
double obtener_dato(string linea_leida, int &posicion_inicio, char final_lectura);

//Pre: necesita la posicion de inicio de lectura y el char donde dejar de leer ambos validos
//Pos: devuelve la palabra que se encuentra en la posicion del string pedida
string obtener_palabra(string linea_leida, int &posicion_inicio, char final_lectura);

//Pre: -
//Pos: imprime el menu por pantalla
void mostrar_menu();

//Pre: -
//Pos: pide al usuario la opcion del menu que quiere y la devuelve si es valida
int pedir_opcion();

//Pre: -
//Pos: Maneja el flujo de programa 
int main() {
	BST arbol;
	bool sigue_programa = true;
	cargar_arbol(&arbol);

	system("clear");
	while(sigue_programa){

		mostrar_menu();
		int opcion_pedida = pedir_opcion();

		switch (opcion_pedida) {
			case 1:
				consultar_aeropuerto(&arbol);
				break;
			case 2:
				agregar_aeropuerto(&arbol);
				break;
			case 3:
				eliminar_aeropuerto(&arbol);
				break;
			case 4:
				listar_aeropuertos(&arbol);
				break;
			default:
				sigue_programa = false;
		
		}

		system("clear");
	}

	return EXIT_SUCCESS;
}

string obtener_palabra(string linea_leida, int &posicion_inicio, char final_lectura) {
	int  contador = 0;
	char dato_leido[50];

	while(linea_leida[posicion_inicio] != final_lectura) {
	
		dato_leido[contador] = linea_leida[posicion_inicio];
		contador++;
		posicion_inicio++;
	
	}
	
	dato_leido[contador]= '\0';
	posicion_inicio++;
	return (string)dato_leido;

}

double obtener_dato(string linea_leida, int &posicion_inicio, char final_lectura) {

	int contador = 0;
	string dato_leido;
	float medida_leida;

	while(linea_leida[posicion_inicio] != final_lectura){
		
		dato_leido[contador] = linea_leida[posicion_inicio];
		contador++;
		posicion_inicio++;
	
	}
	
	posicion_inicio++;
	medida_leida = atof(dato_leido.c_str());
	return medida_leida;

}

void pasar_datos(string linea_leida, BST* arbol) {
	
	int posicion_inicio = 0;
	Aeropuerto* datos_aeropuerto = new Aeropuerto();
	
	string codigo = obtener_palabra(linea_leida, posicion_inicio, ' ');
	string nombre_aeropuerto = obtener_palabra(linea_leida, posicion_inicio, ' ');
	string nombre_ciudad = obtener_palabra(linea_leida, posicion_inicio, ' ');
	string pais = obtener_palabra(linea_leida, posicion_inicio, ' ');
	double superficie = obtener_dato(linea_leida, posicion_inicio, ' ');
	int cantidad_terminales = obtener_dato(linea_leida, posicion_inicio, ' ');
	int destinos_nacionales = obtener_dato(linea_leida, posicion_inicio, ' ');
	int destinos_internacionales = obtener_dato(linea_leida, posicion_inicio, '\0');

	datos_aeropuerto->asignar_nombre_aeropuerto(nombre_aeropuerto);
	datos_aeropuerto->asignar_nombre_ciudad(nombre_ciudad);
	datos_aeropuerto->asignar_pais(pais);
	datos_aeropuerto->asignar_superficie(superficie);
	datos_aeropuerto->asignar_terminales(cantidad_terminales);
	datos_aeropuerto->asignar_destinos(destinos_nacionales, destinos_internacionales);

	arbol->add(codigo, datos_aeropuerto);

}


void cargar_arbol(BST* arbol) {
	
	ifstream archivo;
	string linea_leida;
	archivo.open("aeropuertos.txt");

	getline(archivo, linea_leida);
	
	while(!(archivo.eof())) {
		
		pasar_datos(linea_leida, arbol);
		getline(archivo, linea_leida);

	
	}
	
	archivo.close();

}

void mostrar_menu() {
	
	cout << "           Menu de aeropuertos 🛫       "<< endl << endl;
	cout << "  ①  Consultar aeropuerto con codigo IATA" << endl;
	cout << "  ②  Agregar un aeropuerto" << endl;
	cout << "  ③  Eliminar un aeropuerto con codigo IATA" << endl;
	cout << "  ④  Listar aeropuertos"<< endl;
	cout << "  ⑤  Salir" << endl << endl;

}

int pedir_opcion() {

	int opcion_pedida;
	cout << " Opcion: ";
	cin >> opcion_pedida;

	if (!cin.good()) { // Comprobar que sea un numero
		
		cin.clear();
		cin.ignore();
		cout << " Por favor ingrese un numero" << endl;
		return pedir_opcion();
	
	}

	if (opcion_pedida < MINIMO_NUMERO_MENU || opcion_pedida > MAXIMO_NUMERO_MENU) {
		
		cout << " Por favor ingrese un numero entre 1 y 5" << endl;
		return pedir_opcion();
	
	}

	return opcion_pedida;

}