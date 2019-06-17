// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef BRIDGES_H
#define BRIDGES_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "GrafoValorado.h"
#include "PriorityQueue.h"

class bridges {

	PriorityQueue<Arista<int>> pq;
	std::vector<bool> marked;
	int _min_cost;

public:

	bridges(GrafoValorado<int> const & G) : marked(G.V(), false), _min_cost(0) {

		visit(G, 0);

		while (!pq.empty()) {

			auto edge = pq.top();
			pq.pop();

			int v_org = edge.uno();
			int v_dest = edge.otro(v_org);

			if (!marked[v_org] || !marked[v_dest]) _min_cost += edge.valor();
			if (!marked[v_org]) visit(G, v_org);
			if (!marked[v_dest]) visit(G, v_dest);
		}
	}

	bool is_possible() {

		for (auto m : marked) if (!m) return false;

		return true;
	}

	int min_cost() { return _min_cost; }

private:

	void visit(GrafoValorado<int> const & G, int v_org) {

		marked[v_org] = true;

		for (auto ady : G.ady(v_org)) if (!marked[ady.otro(v_org)]) pq.push(ady);
	}
};

#endif
