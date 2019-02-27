// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef queue_duplicate_h
#define queue_duplicate_h

#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_eda.h"

template <class T>
class queue_merge : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void mezclar(queue_merge<int> & l_aux);
	void print(std::ostream & o = std::cout) const;
};

template <class T>
void queue_merge<T>::mezclar(queue_merge<int> & l_aux) {

	this->nelems = this->nelems + l_aux.nelems;

	if (this->ult->elem < l_aux.prim->elem) this->ult->sig = l_aux.prim;
	else if (this->prim->elem > l_aux.ult->elem) {

		l_aux.ult->sig = this->prim;
		this->prim = l_aux.prim;
	}
	else {

		Nodo * nodo_actual = this->prim;
		Nodo * nodo_list = l_aux.prim;
		Nodo * nodo_aux;

		if (nodo_actual->elem > nodo_list->elem) std::swap(nodo_actual->elem, nodo_list->elem);

		while (nodo_list != nullptr) {

			while (nodo_actual->sig != nullptr && nodo_list->elem > nodo_actual->sig->elem) nodo_actual = nodo_actual->sig;

			nodo_aux = nodo_list->sig;
			nodo_list->sig = nodo_actual->sig;
			nodo_actual->sig = nodo_list;
			nodo_list = nodo_aux;
		}
	}

	l_aux.prim = nullptr;
	l_aux.ult = nullptr;
	l_aux.nelems = 0;
}

template <class T>
void queue_merge<T>::print(std::ostream & o) const {

	Nodo * actual = this->prim;

	while (actual->sig != nullptr) {

		o << actual->elem << ' ';
		actual = actual->sig;
	}

	o << actual->elem;
}

#endif
