// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector <std::vector <int >>;

int calcularCombinatorio(int n, int m, std::vector<std::vector<int>> & matriz) {

	if (m == 0 || m == n) return matriz[n][m] = 1;
	else if (m == 1 || m == n - 1) return matriz[n][m] = n;
	else {
		if (matriz[n - 1][m - 1] == -1) matriz[n - 1][m - 1] = calcularCombinatorio(n - 1, m - 1, matriz);
		if (matriz[n - 1][m] == -1) matriz[n - 1][m] = calcularCombinatorio(n - 1, m, matriz);
		return matriz[n][m] = matriz[n - 1][m - 1] + matriz[n - 1][m];
	}
}

bool resuelveCaso() {

	int n, m;

	std::cin >> n >> m;

	if (!std::cin) return false;

	tMatriz matriz(n + 1, std::vector <int >(m + 1, -1));

	std::cout << calcularCombinatorio(n, m, matriz) << std::endl;

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