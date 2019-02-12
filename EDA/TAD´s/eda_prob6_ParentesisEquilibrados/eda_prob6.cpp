// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "stack_eda.h"

bool esEquilibrado(std::string const & linea) {

	stack<char> pila;
	int nAbiertos = 0, nCerrados = 0;

	for (char l : linea) {

		if (l == '(' || l == '[' || l == '{') {

			pila.push(l);
			nAbiertos++;
		}
		else if (l == ')' || l == ']' || l == '}') {

			nCerrados++;
			if (pila.empty()) return false;

			switch (l) {

				case ')': if (pila.top() != '(') return false; break;
				case ']': if (pila.top() != '[') return false; break;
				case '}': if (pila.top() != '{') return false; break;
			}

			pila.pop();
		}
	}

	return nAbiertos == nCerrados;
}

bool resuelveCaso() {

	std::string linea;
	getline(std::cin, linea);

	if (!std::cin) return false;

	if (esEquilibrado(linea)) std::cout << "SI";
	else std::cout << "NO";

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