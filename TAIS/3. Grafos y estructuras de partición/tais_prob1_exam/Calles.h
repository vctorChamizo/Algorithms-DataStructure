
/*
	REALIZADO POR: Víctor Chamizo Rodríguez
	USUARIO JUEZ: TAIS58
*/

#include <vector>
#include <queue>

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

const int INF = 1000000000;

class Calles {

public:

	Calles(GrafoDirigidoValorado<int> const & G, int s) : nMetros(G.V()), nCalles(G.V()), pq(G.V()),
														  nCallesMinimas(G.V()), marked(G.V(), false) {

		// Algoritmo de Dijkstra.
		for (int v = 0; v < G.V(); v++) nMetros[v] = INF;

		nMetros[s] = 0;
		nCalles[s] = 0;
		pq.push(s, 0);

		while (!pq.empty()) {

			int v = pq.top().elem;
			pq.pop();

			for (AristaDirigida<int> e : G.ady(v)) relax(e);
		}

		// Busqueda en anchura.
		bfs(G, s);
	}

	// Distancia en recorrida en metros (coste de las aristas)
	int getDistancia(int x) {  return nMetros[x]; }

	// Numero de calles minimas recorridas (numero de aristas recorridas)
	int getCalles(int x) { return nCalles[x]; }

	// Número minimo de aristas para llegar a un destino
	int getCaminoMinimo(int v) const { return nCallesMinimas[v]; }

private:

	std::vector<int> nMetros;
	std::vector<int> nCalles;
	IndexPQ<int> pq;

	std::vector<bool> marked;
	std::vector<int> nCallesMinimas;

	void relax(AristaDirigida<int> e) {

		int v = e.from(), w = e.to();

		if (nMetros[w] > nMetros[v] + e.valor()) {

			nMetros[w] = nMetros[v] + e.valor();
			nCalles[w] = nCalles[v] + 1;
			pq.update(w, nMetros[w]);
		}
	}// relax

	void bfs(GrafoDirigidoValorado<int> const & G, int s) {

		std::queue<int> q;
		nCallesMinimas[s] = 0;
		marked[s] = true;
		q.push(s);

		while (!q.empty()) {

			int v = q.front();
			q.pop();

			for (auto w : G.ady(v)) {

				int dest = w.to();

				if (!marked[dest]) {

					nCallesMinimas[dest] = nCallesMinimas[v] + 1;
					marked[dest] = true;
					q.push(dest);
				}
			}
		}
	}// bfs
};