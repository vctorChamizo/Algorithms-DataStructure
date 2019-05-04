// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <ctype.h>
#include <algorithm>

/*
	Para resolver el problema se utiliza un diccionario para almacenar las diferentes referencias y sus respectivas posiciones
	en el texto.

	Clave: palabra de referencia.
	Valor: conjunto que almacena las distintas lineas en las que aparece en el texto.

	El resultado se calcual almacenando las diferentes palabras (sin repetir) en el diccionario y actualizando el conjunto
	que contiene como valor de la linea que le corresponde en el texto. Dicha linea se va calculando con el indice del bucle que
	controla las diferentes lineas de las que se compone el texto.
*/

/*
	Convierte la palabra que le llega como referencia en una palabra compuesta unicamente por letras minusculas.
*/
void to_lower(std::string & w) { std::transform(w.begin(), w.end(), w.begin(), ::tolower); }

using reference = std::string;
using lines = std::set<int>;

bool resuelveCaso() {

	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::cin.ignore();

	std::string line, word;
	std::map<reference, lines> map;

	for (int i = 1; i <= N; ++i) {

		std::getline(std::cin, line);
		std::stringstream ss(line);

		while (ss >> word) {

			if (word.length() > 2) {

				to_lower(word);

				map[word].insert(i); // Insertamos en el conjunto de la clave que le definimos.
			}
		}
	}

	for (auto const & m : map) {

		std::cout << m.first << " ";

		int last = *(--m.second.cend());

		for (auto const& v : m.second) {

			std::cout << v;

			if (last != v) std::cout << " ";
		}

		std::cout << std::endl;
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