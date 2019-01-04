// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int calcularPosicion(std::vector<int> const & v) {

	int p = -1;
	int contUnos = 0;
	int contCeros = 0;

	for (auto i = 0; i < v.size(); ++i) {

		if (v[i] == 0) contCeros++;
		else if (v[i] == 1) contUnos++;

		if (contCeros == contUnos) p = i;
	}

	return p;
}


void resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	std::vector<int> vector(nElem);

	for (auto & n : vector) std::cin >> n;

	int posicion = calcularPosicion(vector);

	std::cout << posicion << std::endl;
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