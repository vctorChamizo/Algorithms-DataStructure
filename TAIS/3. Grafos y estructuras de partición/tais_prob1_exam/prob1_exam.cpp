
/*

	REALIZADO POR: Víctor Chamizo Rodríguez
	USUARIO JUEZ: TAIS58


	EXPLICACIÓN:
		
		El problema requiere calcular el coste minimo desde una interseccion origen a una interseccion destino (algoritmo Dijkstra),
		así como saber el minimo de calles que se deben recorrer para llegar al punto de destino (busqueda en anchura).

		De este forma con el algoritmo de Dijkstra, sabemos la distancia minima que recorremos al destino y el numero de calles que
		hemos recorrido en dicho trayecto, que comparandolo con el camino minimo en cuanto a calles recorridas que nos facilita
		la búsqueda en anchura, podemos comparar si ambos resultados coinciden y si efectivamente, el camino recorrido coincide con
		el minimo numero de calles necesarias para llegar al destino deseado.


	COSTE:

		Dijkstra: O(C * log(N)) --> siendo N el número de intersecciones (vértices del grafo) y C es el número de calles (aristas).
								--> log(N) coste de hacer push() y pop() en nuestra IndexPQ y se realiza C veces ya que es nuestro número de calles.
	
		BFS: O(C + N) --> siendo N el número de intersecciones (vértices del grafo) y C es el número de calles (aristas).

		Coste total: esto se realiza para cada K consultas --> O(K * (C * log(N) + C + N)
*/

#include <iostream>
#include <fstream>
#include <vector>

#include "GrafoDirigidoValorado.h"
#include "Calles.h"

bool resuelveCaso() {

	int V, E;
	std::cin >> V >> E;

	if (!std::cin) return false;

	GrafoDirigidoValorado<int> grafo(V);
	int v, w, valor;

	for (int i = 0; i < E; i++) {

		std::cin >> v >> w >> valor;

		//Como las calles son de doble sentido --> añadimos ambas aristas.
		grafo.ponArista({v - 1, w - 1, valor});
		grafo.ponArista({w - 1, v - 1, valor });
	}

	int K, ini, fin;
	std::cin >> K;

	for (int x = 0; x < K; x++) {

		std::cin >> ini >> fin;

		// Realizamos el algoritmo de de Dijkstra y la búsqueda en anchura.
		// Esto nos proporciona los datos necesarios para resolver el problema.
		Calles calles(grafo, ini - 1);

		int distancia = calles.getDistancia(fin - 1); // Distancia minima que hemos recorrido desde el origen hasta el destino.

		if (distancia != INF) { // Significa que no hay camino posible a esa interseccion.

			std::cout << distancia;

			// Numero de calles que hemos recorrido .
			// Numero minimo de calles que hay que recorrer para llegar al destino.
			if (calles.getCalles(fin - 1) == calles.getCaminoMinimo(fin - 1)) std::cout << " SI" << std::endl;
			else std::cout << " NO" << std::endl;
		}
		else std::cout << "SIN CAMINO" << std::endl;
	}

	std::cout << "----" << std::endl;

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
