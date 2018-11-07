// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esvalida(std::vector<int> const & vSol, int k, int d, int e) {

	if (vSol[0] != e) return false;
	if (k > 0) {

		if (vSol[k] - vSol[k - 1] > 1) return false;
		if (vSol[k] < vSol[k - 1]) return false;
		if (k >= d && vSol[k] == vSol[k - d]) return false;
	}
	
	return true;
}

bool esSolucion(int vMax, int k) { return k == vMax; }

void resolver(std::vector<int> & vSol, int k, int d, int e) {

	for (int i = e; i <= vSol.size(); ++i) {

		vSol[k] = i;

		if (esvalida(vSol, k, d, e)) {

			if (!esSolucion(vSol.size() - 1, k)) resolver(vSol, k + 1, d, e);
			else {

				for (int j = 0; j < vSol.size(); ++j)
					std::cout << vSol[j];

				std::cout << std::endl;
			}
		}

		vSol[k] = 0;
	}
}

void resuelveCaso() {

	int n, d, e;

	std::cin >> n >> d >> e;

	std::vector<int> vectorSolucion(n);

	resolver(vectorSolucion, 0, d, e);

	std::cout << std::endl;
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}