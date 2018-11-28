#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include <iostream>

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
          Aeropuerto();
          void asignar_nombre_aeropuerto(string nombre_aeropuerto);
          void asignar_nombre_ciudad(string nombre_ciudad);
          void asignar_pais(string pais);
          void asignar_superficie(double superficie);
          void asignar_terminales(int cantidad_terminales);
          void asignar_destinos(int destinos_nacionales,int destinos_internacionales);
          ~Aeropuerto();

};

#endif
