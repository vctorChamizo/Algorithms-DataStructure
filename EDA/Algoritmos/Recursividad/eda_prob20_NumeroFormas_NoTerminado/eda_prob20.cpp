// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int calcularPosibilidades(std::vector<int> const & v, std::vector<std::vector<int>> & m, int cant) {

	if (cant == 0) return m[][]
}


bool resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	if (!std::cin) return false;

	int cantidad;

	std::cin >> cantidad;

	std::vector<int> vector(nElem);

	for (int & n : vector) std::cin >> n;

	std::vector<std::vector<int>> matriz(nElem + 1, std::vector<int>(nElem + 1));

	int posibilidades = calcularPosibilidades(vector, matriz, cantidad);

	std::cout << posibilidades << std::endl;

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