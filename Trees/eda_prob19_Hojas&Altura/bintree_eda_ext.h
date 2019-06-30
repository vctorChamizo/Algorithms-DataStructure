// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"

template <class T>
class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	size_t height() const { return height(this->raiz); }
	size_t nods() const { return nods(this->raiz); }
	size_t sheets() const { return sheets(this->raiz); }

private:

	static size_t height(Link r);
	static size_t nods(Link r);
	static size_t sheets(Link r);
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
size_t bintree_ext<T>::height(Link r) {

	if (r == nullptr) return 0;
	else return std::max(height(r->left), height(r->right)) + 1;
}

template <typename T>
size_t bintree_ext<T>::nods(Link r) {

	if (r == nullptr) return 0;
	else return nods(r->left) + nods(r->right) + 1;
}

template <typename T>
size_t bintree_ext<T>::sheets(Link r) {

	if (r == nullptr) return 0;
	else if (r->left == nullptr && r->right == nullptr) return 1;
	else return sheets(r->left) + sheets(r->right);
}
