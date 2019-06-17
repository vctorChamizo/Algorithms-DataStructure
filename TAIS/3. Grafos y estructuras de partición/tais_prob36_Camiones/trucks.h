// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef TRUCKS_H
#define TRUCKS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <vector>

#include  "GrafoValorado.h"

class trucks {

	std::vector<bool> marked;
	int weight;

public:

	trucks(GrafoValorado<int> const & G, int v_org, int w) : marked(G.V(), false), weight(w) { dfs(G, v_org); }

	bool is_possible(int v_dest) { return marked[v_dest]; }

private:

	void dfs(GrafoValorado<int> const & G, int v_org) {

		marked[v_org] = true;

		for (auto ady : G.ady(v_org)) if (!marked[ady.otro(v_org)] && ady.valor() >= weight) dfs(G, ady.otro(v_org));
	}
};

#endif
