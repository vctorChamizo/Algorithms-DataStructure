// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez:


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


int maximoVictorias(std::vector<int> const & c, std::vector<int> const & e) {

	int i = 0, j = 0, nVictorias = 0;

	while (i < c.size() && j < e.size()) {

		if (c[i] <= e[j]) {

			nVictorias++;
			i++;
		}

		j++;
	}

	return nVictorias;
}


bool resuelveCaso() {

	int n;

	std::cin >> n;

	if (!std::cin) return false;

	std::vector<int> enemigosCiudades(n);
	std::vector<int> efectivosEquipos(n);

	for (auto i = 0; i < n; ++i)
		std::cin >> enemigosCiudades[i];

	for (auto j = 0; j < n; ++j)
		std::cin >> efectivosEquipos[j];

	std::sort(enemigosCiudades.begin(), enemigosCiudades.end());
	std::sort(efectivosEquipos.begin(), efectivosEquipos.end());

	int maximo = maximoVictorias(enemigosCiudades, efectivosEquipos);

	std::cout << maximo << std::endl;

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