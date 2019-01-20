// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <climits>

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"


class Enlaces {

public:

	Enlaces(GrafoDirigidoValorado<int> const & G, std::vector<int> const & vTC) : 
			distTo(G.V(), INT_MAX), edgeTo(G.V()), ipq(G.V()), camino(true){

		distTo[0] = vTC[0];
		ipq.push(0, 0);

		while (!ipq.empty()) {

			int v = ipq.top().elem;
			ipq.pop();

			for (auto arista : G.ady(v)) 
				relax(arista, vTC);
		}

		if (distTo[G.V() - 1] == INT_MAX)
			camino = false;
	}

	int getTiempoMinimo(int vDes) const { return distTo[vDes - 1]; }

	bool hayCamino() const { return camino; }

private:

	std::vector<int> distTo;
	std::vector<AristaDirigida<int>> edgeTo;
	IndexPQ<int> ipq;

	int tiempoMinimo;
	bool camino;

	void relax(AristaDirigida<int> e, std::vector<int> const & vTC) {

		int v = e.from();
		int w = e.to();

		if (distTo[w] > distTo[v] + e.valor() + vTC[w]) {

			distTo[w] = distTo[v] + e.valor() + vTC[w];
			edgeTo[w] = e;
			ipq.update(w, distTo[w]);
			
		}
	}
};