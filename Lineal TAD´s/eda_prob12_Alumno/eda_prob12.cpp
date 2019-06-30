// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

bool resuelveCaso() {

	int N, M;
	std::cin >> N >> M;
	if (N == 0 && M == 0) return false;

	std::queue<int> cola;
	for (int i = 1; i <= N; ++i) cola.push(i);

	int aux;
	while (cola.size() > 1) {

		for (int i = 0; i < M; ++i) {

			aux = cola.front();
			cola.pop();
			cola.push(aux);
		}

		cola.pop();
	}

	std::cout << cola.front() << std::endl;

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