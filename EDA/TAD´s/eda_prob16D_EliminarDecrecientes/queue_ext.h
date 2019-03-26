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

	void removeDecreasingValue();
	void print(std::ostream & o = std::cout) const;
};

template <class T>
void queue_ext<T>::removeDecreasingValue() {

	Nodo * current_node = this->prim;
	Nodo * next_node = current_node->sig;

	while (next_node != nullptr) {

		if (next_node->elem < current_node->elem) {

			current_node->sig = next_node->sig;
			delete next_node;

			next_node = current_node->sig;

			--this->nelems;
		}
		else {

			current_node = current_node->sig;
			next_node = (current_node == nullptr ? nullptr : current_node->sig);
		}

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
