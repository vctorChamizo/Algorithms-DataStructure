// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool esDisperso(std::vector<int> const& v, int ini, int fin, int dis) {

	if (ini == fin) return true;
	else if (ini + 1 == fin) return (abs(v[ini] - v[fin])) >= dis;
	else {

		if (abs(v[ini] - v[fin]) >= dis) {

			int m = (ini + fin) / 2;

			bool dispersionIz, dispersionDch;

			dispersionIz = esDisperso(v, ini, m, dis);
			if (dispersionIz) dispersionDch = esDisperso(v, m + 1, fin, dis);

			if (dispersionIz && dispersionDch) return true;
			else return false;

		}

		return false;
	}
}


bool resuelveCaso() {

	long int nTiradas;

	std::cin >> nTiradas;

	if (!std::cin)
		return false;

	int dispersion;

	std::cin >> dispersion;

	std::vector<int> valorTiradas(nTiradas);

	for (int i = 0; i < valorTiradas.size(); ++i)
		std::cin >> valorTiradas[i];

	bool disperso = false;
	
	disperso = esDisperso(valorTiradas, 0, valorTiradas.size() - 1, dispersion);

	if (disperso) std::cout << "SI";
	else std::cout << "NO";

	std::cout << std::endl;

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