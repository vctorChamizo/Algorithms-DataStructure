// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef SCHOOL_H
#define SCHOOL_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <vector>
#include <limits.h>

#include "GrafoValorado.h"
#include "IndexPQ.h"

class school {

	std::vector<int> dist_to;
	std::vector<int> _n_paths;
	IndexPQ<int> ipq;

public:

	school(GrafoValorado<int> const & G) : dist_to(G.V(), INT_MAX), _n_paths(G.V(), 0), ipq(G.V()) {

		int v_org = 0;

		dist_to[v_org] = 0;
		_n_paths[v_org] = 1;
		ipq.push(v_org, 0);

		while (!ipq.empty()) {

			int v = ipq.top().elem;
			ipq.pop();

			for (auto edge : G.ady(v)) relax(v, edge.otro(v), edge.valor());
		}
	}

	int n_paths(int i) const { return _n_paths[i]; }

private:

	void relax(int v, int w, int value) {

		if (dist_to[w] > dist_to[v] + value) {

			dist_to[w] = dist_to[v] + value;
			ipq.update(w, dist_to[w]);

			_n_paths[w] = _n_paths[v];
		}
		else if (dist_to[w] == dist_to[v] + value)
			_n_paths[w] += _n_paths[v];
	}
};

#endif
