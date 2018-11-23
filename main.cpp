#include <iostream>
#include <fstream>
#include "Aeropuerto.h"
#include "Nodo.h"

using namespace std;

void cargar_arbol();
void pasar_datos(string linea_leida);
int main(){

  cargar_arbol();
  return 0;
}

void cargar_arbol(){

  		ifstream archivo;
  		string linea_leida;
  		archivo.open ("aeropuerto.txt");

  		while(!archivo.eof ()){
  				getline (archivo, linea_leida);
  				pasar_datos (linea_leida);
  		}

  		archivo.close ();
}
