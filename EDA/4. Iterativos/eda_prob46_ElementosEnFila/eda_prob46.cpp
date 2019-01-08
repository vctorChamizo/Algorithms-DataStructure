// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int encontrarNuemeros(std::vector< std::vector<int> > const & m) {

	int cont = 0;

	for (int i = 0; i < m.size(); ++i)
		for (int j = 0; j < m[0].size(); ++j) 
			if (m[i][j] == i) cont++;
		
	return cont;
}


bool resuelveCaso() {

	int f, c;

	std::cin >> f >> c;

	if (!std::cin) return false;

	std::vector< std::vector<int> > matriz (f, std::vector<int>(c));

	for (int i = 0; i < f; ++i)
		for (int j = 0; j < c; ++j) 
			std::cin >> matriz[i][j];

	int n = encontrarNuemeros(matriz);

	std::cout << n << std::endl;

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