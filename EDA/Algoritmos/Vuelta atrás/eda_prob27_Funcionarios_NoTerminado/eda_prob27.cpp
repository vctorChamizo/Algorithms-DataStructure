// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#define INF 1000000000

using tMatriz = std::vector<std::vector<int>>;

bool esValida(std::vector<bool> & vMark, int i) {

	if (vMark[i]) return false; // Si el funcionario esta ocupado
	return true;
}

bool esSolucion(int i, int k) { return i == k; }

int encontrarOptimo(tMatriz const & m, std::vector<bool> & vMark,
	int & tMin, int tAcum, int k) {

	/*
		k --> trabajo a realizar.
		i --> funcionario que realiza el trabajo
	*/
	for (int i = 0; i < vMark.size(); ++i) {

		tAcum += m[i][k];

		if (esValida(vMark, i)) {

			vMark[i] = true;
			
			if (!esSolucion(vMark.size() - 1, k)) encontrarOptimo(m, vMark, tMin, tAcum, k + 1);
			else tMin = std::min(tAcum, tMin);
		}
		
		tAcum -= m[i][k];
		vMark[i] = false;
	}

	return tMin;
}


bool resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	if (nElem == 0) return false;

	tMatriz matriz(nElem, std::vector<int>(nElem));
	std::vector<bool> vectorMarcado(nElem, false);
	int tiempoMinimo = INF;

	for (int i = 0; i < nElem; ++i)
		for (int j = 0; j < nElem; ++j)
			std::cin >> matriz[i][j];

	std::cout << encontrarOptimo(matriz, vectorMarcado, tiempoMinimo, 0, 0) << std::endl;

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