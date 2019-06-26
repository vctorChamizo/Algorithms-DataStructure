// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef ARBORESCENCE_H
#define ARBORESCENCE_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <vector>

#include "GrafoDirigido.h"

class arborescence {

	std::vector<bool> marked;
	bool _arborescence;
	int cont_v_marked;
	int root;

public:

	arborescence(GrafoDirigido const & G) : marked(G.V(), false), _arborescence(true), cont_v_marked(0), root(-1) {

		for (auto i = 0; i < G.V(); ++i) {

			if (is_candidate(G, i)) {

				dfs(G, i);

				if (_arborescence && cont_v_marked == G.V()) root = i;
				else _arborescence = false;
			}
		}

		if (root == -1) _arborescence = false;
	}

	bool is_arborescence() const { return _arborescence; }

	int get_root() const { return root; }

private:

	/*
		Comprueba que el vertice candidato unicamente tiene aristas de salida.
	*/
	bool is_candidate(GrafoDirigido const & G, int candidate_root) {

		// Para cada uno de los vertices del grafo (que no sea el candidato) se comprueba que los adyacentes
		// de los mismos no sean el propio vertice candidato
		for (auto v = 0; v < G.V(); ++v) 
			if (v != candidate_root)
				for (auto ady : G.ady(v)) if (ady == candidate_root) return false;

		return true;
	}

	void dfs(GrafoDirigido const & G, int v_org) {

		marked[v_org] = true;
		cont_v_marked++;

		for (auto ady : G.ady(v_org)) 
			if (!marked[ady]) dfs(G, ady);
			else _arborescence = false;
	}
};

#endif
