// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>

#include "bintree_eda.h"

const std::string DRAGON = "Dragon";

struct tWay {

	std::string name_sheet;
	int n_dragons;
};

template <class T>
class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	tWay way_min() const { return way_min_private(this->raiz); }

private:

	static tWay way_min_private(Link r);
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
tWay bintree_ext<T>::way_min_private(Link r) {

	tWay w, w_left, w_right;

	if (r->left == nullptr && r->right == nullptr) {

		w.n_dragons = 0;
		w.name_sheet = r->elem;

		return w;
	}
	else if (r->right == nullptr) {

		w_left = way_min_private(r->left);

		if (r->elem == DRAGON) w_left.n_dragons++;

		return w_left;
	}
	else if (r->left == nullptr) {

		w_right = way_min_private(r->right);
		
		if (r->elem == DRAGON) w_right.n_dragons++;

		return w_right;
	}
	else {

		w_left = way_min_private(r->left);
		w_right = way_min_private(r->right);

		if (w_left.n_dragons > w_right.n_dragons) {

			w.n_dragons = w_right.n_dragons;
			w.name_sheet = w_right.name_sheet;
		}
		else {

			w.n_dragons = w_left.n_dragons;
			w.name_sheet = w_left.name_sheet;
		}

		if (r->elem == DRAGON) w.n_dragons++;

		return w;
	}
}
