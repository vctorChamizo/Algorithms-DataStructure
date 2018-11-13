// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58


#include "GrafoValorado.h"


class Camiones {

public:

	Camiones(GrafoValorado<int> const & G, int vOrg, int anchura) : marcado(G.V(), false) {

		dfs(G, vOrg, anchura);
	}

	bool esRuta(int vDest) const { return marcado[vDest]; }

private:

	std::vector<bool> marcado;

	void dfs(GrafoValorado<int>const& G, int vOrg, int anchura) {
		
		marcado[vOrg] = true;

		for (auto aristaAdy : G.ady(vOrg)) {

			int vDest = aristaAdy.otro(vOrg);

			if (!marcado[vDest] && aristaAdy.valor() >= anchura) dfs(G, vDest, anchura);
		}
	}
};