// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

const int COLORES = 3;

bool esValida(std::vector<std::string> const & vSol, int k, int contR, int nR, int contA, int nA, int contV, int nV) { 
	
	if (vSol[0] != "rojo") return false;
	if (vSol[k] == "verde" && vSol[k] == vSol[k - 1]) return false;
	if (contV > contA) return false;
	if (k == vSol.size() - 1 && contR <= contA + contV) return false;
	if (nA < contA || nR < contR || nV < contV) return false;

	return true; 
}


bool esSolucion(int alturaTorre, int k) { return k == alturaTorre; }

/*

Identificadores de colores:
	AZUL = 0
	ROJO = 1
	VERDE = 2
*/
void resolver(std::vector<std::string> & vSol, int k, int contR, int nR, int contA, int nA, int contV, int nV, bool & imposible) {

	for (int i = 0; i < COLORES; ++i) {

		if (i == 0) { vSol[k] = "azul"; contA++; }
		if (i == 1) { vSol[k] = "rojo"; contR++; }
		if (i == 2) { vSol[k] = "verde"; contV++; }

		if (esValida(vSol, k, contR, nR, contA, nA, contV, nV)) {

			if (!esSolucion(vSol.size() - 1, k))  resolver(vSol, k + 1, contR, nR, contA, nA, contV, nV, imposible);
			else {

				imposible = true;

				for (int j = 0; j < vSol.size(); ++j)
					std::cout << vSol[j] << " ";

				std::cout << std::endl;
			}
		}

		if (i == 0) { contA--; }
		if (i == 1) { contR--; }
		if (i == 2) { contV--; }
	}
}


bool resuelveCaso() {

	int alturaTorre;

	std::cin >> alturaTorre;

	if (alturaTorre < 1)
		return false;

	int azul, rojo, verde;

	std::cin >> azul >> rojo >> verde;

	std::vector<std::string> vectorSolucion(alturaTorre);

	bool imposible = false;

	resolver(vectorSolucion, 0, 0, rojo, 0, azul, 0, verde, imposible);

	if (!imposible) std::cout << "SIN SOLUCION" << std::endl;

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