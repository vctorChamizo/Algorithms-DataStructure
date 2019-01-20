#include <climits>

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

class Laberinto {

public:

	Laberinto(GrafoDirigidoValorado<int> const & G, int S) : distTo(G.V(), INT_MAX) , edgeTo(G.V()), ipq(G.V()) {

		distTo[S] = 0;
		ipq.push(S, 0);

		while (!ipq.empty()) {

			int v = ipq.top().elem;
			ipq.pop();

			for (auto edge : G.ady(v)) relax(edge);
		}
	}

	int getRatones(int T) { 
	
		int nRatones = 0;

		for (int & r : distTo) if (r <= T && r > 0) nRatones++;

		return nRatones;
	}

private:

	std::vector<int> distTo;
	std::vector< AristaDirigida<int>> edgeTo;
	IndexPQ<int> ipq;

	void relax(AristaDirigida<int> e) {

		int v = e.from();
		int w = e.to();

		if (distTo[w] > distTo[v] + e.valor()) {

			distTo[w] = distTo[v] + e.valor();
			edgeTo[w] = e;
			ipq.update(w, distTo[w]);

		}
	}

};