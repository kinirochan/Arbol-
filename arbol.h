#ifndef ARBOL_H
#define ARBOL_H

#include <math.h>
#include <string>
#include "aeropuerto.h"

/*La clase Arbol es una implementacion arbol binario tomada de https://gist.github.com/mgechev/5911348*/

using namespace std;

struct Node {
	string value;
	Node* left;
	Node* right;
	Aeropuerto* datos_aeropuerto;

	Node(string val, Aeropuerto* aeropuerto) {
		this->value = val;
		this->datos_aeropuerto = aeropuerto;
	}

	Node(string val, Aeropuerto* aeropuerto, Node* left, Node* right) {
		this->value = val;
		this->datos_aeropuerto = aeropuerto;
		this->left = left;
		this->right = right;
	}
};

class BST {
	private:
		Node* root;
		void addHelper(Node* root, string val, Aeropuerto* aeropuerto);
		void printHelper(Node* root);
		int nodesCountHelper(Node* root);
		int heightHelper(Node* root);
		void printMaxPathHelper(Node* root);
		bool deleteValueHelper(Node* parent, Node* current, string value);
		Node* searchHelper(Node* root, string key);

	public:
		BST();
		void add(string val, Aeropuerto* aeropuerto);
		void print();
		int nodesCount();
		int height();
		void printMaxPath();
		bool deleteValue(string value);
		Node* search(string key);
		~BST();
};

#endif
