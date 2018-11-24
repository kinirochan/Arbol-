#include <iostream>
#include <fstream>
#include "Aeropuerto.h"
#include "Arbol_binario.h"
#include<string>

using namespace std;

void cargar_arbol(Arbol_binario* arbol);
void pasar_datos(string linea_leida/*,Arbol_binario* arbol*/);
double obtener_dato (string linea_leida, int *posicion_inicio, char final_lectura);
string obtener_palabra (string linea_leida, int *posicion_inicio, char final_lectura);

int main(){
    Arbol_binario arbol;
    cargar_arbol(&arbol);

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
void pasar_datos(string linea_leida /*,Arbol_binario* arbol*/){

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

    //  arbol->agregar(codigo, &datos_aeropuerto);

}
void cargar_arbol(Arbol_binario* arbol){

  		ifstream archivo;
  		string linea_leida;
  		archivo.open ("aeropuerto.txt");

  		while(!archivo.eof ()){
  				getline (archivo, linea_leida);
          pasar_datos (linea_leida /*,arbol*/);
  		}
  		archivo.close ();
}
