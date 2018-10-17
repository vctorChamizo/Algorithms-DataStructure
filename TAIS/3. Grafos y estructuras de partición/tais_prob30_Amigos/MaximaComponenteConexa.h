
#include <algorithm>
#include <vector>
#include "Grafo.h"


class MaximaComponenteConexa {

public:

	/*
		Inicializamos el array de booleamos marcado:
			- Indicamos el numero de elementos que va a contener (Numero de vertices).
			- Indicamos con que valor inicializamos (FALSE).

		Inicalizamos el valor _maximo indicandole el numero que queramos en el argumento.
	*/
	MaximaComponenteConexa(Grafo const& G) : marcado(G.V(), false), _maximo(0) {

		//Para cada uno de los vertices del grafo.
		for (int v = 0; v < G.V(); ++v) {

			//Si el vertice no ha sido marcado, es decir, si no ha sido recorrido.
			if (!marcado[v]) {

				int tam = 0;

				dfs(G, v, tam);

				//Si el tamaño del nuevo vertice recorrido es mayor, que el anterior, lo guardamos.
				_maximo = std::max(_maximo, tam);
			}
		}
	}

	//Tamaño máximo de una componente conexa
	int maximo() const {
		return _maximo;
	}


private:

	std::vector<bool> marcado; //Array de booleanos que indica si ya hemos estado en el vertice.

	int _maximo;

	//Recorre los adyacentes del verticeOrigen y acumula el maximo de sus adyacentes en tamMaximoAdy
	void dfs(Grafo const& G, int verticeOrigen, int & tamMaximoAdy) {

		//Lo ponemos como marcado ya que estamos sobre el.
		marcado[verticeOrigen] = true;

		++tamMaximoAdy;

		//Por cada uno de los adyacentes del verticeOrigen, comprobamos los adyacentes de los mismos.
		for (int verticeAdyacente : G.ady(verticeOrigen))
			if (!marcado[verticeAdyacente]) dfs(G, verticeAdyacente, tamMaximoAdy);
	}
};
