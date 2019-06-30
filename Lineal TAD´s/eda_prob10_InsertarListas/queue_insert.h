// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef queue_duplicate_h
#define queue_duplicate_h

#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_eda.h"

template <class T>
class queue_insert : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void inserta(queue_insert<int> & l_aux, int p);
	void print(std::ostream & o = std::cout) const;
};

template <class T>
void queue_insert<T>::inserta(queue_insert<int> & l_aux, int p) {

	int cont = 0;
	Nodo * nodo_actual = this->prim;

	if (p == 0) {

		l_aux.ult->sig = nodo_actual;
		this->prim = l_aux.prim;
	}
	else {

		while (cont < p - 1) {

			nodo_actual = nodo_actual->sig;
			cont++;
		}

		l_aux.ult->sig = nodo_actual->sig;
		nodo_actual->sig = l_aux.prim;
	}

	this->nelems = this->nelems + l_aux.size();
	l_aux.prim = nullptr;
	l_aux.ult = nullptr;
	l_aux.nelems = 0;
}

template <class T>
void queue_insert<T>::print(std::ostream & o) const {

	Nodo * actual = this->prim;

	while (actual->sig != nullptr) {

		o << actual->elem << ' ';
		actual = actual->sig;
	}

	o << actual->elem;
}

#endif
