// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include "GrafoValorado.h"
#include "PriorityQueue.h"

class CostePuentes {

public:

	CostePuentes(GrafoValorado<int> const & G) : marcado(G.V(), false), costeMinimo(0), puentes(true) {

		visit(G, 0);

		while (!colaMin.empty()) {

			auto arista = colaMin.top();
			colaMin.pop();

			int vOrg = arista.uno();
			int vDes = arista.otro(vOrg);

			if (!marcado[vOrg] || !marcado[vDes]) costeMinimo += arista.valor();
			if (!marcado[vOrg]) visit(G, vOrg);
			if (!marcado[vDes]) visit(G, vDes);
		}

		int i = 0;

		while (i < marcado.size() && puentes) {
			
			if (!marcado[i]) puentes = false;
			i++;
		}
	}

	int getCosteMinimo() const { return costeMinimo; }
	
	bool hayPuentes() const { return puentes; }

private:

	PriorityQueue<Arista<int>> colaMin;
	std::vector<bool> marcado;
	bool puentes;
	int costeMinimo;

	void visit(GrafoValorado<int> const & G, int vOrg) {

		marcado[vOrg] = true;

		for (auto aristaAdy : G.ady(vOrg)) 
			if (!marcado[aristaAdy.otro(vOrg)])
				colaMin.push(aristaAdy);
	}
};