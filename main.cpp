#include <iostream>
#include <fstream>
#include "Aeropuerto.h"
#include "Arbol_binario.h"
#include<string>

using namespace std;
const char ESPACIO_EN_BLANCO = ' ';
const char FIN_STRING = '\0';

void cargar_arbol(Arbol_binario* arbol);
void pasar_datos(string linea_leida,Arbol_binario* arbol);
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
void pasar_datos(string linea_leida ,Arbol_binario* arbol){

      int posicion_inicio = 0;
      Aeropuerto datos_aeropuerto;
      string codigo = obtener_palabra(linea_leida, posicion_inicio,ESPACIO_EN_BLANCO);
      string nombre_aeropuerto = obtener_palabra(linea_leida, posicion_inicio, ESPACIO_EN_BLANCO);
      string nombre_ciudad = obtener_palabra(linea_leida, posicion_inicio, ESPACIO_EN_BLANCO);
      string pais = obtener_palabra(linea_leida, posicion_inicio,ESPACIO_EN_BLANCO);
      double superficie = obtener_dato(linea_leida, posicion_inicio,ESPACIO_EN_BLANCO);
      int cantidad_terminales = obtener_dato(linea_leida, posicion_inicio,ESPACIO_EN_BLANCO );
      int destinos_nacionales = obtener_dato(linea_leida, posicion_inicio,ESPACIO_EN_BLANCO);
      int destinos_internacionales = obtener_dato(linea_leida, posicion_inicio, FIN_STRING);
      
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
  		archivo.open ("aeropuerto.txt");

      getline (archivo, linea_leida);
  		while(!(archivo.eof())){
          pasar_datos (linea_leida,arbol);
  				getline (archivo, linea_leida);

  		}
  		archivo.close ();
}
