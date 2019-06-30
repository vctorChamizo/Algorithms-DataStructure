// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>

#include "bintree_eda.h"

template <class T>
class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	T nod_min() const { return nod_min(this->raiz); }

	bool operator < (Link const & r) { return this->raiz->elem < r->elem;  }

private:

	static T nod_min(Link r);
};

template <typename T>
inline bintree_ext<T> leerArbol_ext(T vacio) {

	T raiz;
	std::cin >> raiz;

	if (raiz == vacio) return {};
	else {

		auto iz = leerArbol_ext(vacio);
		auto dr = leerArbol_ext(vacio);
		return { iz, raiz, dr };
	}
}

template <typename T>
T bintree_ext<T>::nod_min(Link r) {

	if (r->left == nullptr && r->right == nullptr) return r->elem;
	else if (r->left == nullptr) return std::min(r->elem, nod_min(r->right));
	else if (r->right == nullptr) return std::min(r->elem, nod_min(r->left));
	else return std::min(r->elem, std::min(nod_min(r->left), nod_min(r->right)));
}
