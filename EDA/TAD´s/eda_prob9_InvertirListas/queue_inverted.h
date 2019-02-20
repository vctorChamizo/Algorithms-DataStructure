// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef queue_inverted_h
#define queue_inverted_h

#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_eda.h"

template <class T>
class queue_inverted : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void invierte();
	void print(std::ostream & o = std::cout) const;
};

template <class T>
void queue_inverted<T>::invierte() {

	Nodo * nodo_actual = this->prim;
	Nodo * nodo_anterior = nullptr;
	Nodo * nodo_siguiente;

	while (nodo_actual != nullptr) {

		nodo_siguiente = nodo_actual->sig;
		nodo_actual->sig = nodo_anterior;
		nodo_anterior = nodo_actual;
		nodo_actual = nodo_siguiente;
	}
}//duplica

template <class T>
void queue_inverted<T>::print(std::ostream & o) const {

	Nodo * actual = this -> ult;

	while (actual -> sig != nullptr) {

		o << actual->elem << ' ';
		actual = actual -> sig;
	}

	o << actual -> elem;
	
}//print

#endif
