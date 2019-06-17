// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef VILLAGE_H
#define VILLAGE_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <vector>
#include <limits.h>

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

class village {

	std::vector<int> dist_to;
	IndexPQ<int> ipq;

public:

	village(GrafoDirigidoValorado<int> const & G, int v_org) : dist_to(G.V(), INT_MAX), ipq(G.V()) {

		dist_to[v_org] = 0;
		ipq.push(v_org, 0);

		while (!ipq.empty()) {

			int v = ipq.top().elem;
			ipq.pop();

			for (auto edge : G.ady(v)) relax(edge);
		}
	}

	int min_cost(int v_dest) { return dist_to[v_dest]; }

private:

	void relax(AristaDirigida<int> const & e) {

		int v = e.from();
		int w = e.to();

		if (dist_to[w] > dist_to[v] + e.valor()) {

			dist_to[w] = dist_to[v] + e.valor();
			ipq.update(w, dist_to[w]);
		}
	}
};

#endif
