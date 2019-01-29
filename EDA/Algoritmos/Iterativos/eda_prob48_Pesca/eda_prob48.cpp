// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int pesca(std::vector< std::vector<int> > const & m, int c) {

	int max = 0;
	int suma;

	for (int i = 0; i <= m.size() - c; ++i)
		for (int j = 0; j <= m[0].size() - c; ++j) {

			suma = 0;

			for (int k = i; k < (i + c); ++k)
				for (int z = j; z < (j + c); ++z)
					suma += m[k][z];

			if (max < suma) max = suma;
		}
			
	return max;
} 


bool resuelveCaso() {

	int nCuadrantes;
	std::cin >> nCuadrantes;

	if (!std::cin) return false;

	int cuadrantePesca;
	std::vector< std::vector<int> > matriz (nCuadrantes, std::vector<int>(nCuadrantes));

	std::cin >> cuadrantePesca;
	for (int i = 0; i < nCuadrantes; ++i)
		for (int j = 0; j < nCuadrantes; ++j)
			std::cin >> matriz[i][j];

	std::cout << pesca (matriz, cuadrantePesca) << std::endl;

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