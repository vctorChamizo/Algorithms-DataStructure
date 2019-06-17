// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <vector>
#include <limits.h>

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

class labyrinth {

	std::vector<int> dist_to;
	IndexPQ<int> ipq;

public:

	labyrinth(GrafoDirigidoValorado<int> const & G, int S) : dist_to(G.V(), INT_MAX), ipq(G.V()) {

 		dist_to[S] = 0;
		ipq.push(S, 0);

		while (!ipq.empty()) {

			int v = ipq.top().elem;
			ipq.pop();

			for (auto edge : G.ady(v)) relax(edge);
		}
	}

	int min_mouses(int T) {

		int _n_mouses = 0;

		for (int i = 0; i < dist_to.size(); ++i) if (dist_to[i] > 0 && dist_to[i] <= T) _n_mouses++;
		
		return _n_mouses;
	}

private :

	void relax(AristaDirigida<int> const & edge) {

		int v = edge.from();
		int w = edge.to();

		if (dist_to[w] > dist_to[v] + edge.valor()) {

			dist_to[w] = dist_to[v] + edge.valor();
			ipq.update(w, dist_to[w]);
		}
	}
};

#endif
