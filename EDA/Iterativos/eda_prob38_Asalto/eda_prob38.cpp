// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: EDA12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void Atraco(std::vector<int> const & v, int t, int & g, int & nv) {

	int aux_recorrido;
	int aux_g;

	for (int i = 0; i <= v.size() - t; ++i) {

		aux_g = 0;
		aux_recorrido = i + t;

		for (int j = i; j < aux_recorrido; ++j) aux_g += v[j];

		if (aux_g >= g) {

			g = aux_g;
			nv = i;
		}
	}
}

void resuelveCaso() {

	int nVagones, tiempo;

	std::cin >> nVagones >> tiempo;

	std::vector<int> vector(nVagones);

	for (int & n : vector) std::cin >> n;

	int ganancia, nVagon;

	Atraco(vector, tiempo, ganancia, nVagon);

	std::cout << nVagon << " " << ganancia << std::endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}