#include <iostream>
#include <fstream>
#include "Aeropuerto.h"
#include "Arbol_binario.h"
#include "operaciones.h"
#include <string>
#include <stdlib.h>

using namespace std;

const int MINIMO_NUMERO_MENU = 1;
const int MAXIMO_NUMERO_MENU = 5;

void cargar_arbol(Arbol_binario* arbol);
void pasar_datos(string linea_leida,Arbol_binario* arbol);
double obtener_dato (string linea_leida, int *posicion_inicio, char final_lectura);
string obtener_palabra (string linea_leida, int *posicion_inicio, char final_lectura);
void mostrar_menu();
int pedir_opcion ();

int main(){
      Arbol_binario arbol;
      bool sigue_programa = true;
      cargar_arbol(&arbol);
      while(sigue_programa){
      mostrar_menu();
      int opcion_pedida = pedir_opcion ();

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
              listar_aeropuertos();
              break;
          case 5:
              sigue_programa = false;
              break;
          default:
              sigue_programa = false;
      }
    }




    return EXIT_SUCCESS;
}

string obtener_palabra (string linea_leida, int &posicion_inicio, char final_lectura){
  int  contador = 0;
  char dato_leido[50];

  while(linea_leida[posicion_inicio] != final_lectura){
    dato_leido[contador] = linea_leida[posicion_inicio];
    contador++;
    posicion_inicio++;
  }
  dato_leido[contador]= '\0';
  posicion_inicio++;
  return (string)dato_leido;

}

double obtener_dato (string linea_leida, int &posicion_inicio, char final_lectura){

	  int  contador = 0;
		string dato_leido;
		double medida_leida;
	  while(linea_leida[posicion_inicio] != final_lectura){
			dato_leido[contador] = linea_leida[posicion_inicio];
	    contador++;
	    posicion_inicio++;
		}
    posicion_inicio++;
		medida_leida = atof(dato_leido.c_str());
	  return medida_leida;
}
void pasar_datos(string linea_leida ,Arbol_binario* arbol){

      int posicion_inicio = 0;
      Aeropuerto datos_aeropuerto;
      string codigo = obtener_palabra(linea_leida, posicion_inicio, ' ');
      string nombre_aeropuerto = obtener_palabra(linea_leida, posicion_inicio, ' ');
      string nombre_ciudad = obtener_palabra(linea_leida, posicion_inicio, ' ');
      string pais = obtener_palabra(linea_leida, posicion_inicio, ' ');
      double superficie = obtener_dato(linea_leida, posicion_inicio, ' ');
      int cantidad_terminales = obtener_dato(linea_leida, posicion_inicio, ' ');
      int destinos_nacionales = obtener_dato(linea_leida, posicion_inicio, ' ');
      int destinos_internacionales = obtener_dato(linea_leida, posicion_inicio, '\0');

      datos_aeropuerto.asignar_nombre_aeropuerto(nombre_aeropuerto);
      datos_aeropuerto.asignar_nombre_ciudad(nombre_ciudad);
      datos_aeropuerto.asignar_pais(pais);
      datos_aeropuerto.asignar_superficie(superficie);
      datos_aeropuerto.asignar_terminales(cantidad_terminales);
      datos_aeropuerto.asignar_destinos(destinos_nacionales, destinos_internacionales);

      arbol->agregar(codigo, &datos_aeropuerto);

}
void cargar_arbol(Arbol_binario* arbol){
  		ifstream archivo;
  		string linea_leida;
  		archivo.open ("aeropuertos.txt");

      getline (archivo, linea_leida);
  		while(!(archivo.eof())){
          pasar_datos (linea_leida,arbol);
  				getline (archivo, linea_leida);

  		}
  		archivo.close ();
}

void mostrar_menu (){
      system("clear");
      cout << "           Menu de aeropuertos 🛫       "<< endl << endl;
      cout << "  ①  Consultar aeropuerto con codigo IATA" << endl;
      cout << "  ②  Agregar un aeropuerto" << endl;
      cout << "  ③  Eliminar un aeropuerto con codigo IATA" << endl;
      cout << "  ④  Listar aeropuertos"<< endl;
      cout << "  ⑤  Salir" << endl;
}

int pedir_opcion () {

		int opcion_pedida;
		cout << " Opcion: ";
		cin >> opcion_pedida;

		if (!cin.good ()) { // Comprobar que sea un numero
				cin.clear ();
				cin.ignore ();
				cout << " Por favor ingrese un numero" << endl;
				return pedir_opcion();
		}

		if (opcion_pedida < MINIMO_NUMERO_MENU || opcion_pedida > MAXIMO_NUMERO_MENU) {
				cout << " Por favor ingrese un numero entre 1 y 5" << endl;
				return pedir_opcion();
		}

		return opcion_pedida;

}
