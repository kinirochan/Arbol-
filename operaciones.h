#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "arbol.h"

//Pre: necesita un arbol binario previamente cargado 
//Pos: devuelve los datos del aeropuerto pedido 
void consultar_aeropuerto(BST* arbol);

//Pre: necesita un arbol binario previamente cargado 
//Pos: agrega un aeropuerto al arbol 
void agregar_aeropuerto(BST* arbol);

//Pre: necesita un arbol binario previamente cargado 
//Pos: elimina un aeropuerto ingresado por el usuario 
void eliminar_aeropuerto(BST* arbol);

//Pre: necesita un arbol binario previamente cargado 
//Pos: lista todos los aeropuertos en orden alfabetico
void listar_aeropuertos(BST* arbol);


#endif
