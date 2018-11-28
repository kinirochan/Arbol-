#include "arbol.h"

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
	// cout<<root->value<<' ';
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
	// cout<<root->value<<' ';
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

BST::~BST() {
	// deleteValue(root->value);
}