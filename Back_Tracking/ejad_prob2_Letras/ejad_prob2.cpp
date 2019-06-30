// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez:

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool esValida (std::vector<char> const & vSol, int k, int n) {

	if (k > 0 && (vSol[k] == vSol[k - 1] || vSol[k] < vSol[k - 1])) return false;

	return true;
}

bool esSolucion(int m, int k) { return m == k; }


void resolver(std::vector<char> vSol, int k, int n) {

	for (char i = 'a'; i < ('a' + n); ++i) {

		vSol[k] = i;

		if (esValida(vSol, k, n)) {

			if (!esSolucion(vSol.size() - 1, k)) resolver(vSol, k + 1, n);
			else {

				for (int j = 0; j < vSol.size(); ++j)
					std::cout << vSol[j];

				std::cout << std::endl;
			}
		}

		vSol[k] = 0;
	}
}

bool resuelveCaso() {

	int n;

	std::cin >> n;

	if (!std::cin)
		return false;

	int m;

	std::cin >> m;

	std::vector<char> vectorSolucion(m);

		resolver(vectorSolucion, 0, n);

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