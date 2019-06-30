// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef queue_duplicate_h
#define queue_duplicate_h

#include <iostream>
#include <iomanip>
#include <fstream>

#include "queue_eda.h"

template <class T>
class queue_duplicate : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void duplica();
	void print(std::ostream & o = std::cout) const;
};

template <class T>
void queue_duplicate<T>::duplica() {

	Nodo * nodo_actual = this -> prim;
	Nodo * nodo_nuevo = nullptr;

	while (nodo_actual != nullptr) {

		nodo_nuevo = new Nodo(nodo_actual -> elem, nodo_actual -> sig);

		nodo_actual -> sig = nodo_nuevo;
		nodo_actual = nodo_nuevo -> sig;
		++this -> nelems;
	}

	this -> ult = nodo_nuevo;

}//duplica

template <class T>
void queue_duplicate<T>::print(std::ostream & o) const {

	Nodo * actual = this -> prim;

	while (actual -> sig != nullptr) {

		o << actual->elem << ' ';
		actual = actual -> sig;
	}

	o << actual -> elem;
	
}//print

#endif
