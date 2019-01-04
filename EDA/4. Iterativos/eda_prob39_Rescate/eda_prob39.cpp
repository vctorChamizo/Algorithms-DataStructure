// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: EDA12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void Rescate(std::vector<int> const & v, int a, int & ini, int & fin) {

	int nEdificios = 0;
	int posicion = 0;
	int maxEdificios = 0;

	for (int i = 0; i < v.size(); ++i) {

		if (v[i] > a) nEdificios++;
		else nEdificios = 0;
			
		if (maxEdificios < nEdificios) {

			posicion = i;
			maxEdificios = nEdificios;
		}
	}

	ini = posicion - maxEdificios + 1;
	fin = posicion;
}

void resuelveCaso() {

	int nEdificios, altura;

	std::cin >> nEdificios >> altura;

	std::vector<int> edificios(nEdificios);

	for (int & n : edificios) std::cin >> n;

	int inicio = 0;
	int fin = 0;

	if (edificios.size() > 1) Rescate(edificios, altura, inicio, fin);

	std::cout << inicio << " " << fin << std::endl;
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