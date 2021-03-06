#include "arbol.h"
#include <iostream>

using namespace std;

BST::BST() {
	root = 0;
}

void BST::addHelper(Node *root, string val, Aeropuerto* aeropuerto) {
	if ((root->value).compare(val) > 0) {
		if (!root->left) {
			root->left = new Node(val, aeropuerto);
		} else {
			addHelper(root->left, val, aeropuerto);
		}
	} else {
		if (!root->right) {
			root->right = new Node(val, aeropuerto);
		} else {
			addHelper(root->right, val, aeropuerto);
		}
	}
}

void BST::printHelper(Node *root) {

	if (!root) return;
	printHelper(root->left);

	cout << " - " << root->value << endl;
	cout << "      Nombre: " << root->datos_aeropuerto->obtener_nombre_aeropuerto() << endl;
	cout << "      Ciudad: " << root->datos_aeropuerto->obtener_nombre_ciudad() << endl;
	cout << "      Pais: " << root->datos_aeropuerto->obtener_pais() << endl;
	cout << "      Superficie: " << root->datos_aeropuerto->obtener_superficie() << endl;
	cout << "      Terminales: " << root->datos_aeropuerto->obtener_cantidad_terminales() << endl;
	cout << "      Destinos nacionales: " << root->datos_aeropuerto->obtener_destinos_nacionales() << endl;
	cout << "      Destinos internacionales: " << root->datos_aeropuerto->obtener_destinos_internacionales() << endl << endl;

	printHelper(root->right);

}

int BST::nodesCountHelper(Node *root) {

	if (!root) return 0;
	else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);

}

int BST::heightHelper(Node *root) {

	if (!root) return 0;
	else return 1 + max(heightHelper(root->left), heightHelper(root->right));

}

void BST::printMaxPathHelper(Node *root) {

	if (!root) return;

	if (heightHelper(root->left) > heightHelper(root->right)) {
		printMaxPathHelper(root->left);
	} else {
		printMaxPathHelper(root->right);
	}

}

bool BST::deleteValueHelper(Node *parent, Node *current, string value) {

	if (!current) return false;

	if (current->value == value) {

		if (current->left == NULL || current->right == NULL) {
			Node *temp = current->left;

			if (current->right) temp = current->right;

			if (parent) {

				if (parent->left == current) {
					parent->left = temp;
				} else {
					parent->right = temp;
				}

			} else {
				this->root = temp;
			}

		} else {
			Node *validSubs = current->right;

			while (validSubs->left) {
				validSubs = validSubs->left;
			}

			string temp = current->value;
			current->value = validSubs->value;
			validSubs->value = temp;
			return deleteValueHelper(current, current->right, temp);

		}

		delete current->datos_aeropuerto;
		delete current;
		return true;

	}

	return deleteValueHelper(current, current->left, value) ||
		   deleteValueHelper(current, current->right, value);

}

void BST::add(string val, Aeropuerto* aeropuerto) {

	if (root) {
		this->addHelper(root, val, aeropuerto);
	} else {
		root = new Node(val, aeropuerto);
	}

}

void BST::print() {

	printHelper(this->root);

}

int BST::nodesCount() {

	return nodesCountHelper(root);

}

int BST::height() {

	return heightHelper(this->root);

}

void BST::printMaxPath() {

	printMaxPathHelper(this->root);

}

bool BST::deleteValue(string value) {

	return this->deleteValueHelper(NULL, this->root, value);

}

Node* BST::searchHelper(Node* root, string key) {

	// Base Cases: root is null or key is present at root
	if (root == NULL || root->value == key)
		return root;

	// Key is greater than root's key
	if (root->value.compare(key) < 0)
		return searchHelper(root->right, key);

	// Key is smaller than root's key
	return searchHelper(root->left, key);

}

Node* BST::search(string key) {

	return searchHelper(this->root, key);

}

BST::~BST() {

	while (nodesCount() > 0) {
		deleteValue(root->value);
	}

}
