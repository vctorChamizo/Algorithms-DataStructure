// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <vector>
#include "Grafo.h"

struct tMarcado {

	bool marcado = false;
	bool color = false;
};

class Bipartito {

public:

	Bipartito(Grafo const & G) : listaMarcado(G.V(), verticeMarcado), esBipartito(true) {

		int i = 0;

		while (esBipartito && i < G.V()) {

			dfs(G, i);
			i++;
		}
	}


	bool getBipartito() const {
		return esBipartito;
	}


private:

	tMarcado verticeMarcado; //Array de booleanos que indica si ya hemos estado en el vertice.

	std::vector<tMarcado> listaMarcado;

	bool esBipartito;

	void dfs(Grafo const & G, int & vOrg) {

		listaMarcado[vOrg].marcado = true;

		for (int vAdy : G.ady(vOrg)) {

			if (!listaMarcado[vAdy].marcado) {

				listaMarcado[vAdy].color = !listaMarcado[vOrg].color;
				dfs(G, vAdy);
			}
			else if (listaMarcado[vAdy].color == listaMarcado[vOrg].color) {

				esBipartito = false;
				return;
			}
		}
	}
};
