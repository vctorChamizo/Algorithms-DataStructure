// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	FUNCIÓN:

		tesoros(i, j) = maximizar la cantidad de oro de obtnido en un tiempo maximo j
						teniendo en cuenta cofres definidos entre 1 e i.


	CASOS BASE:

		tesoros(0, j) = 0 -> si no hay cofres la cantidad maxima que se puede obtener de oro es cero.

		tesoros(i, 0) = 0 -> si el tiempo maximo de la botella es cero no se puede obtner oro.



	FUNCIÓN RECURSIVA:
			
							tesoros(i - 1, j)										si ti > j
		tesoros(i,j) = {																			
							max(tesoros(i - 1, j), tesoros(i - 1, j - ti) + vi		si ti <= j

			siendo:
					t = tiempo maximo disponible
					v = valor del cofre


	COSTES:

		- Coste en espacio adicional : (N * T) -> siendo N el numero de cofres y T la cantidad de aire disponible.

		- Coste en tiempo: (N * T) + (N * T) -> siendo N el numero de cofres y T la cantidad de aire disponible.


	COSTE TOTAL:

		O(N * T) -> siendo N el numero de cofres y T la cantidad de aire disponible.
 */
 
#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

#include "Matriz.h"

struct tTreasure {

	int depth;
	int gold;
	int time;
};

void treasures(std::vector<tTreasure> const & v, int T, int N, int & max_gold, int & n_chest, std::vector<bool> & chests) {

	Matriz<int> matrix(N + 1, T + 1, 0);

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= T; ++j) {

			if (v[i].time > j) matrix[i][j] = matrix[i - 1][j];
			else matrix[i][j] = std::max(matrix[i - 1][j], matrix[i - 1][j - v[i].time] + v[i].gold);
		}

	max_gold = matrix[N][T];

	int rest = T;

	for (int i = N; i >= 1; --i) {

		if (matrix[i][rest] == matrix[i - 1][rest]) chests[i] = false;
		else {

			chests[i] = true;
			n_chest++;
			rest -= v[i].time;
		}
	}
}

bool resuelveCaso() {

	int T;
	std::cin >> T;

	if (!std::cin) return false;

	int N;
	std::cin >> N;

	std::vector<tTreasure> v(N + 1);
	tTreasure t;
	int d, g;

	for (int i = 1; i <= N; ++i) {

		std::cin >> d >> g;

		t.depth = d;
		t.gold = g;
		t.time = d + (d * 2);

		v[i] = t;
	}
	
	int max_gold;
	int n_chest = 0;
	std::vector<bool> chests (N + 1);

	treasures(v, T, N, max_gold, n_chest, chests);

	if (max_gold == 0) std::cout << 0 << std::endl << 0 << std::endl;
	else {

		std::cout << max_gold << std::endl << n_chest << std::endl;

		for (int j = 1; j <= N; ++j) if (chests[j]) std::cout << v[j].depth << " " << v[j].gold << std::endl;
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