// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <vector>
#include <limits.h>

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

class network {

	std::vector<int> dist_to;
	std::vector<int> v_charge;
	IndexPQ<int> ipq;

public:

	network(GrafoDirigidoValorado<int> const & G, std::vector<int> v_c) : dist_to(G.V(), INT_MAX), ipq(G.V()), v_charge(v_c) {

		dist_to[0] = v_charge[0];
		ipq.push(0, 0);

		while (!ipq.empty()) {

			int v = ipq.top().elem;
			ipq.pop();

			for (auto edge : G.ady(v)) relax(edge);
		}
	}

	bool is_possible() {

		for (auto const & d : dist_to) if (d == INT_MAX) return false;

		return true;
	}

	int min_path(int v_dest) { return dist_to[v_dest]; }

private:

	void relax(AristaDirigida<int> const & e) {

		int v = e.from();
		int w = e.to();

		if (dist_to[w] > dist_to[v] + e.valor() + v_charge[w]) {

			dist_to[w] = dist_to[v] + e.valor() + v_charge[w];
			ipq.update(w, dist_to[w]);
		}
	}
};

#endif
