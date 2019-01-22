#include <vector>
#include <climits>

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

class Reparto {

public:

	Reparto(GrafoDirigidoValorado<int> const & G, int O) : distTo(G.V(), INT_MAX), edgeTo(G.V()), ipq(G.V()) {

		distTo[O] = 0;
		ipq.push(O, 0);

		int v;

		while (!ipq.empty()) {

			v = ipq.top().elem;
			ipq.pop();

			for (auto arista : G.ady(v)) relax(arista);
		}
	}

	int getEsfuerzo(int des) { return distTo[des]; }

private:

	std::vector<int> distTo;
	std::vector<AristaDirigida<int>> edgeTo;
	IndexPQ<int> ipq;

	void relax(AristaDirigida<int> const & e) {

		int v = e.from();
		int w = e.to();

		if (distTo[w] > distTo[v] + e.valor()) {

			distTo[w] = distTo[v] + e.valor();
			edgeTo[w] = e;
			ipq.update(w, distTo[w]);
		}
	}

};