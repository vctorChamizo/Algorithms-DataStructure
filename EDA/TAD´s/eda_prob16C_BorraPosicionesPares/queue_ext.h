// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef queue_duplicate_h
#define queue_duplicate_h

#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_eda.h"

template <class T>
class queue_ext : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void removePair();
	void print(std::ostream & o = std::cout) const;
};

template <class T>
void queue_ext<T>::removePair() {

	Nodo * current_node = this->prim;
	Nodo * delete_node = current_node->sig;

	while (delete_node != nullptr) {

		current_node->sig = delete_node->sig;
		delete delete_node;
		current_node = current_node->sig;
		delete_node = (current_node == nullptr ? nullptr : current_node->sig);

		--this->nelems;
	}
}

template <class T>
void queue_ext<T>::print(std::ostream & o) const {

	Nodo * actual = this->prim;

	while (actual->sig != nullptr) {

		o << actual->elem << ' ';
		actual = actual->sig;
	}

	o << actual->elem;
}

#endif
