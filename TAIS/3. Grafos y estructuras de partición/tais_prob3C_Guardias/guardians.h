// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef GUARDIANS_H
#define GUARDIANS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include <vector>
#include <algorithm>

#include "Grafo.h"

class guardians {

	std::vector<bool> marked;; // Controla los vertices que se han visitado.
	std::vector<bool> marked_guardians; // Controla los posibles guardias que se colocan el los vertices (guardias = TRUE || guardias = FALSE)
	
	int _guardians_true; // Contabiliza los guardias que se colocan a TRUE.
	int _guardians_false; // Contabiliza los guardias que se colocan a FALSE.
	
	int _min_guardians;
	bool _is_possible;

public:

	guardians(Grafo const & G) : marked(G.V(), false), marked_guardians(G.V(), false), _is_possible(true), _min_guardians(0) {

		for (int i = 0; i < G.V(); ++i) {

			_guardians_true = _guardians_false = 0;

			if (!marked[i]) { // Si el vertice a visitar no esta marcado -> se suma uno a los guardias con FALSE.

				_guardians_false++;
				dfs(G, i);
			}

			_min_guardians += std::min(_guardians_true, _guardians_false);
		}
	}

	bool is_possible() { return _is_possible; }

	int min_guardians() { return _min_guardians; }

private:

	void dfs(Grafo const & G, int v_org) {

		marked[v_org] = true;

		for (auto ady : G.ady(v_org)) {

			if (!marked[ady]) {

				// El vertice adyacente tiene el tipo de guardia inverso al de el verice origen.
				marked_guardians[ady] = !marked_guardians[v_org]; 

				if (marked_guardians[ady]) _guardians_true++;
				else _guardians_false++;

				dfs(G, ady);
			}
			// Si el vertice adyacente ya ha sido visitado y tiene el mismo tipo de guardia que el origen -> hay conflicto.
			else if (marked_guardians[ady] == marked_guardians[v_org]) _is_possible = false;
		}
	}
};

#endif
