// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez:


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


const int SABORES = 2;


bool esValida(std::vector<char> & vSol, int k, int nC, int contC, int nV, int contV) {

	if (vSol.size() <= 2 && k > 0 && vSol[k] == vSol[k - 1]) return false;
	if (contC > nC || contV > nV) return false;

	return true;
}


bool esSolucion(int max, int k) { return max == k; }


/*
	Identififcacion de sabores:
		- CHOCOLATE = 0
		- VAINILLA = 1
*/
void resolver(std::vector<char> & vSol, int k, int nC, int contC, int nV, int contV) {

	for (auto i = 0; i < SABORES; ++i) {

		if (i == 0) { vSol[k] = 'C'; contC++; }
		if (i == 1) { vSol[k] = 'V'; contV++; }

		if (esValida(vSol, k, nC, contC, nV, contV)) {

			if (!esSolucion(vSol.size() - 1, k)) resolver(vSol, k + 1, nC, contC, nV, contV);
			else {
				for (auto j = 0; j < vSol.size(); ++j)
					std::cout << vSol[j];

				std::cout << " ";
			}
		}

		vSol[k] = 0;
		if (i == 0) contC--;
		if (i == 1) contV--;
	}
}


void resuelveCaso() {

	int nChocolate, nVainilla;

	std::cin >> nChocolate >> nVainilla;

	std::vector<char> vectorSolucion(nChocolate + nVainilla);

	resolver(vectorSolucion, 0, nChocolate, 0, nVainilla, 0);

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