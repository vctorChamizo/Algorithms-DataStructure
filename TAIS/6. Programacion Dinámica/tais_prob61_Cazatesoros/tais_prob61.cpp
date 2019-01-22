// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS 58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

void cantidadOro(int T, int N, std::vector<int> const & t, std::vector<int> const & o, int & c_oro, std::vector<bool> & cofres, int & cantidadCofres) {

	Matriz<int> c(N + 1, T + 1, 0);

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= T; ++j) {

			if (t[i] > j) c[i][j] = c[i - 1][j];

			else c[i][j] = std::max(c[i - 1][j], c[i - 1][j - t[i]] + o[i]);
		}

	c_oro = c[N][T];

	int resto = T;
	for (int i = N; i >= 1; --i) {

		if (c[i][resto] == c[i - 1][resto]) cofres[i] = false;
		else {
			cofres[i] = true;
			cantidadCofres++;
			resto = resto - t[i];
		}
	}
}

bool resuelveCaso() {

	int T;
	std::cin >> T;

	if (!std::cin) return false;

	int N;
	std::cin >> N;

	std::vector<int> profundidad(N + 1);
	std::vector<int> tiempo(N + 1);
	std::vector<int> oro(N + 1);
	int p;

	for (int i = 1; i <= N; ++i) {

		std::cin >> p;
		profundidad[i] = p;
		tiempo[i] = p + 2 * p;

		std::cin >> oro[i];
	}

	int c_oro;
	std::vector<bool> cofres(N + 1);
	int cantidadCofres = 0;
	
	cantidadOro(T, N, tiempo, oro, c_oro, cofres, cantidadCofres);

	if (c_oro == 0) std::cout << 0 << ' ' << 0 << std::endl;
	else {

		std::cout << c_oro << std::endl << cantidadCofres << std::endl;

		for (int j = 1; j <= N; ++j) if (cofres[j]) std::cout << profundidad[j] << " " << oro[j] << std::endl;
	}
		
	std::cout << "----" << std::endl;

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