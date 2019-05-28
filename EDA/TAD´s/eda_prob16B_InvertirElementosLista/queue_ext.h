// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_eda.h"

template <class T>
class queue_ext : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void inverted_pair();
	void print(std::ostream & o = std::cout) const;
};

template <class T>
void queue_ext<T>::inverted_pair() {

	Nodo * current_node = this->prim;
	Nodo * previous_node = nullptr;
	Nodo * next_node = nullptr;

	int i = 0;
	if (this->size() > 1) {

		next_node = current_node->sig;
		this->prim = next_node;

		while (current_node != NULL && current_node->sig != NULL) {

			if (i != 0) previous_node->sig = current_node->sig;

			next_node = current_node->sig;
			current_node->sig = next_node->sig;
			next_node->sig = current_node;

			this->ult = current_node;

			previous_node = current_node;
			current_node = current_node->sig;
			
			if (current_node != NULL && current_node->sig != NULL) this->ult = current_node;

			++i;
		}
	}
}

template <class T>
void queue_ext<T>::print(std::ostream & out) const {

	Nodo * current_node = this->prim;

	out << current_node->elem;
	current_node = current_node->sig;

	while (current_node != nullptr) {

		out << ' ' << current_node->elem;
		current_node = current_node->sig;
	}
}