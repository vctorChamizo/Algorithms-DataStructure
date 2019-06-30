// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <fstream>
#include <algorithm>

#include "Pelicula.h"

bool resuelveCaso() {

	int P;
	std::cin >> P;

	if (P == 0) return false;

	std::vector<Pelicula> peliculas(P);

	try { 

		for (auto & p : peliculas) std::cin >> p; 
	}
	catch (std::domain_error & ia) { std::cout << ia.what() << std::endl; }
	

	sort(peliculas.begin(), peliculas.end());

	for (auto & p : peliculas) std::cout << p << std::endl;

	std::cout << "---" << std::endl;

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