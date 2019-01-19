// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS 58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int minimoParches(std::vector<int> const & v, int l) {

	int p = 1, tapado = v[0] + l;

	for (auto i = 1; i < v.size(); ++i) 
		if (v[i] > tapado) {
			p++;
			tapado = v[i] + l;
		}

	return p;
}


bool resuelveCaso() {

	int agujeros;
	std::cin >> agujeros;

	if (!std::cin) return false;

	int longitud;
	std::cin >> longitud;

	std::vector<int> manguera(agujeros);

	for (auto i = 0; i < agujeros; ++i) 
		std::cin >> manguera[i];

	int parches = minimoParches(manguera, longitud);

	std::cout << parches << std::endl;

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