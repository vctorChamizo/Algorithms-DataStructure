// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>

#include <algorithm>

#include "Matriz.h"

void game_table(int N, Matriz<int> const & m, int & sum, int & pos) {

	Matriz<int> m_aux(N + 2, N + 2, 0);
	int k;

	for (k = 1; k <= N; ++k) m_aux[1][k] = m[1][k];

	for (int i = 2; i <= N; ++i)
		for (int j = 1; j <= N; ++j) m_aux[i][j] = m[i][j] + std::max(m_aux[i - 1][j - 1], std::max(m_aux[i - 1][j], m_aux[i - 1][j + 1]));

	for (k = 1; k <= N; ++k) 
		if (sum < m_aux[N][k]) {

			sum = m_aux[N][k];
			pos = k;
		}
}

bool resuelveCaso() {

	int N;
	std::cin >> N;

	if (!std::cin) return false;

	Matriz<int> matrix(N + 1, N + 1, 0);

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) std::cin >> matrix[i][j];

	int max_sum = 0, pos_begin;

	game_table(N, matrix, max_sum, pos_begin);

	std::cout << max_sum << ' ' << pos_begin << std::endl;
		
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