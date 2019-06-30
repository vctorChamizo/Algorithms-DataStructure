// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	FUNCION:

		max_subsequence(i, j) = encontrar subsecuencia mas larga de las palabras formadas con letras de la
								1 a la i y de la de 1 a la j.


	CASOS BASE:
		
		max_subsequence(0, j) = 0 -> si la palabra formada por las letras de la 1 a la i es vacia no hay subsecuencia.

		max_subsequence(i, 0) = 0 -> si la palabra formada por las letras de la 1 a la j es vacia no hay subsecuencia.


	FUNCION RECURSIVA:
								
									max_subsequence(i - 1, j - 1) + 1								si p1i == p2j
		max_subsequence(i, j) = {
									max(max_subsequence(i - 1, j), max_subsequence(i, j - 1))		si p1i != p2j
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>
#include <algorithm>

#include "Matriz.h"

int max_subsequence(std::string const & word_1, std::string const & word_2) {

	Matriz<int> matrix(word_1.size() + 1, word_2.size() + 1, 0);

	for (int i = 1; i <= word_1.size(); ++i)
		for (int j = 1; j <= word_2.size(); ++j) {

			if (word_1[i - 1] == word_2[j - 1]) matrix[i][j] = matrix[i - 1][j - 1] + 1;
			else matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
		}

	return matrix[word_1.size()][word_2.size()];
}

bool resuelveCaso() {

	std::string word_1, word_2;
	std::cin >> word_1 >> word_2;

	if (!std::cin) return false;

	std::cout << max_subsequence(word_1, word_2) << std::endl;

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