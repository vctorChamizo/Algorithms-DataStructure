// Nombre del alumno Víctor Chamizo Rodríguez
// Usuario del Juez E12

/*
El problema es resuelto aplicando el esquema algorítmico Divide y Vencerás.

Antes de llamar a la función que aplicará es esquema se analiza el caso base de
que el vector solo tuviese un elemento, siendo asi este, el minimo.

Una vez llamada a la función, esta dividirá el vector en dos para comprbar si su centro es menor
que el elemento que tiene a la derecha y a la izquierda, puesto que al ser una curva cóncava, cuando esta
condición se cumpla, se habra encontrado el valor minimo de dicha curva.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


int encontrarMinimo(std::vector<int> const& v, int ini, int fin) {

	if (ini + 1 == fin) return std::min(v[ini], v[fin]);
	else {

		int m = (ini + fin) / 2;

		if (v[m] < v[m - 1] && v[m] < v[m + 1]) return v[m];
		else if (v[m] < v[m - 1]) return encontrarMinimo(v, m, fin);
		else return encontrarMinimo(v, ini, m);
	}
}


bool resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	if (!std::cin)
		return false;

	std::vector<int> vector;

	int elem, cont = 0;

	while (cont < nElem) {

		std::cin >> elem;
		vector.push_back(elem);

		cont++;
	}

	/*
	std::vector<int> vector(nElem);

	for (int i = 0; i < vector.size(); ++i)
		std::cin >> vector[i];
	*/
	
	int minimo;

	if (vector.size() == 1) minimo = vector[0];
	else minimo = encontrarMinimo(vector, 0, vector.size() - 1);
	
	std::cout << minimo << std::endl;

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