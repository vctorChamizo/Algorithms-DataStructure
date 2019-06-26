// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

#include"Matriz.h"

void patindromo(std::string const& w, std::vector<bool> & f_w) {

	int n = w.size() - 1;

	Matriz<int> matrix(w.size(), w.size(), 0);

	// Inicializamos la diagonal principal con 1
	for (int i = 0; i < w.size(); ++i) matrix[i][i] = 1;
	
	int j;

	for (int d = 1; d <= n; ++d) // recorre diagonales
		for (int i = 0; i <= n - d; ++i) { // recorre elementos de diagonal

			j = i + d;

			if (w[i] == w[j]) matrix[i][j] = (matrix[i + 1][j - 1]) + 2;
			else matrix[i][j] = std::max(matrix[i][j - 1], matrix[i + 1][j]);
		}

	int k = 0;
	int z = n;

 	while (k < n && z > 0 && k <= z) {

		if (w[k] == w[z]) {

			f_w[k] = true; ++k;
			f_w[z] = true; --z;
		}
		else if (matrix[k][z] == matrix[k + 1][z]) ++k;
		else if (matrix[k][z] == matrix[k][z - 1]) --z;
	}
}

bool resuelveCaso() {

	std::string word;
	std::cin >> word;

	if (!std::cin) return false;

	std::vector<bool> final_word(word.size(), false);

	patindromo(word, final_word);

	for (int i = 0; i < final_word.size(); ++i) if (final_word[i]) std::cout << word[i];

	std::cout << std::endl;

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