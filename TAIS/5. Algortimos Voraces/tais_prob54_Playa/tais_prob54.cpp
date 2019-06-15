// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/* 
	EXPLICACIÓN:

		Este problema se ha resuleto aplicando un estrategia voraz en la que los edificios han sido 
		ordenados de menor a mayor segun la posicion final en la que acaban los edificios.

		De esta forma, si un edificio tiene un inicio mayor que el final del último edificio en el que se colocó
		un tunel, es necesario un tunel nuevo y se actualiza el final que marca la referencia.


	COSTES:
	
		- Coste de ordenar el vector -> O(log(n)) siendo n el numero de elementos del vector.


	COSTE TOTAL:
	
		O(n * log(n)) -> siendo n el número de edificios.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

struct tBuild {

	int begin;
	int end;

	tBuild() {}

	tBuild(int b, int e) : begin(b), end(e) {}

	bool operator < (tBuild const & b) const { return end < b.end || (end == b.end && begin < b.begin); }
};

int min_tunnel(std::vector<tBuild> const & v) {

	int n_tunnels = 1;
	int aux_end = v[0].end;

	for (int i = 1; i < v.size(); ++i) {

		if (v[i].begin >= aux_end) {

			n_tunnels++;

			aux_end = v[i].end;
		}
	}

	return n_tunnels;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<tBuild> v(n);

	int ini, fin;

	for (int i = 0; i < n; ++i) {

		std::cin >> ini >> fin;

		v[i] = { ini, fin };
	}

	std::sort(v.begin(), v.end());
	
	std::cout << min_tunnel(v) << std::endl;

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