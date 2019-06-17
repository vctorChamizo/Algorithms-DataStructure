// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef MAX_FRIENDS_H
#define MAX_FRIENDS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <vector>
#include <algorithm>

#include "Grafo.h"

class max_friends {

	int _max;
	std::vector<bool> marked;

public:

	max_friends(Grafo const & G) : marked(G.V(), false), _max(0) {

		int cont;

		for (auto i = 0; i < G.V(); ++i) {

			cont = 0;

			if (!marked[i]) dfs(G, i, cont);

			_max = std::max(_max, cont);
		}
	}

	int max() const { return _max; }


private:

	void dfs(Grafo const & g, int v_org, int & cont) {

		marked[v_org] = true;
		cont++;

		for (auto ady : g.ady(v_org)) if (!marked[ady]) dfs(g, ady, cont);
	}
};

#endif
