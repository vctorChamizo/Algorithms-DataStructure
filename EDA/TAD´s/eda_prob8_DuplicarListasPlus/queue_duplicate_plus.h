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
	void amplia(queue_duplicate & l_aux);
	void elimina(int n);
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
void queue_duplicate<T>::amplia(queue_duplicate & l_aux) {

	Nodo * nodo_aux = l_aux.prim;

	this->ult->sig = nodo_aux;
	this->ult = l_aux.ult;
	this->nelems += l_aux.size();

	l_aux.prim = nullptr;
	l_aux.ult = nullptr;
	l_aux.nelems = 0;

}//amplia

template <class T>
void queue_duplicate<T>::elimina(int n) {

	Nodo * nodo_actual = this->prim;
	int i = 0;

	while (i < n) {

		nodo_actual = nodo_actual->sig;
		i++;
	}
		
	this->prim = nodo_actual;
	this->nelems -= n;

}//elimina

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
