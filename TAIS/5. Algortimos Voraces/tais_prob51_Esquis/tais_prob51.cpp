// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


int encontrarMinimaDiferencia(std::vector<int> const & a, std::vector<int> const & l) {

	int sum = 0;

	for (int i = 0; i < a.size(); ++i)
		sum += abs(a[i] - l[i]);

	return sum;
}


bool resuelveCaso() {

	int esquiadores;
	std::cin >> esquiadores;

	if (esquiadores == 0) return false;

	std::vector<int> alturas(esquiadores);
	std::vector<int> longitudes(esquiadores);

	for (int i = 0; i < esquiadores; ++i)
		std::cin >> alturas[i];

	for (int j = 0; j < esquiadores; ++j)
		std::cin >> longitudes[j];

	std::sort(alturas.begin(), alturas.end());
	std::sort(longitudes.begin(), longitudes.end());

	int minimaDiferencia = encontrarMinimaDiferencia(alturas, longitudes);

	std::cout << minimaDiferencia << std::endl;

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