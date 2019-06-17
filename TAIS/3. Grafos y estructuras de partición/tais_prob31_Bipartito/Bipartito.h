// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef BIPARTITO_H
#define BIPARTITO_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <vector>

#include "Grafo.h"

/*
	if (!color) color = BLUE;

	if (color) color = RED;
*/
struct tMarked {

	bool marked = false;
	bool color = false;
};

class bipartito {

	bool _bipartito;
	std::vector<tMarked> marked;

public:

	bipartito(Grafo const & G) : _bipartito(true), marked(G.V()) {

		for (auto i = 0; i < G.V(); ++i) 
			if (!marked[i].marked) 
				dfs(G, i, marked[i].color);
	}

	bool is_bipartito() const { return _bipartito; }

private:

	void dfs(Grafo const & G, int v_org, bool previous_color) {

		marked[v_org].marked = true;
		marked[v_org].color = !previous_color;

		for (auto ady : G.ady(v_org)) {

			if (marked[ady].marked && marked[v_org].color == marked[ady].color) _bipartito = false;
			else if (!marked[ady].marked) dfs(G, ady, marked[v_org].color);
		}
	}
};

#endif
