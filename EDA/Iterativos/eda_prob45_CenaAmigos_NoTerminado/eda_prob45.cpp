// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSecuencia {

	int suma;
	int ini = 0;
	int longitud = 0;
};

tSecuencia encontrarSubsecuencia(std::vector<int> const & v) {

	tSecuencia sec;
	int maxSum = 0;

	for (int i = 0; i < v.size() - 1; ++i) {

		if (v[i] + v[i + 1] > maxSum) {


		}
	}
}


bool resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	if (!std::cin) return false;

	std::vector<int> vector(nElem);

	for (int & v : vector) std::cin >> v;

	tSecuencia secuencia = encontrarSubsecuencia(vector);

	std::cout << secuencia.suma << " " << secuencia.ini << " " << secuencia.longitud << std::endl;

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