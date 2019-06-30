// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "Conjunto.h"

bool resuelveCaso() {

	char elem;
	int K;
	std::cin >> elem >> K;

	if (!std::cin) return false;

	if (elem == 'N') {

		int n;
		set<int> s;
		std::cin >> n;

		while (n != -1) {

			if (!s.contains(n)) {

				if (!s.isFullToLimit(K))s.insert(n);
				else if (n > s.getMin()) {

					s.removeMin();
					s.insert(n);
				}
			}
			
			std::cin >> n;
		}

		std::cout << s.getElem(0);
		for (int i = 1; i < s.getContador(); ++i) std::cout << ' ' << s.getElem(i);
	}
	else if (elem == 'P'){

		std::string p;
		set<std::string> s;
		std::cin >> p;

		while (p != "FIN") {

			if (!s.contains(p)) {

				if (!s.isFullToLimit(K))s.insert(p);
				else if (p > s.getMin()) {

					s.removeMin();
					s.insert(p);
				}
			}

			std::cin >> p;
		}

		std::cout << s.getElem(0);
		for (int i = 1; i < s.getContador(); ++i) std::cout << ' ' << s.getElem(i);
	}

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