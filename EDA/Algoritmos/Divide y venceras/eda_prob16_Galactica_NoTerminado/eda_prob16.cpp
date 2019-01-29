// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


//Como vamos a modificar el vector no lo pasamos como referencia constante
int calcularTiempo(std::vector<int> & v, int ini, int fin) {

	return 0;
}


bool resuelveCaso() {

	int nNaves;

	std::cin >> nNaves;

	if (!std::cin)
		return false;

	std::vector<int> flota(nNaves);

	for (int i = 0; i < flota.size(); ++i)
		std::cin >> flota[i];

	int movimientos = calcularTiempo(flota, 0, flota.size() - 1);

	std::cout << movimientos << std::endl;

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