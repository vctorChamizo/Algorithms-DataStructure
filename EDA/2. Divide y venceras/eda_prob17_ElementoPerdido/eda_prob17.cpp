// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int calcularFaltante(std::vector<int> const & vE, std::vector<int> const & vF, int ini, int fin) {

	if (ini == fin) return vE[ini];
	else if (ini + 1 == fin) {

		if (vE[ini] == vF[ini]) return vE[fin];
		else return vE[ini];
	}
	else {

		int m = (ini + fin) / 2;

		if (vE[m] == vF[m]) calcularFaltante(vE, vF, m + 1, fin);
		else calcularFaltante(vE, vF, 0, m);
	}
}


void resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	std::vector<int> vectorEntero(nElem);
	std::vector<int> vectorFaltante(nElem - 1);

	for (int i = 0; i < vectorEntero.size(); ++i)
		std::cin >> vectorEntero[i];

	for (int j = 0; j < vectorFaltante.size(); ++j)
		std::cin >> vectorFaltante[j];

	int faltante;

	faltante = calcularFaltante(vectorEntero, vectorFaltante, 0, vectorEntero.size() - 1);

	std::cout << faltante << std::endl;
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