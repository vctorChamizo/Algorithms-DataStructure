// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <stack>

long long int cochesMuelle(std::list<std::string> const & lista_matriculas, std::stack<std::string> & coches_esperando) {

	long long int cont = 0;
	std::stack<std::string> coches_muelle;

	auto it = lista_matriculas.cbegin();

	while (it != lista_matriculas.cend()) {

		while (!coches_esperando.empty()) {

			if (coches_esperando.top() == *it) it++;
			else {

				while (!coches_muelle.empty() && coches_muelle.top() == *it) {

					coches_muelle.pop();
					it++;
				}

				if (coches_esperando.top() == *it) it++;
				else {

					coches_muelle.push(coches_esperando.top());
					cont++;
				}
			}

			coches_esperando.pop();
		}

		while (!coches_muelle.empty() && coches_muelle.top() == *it) {

			coches_muelle.pop();
			it++;
		}

		while (!coches_muelle.empty()) {

			coches_esperando.push(coches_muelle.top());
			coches_muelle.pop();
		}
	}

	return cont;
}

bool resuelveCaso() {

	long long int N;
	std::cin >> N;

	if (!std::cin) return false;

	std::list<std::string> lista_matriculas;
	std::stack<std::string> coches_llegada;
	std::string c;

	for (long long int i = 0; i < N; ++i) {

		std::cin >> c;
		lista_matriculas.push_back(c);
	}

	for (long long int j = 0; j < N; ++j) {

		std::cin >> c;
		coches_llegada.push(c);
	}

	std::cout << cochesMuelle(lista_matriculas, coches_llegada) << std::endl;

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