#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using tMatriz = std::vector<std::vector<int>>;

bool esValida(std::vector<int> const & anchM, std::vector<int> const & anchN, int i, int k) { return anchM[k] <= anchN[i]; }

bool esSolucion(int i, int k) { return k == i; }

void resolver(std::vector<int> const & anchM, std::vector<int> const & anchN, std::vector<bool> & roadMarked,
	tMatriz const & calds, int & caldMax, int caldAux, int k) {

	/*
		k --> maquinas
		i --> carreteras
	*/
	for (int i = 0; i < anchN.size(); ++i) {

		if (!roadMarked[i]) {

			caldAux += calds[k][i];
			roadMarked[i] = true;

			if (esValida(anchM, anchN, i, k)) {

				if (!esSolucion(anchM.size() - 1, k)) resolver(anchM, anchN, roadMarked, calds, caldMax, caldAux, k + 1);
				else if (caldAux > caldMax) caldMax = caldAux;
			}

			caldAux -= calds[k][i];
			roadMarked[i] = false;
		}
	}

}


void resuelveCaso() {

	int m, n;
	
	std::cin >> m >> n;

	std::vector<int> anchurasM(m);
	std::vector<int> anchurasN(n);
	tMatriz calidades(m, std::vector<int>(n));

	for (int & aM : anchurasM) std::cin >> aM;
	for (int & aN : anchurasN) std::cin >> aN;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> calidades[i][j];

	int calidadMaxima = 0;
	std::vector<bool> carrertraConMaquina(n, false);

	resolver(anchurasM, anchurasN, carrertraConMaquina, calidades, calidadMaxima, 0, 0);

	std::cout << calidadMaxima << std::endl;
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