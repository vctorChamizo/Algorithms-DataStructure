// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int encontrarFranjas(std::vector< std::vector<int> > const & m, int k, int y, int x) {

	int cont;
	
	std::vector<int> vAux (m[0].size());

	for (int j = 0; j < m[0].size(); ++j) {

		cont = 0;

		for (int i = 0; i < m.size(); ++i) {
			if (m[i][j] == 0) cont++;
		}
			
		vAux[j] = cont;
	}
		
	int tope;
	int contCol;
	int contFranja = 0;

	for (int i = 0; i <= vAux.size() - k; ++i) {

		tope = i + k;
		contCol = 0;

		for (int j = i; j < tope; ++j) {

			if (vAux[j] >= x) contCol++;
		}

		if (contCol >= y) contFranja++;
	}
		
	return contFranja;
}


bool resuelveCaso() {

	int f, c, k, y, x;

	std::cin >> f >> c >> k >> y >> x;

	if (!std::cin) return false;

	std::vector< std::vector<int> > matriz (f, std::vector<int>(c));

	for (int i = 0; i < f; ++i)
		for (int j = 0; j < c; ++j) 
			std::cin >> matriz[i][j];

	int n = encontrarFranjas(matriz, k, y, x);

	std::cout << n << std::endl;

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