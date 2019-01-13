// Nombre del alumno Víctor Chamizo Rodríguez
// Usuario del Juez E12

/*
El problema es resuelto aplicando el esquema logaritmico Divide y Vencerás

Debido a que los elementos del vector en un principio estan ordenador de forma descendente pero han
sido modificados por rotaciones, para hayar el mínimo debemos encontrar diviendo el vector
en dos mediante llamadas recursivas el elemento que cumpla que tanto su elementos siguiente como su 
elemento anterior, sean mayores que el mismo.

Para decantarnos por un lado u otro del vector cuando hacemos la división, seguimos la premisa de que si
el elemento inicial de ese sector del vector es menor que el elemento central de dicho sector, el minimo
debe estar en la parte izquierda del vector, debido a que en un principio están ordenados de forma descendente.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


int calcularMinimo(std::vector<int> const& v, int ini, int fin) {

	if (ini == fin) return v[ini];
	else if (ini + 1 == fin) return std::min(v[ini], v[fin]);
	else {

		int m = (ini + fin) / 2;

		if (v[m] < v[m - 1] && v[m] < v[m + 1]) return v[m];
		else if (v[m] > v[ini]) return calcularMinimo(v, ini, m - 1);
		else return calcularMinimo(v, m + 1, fin);
	}
}


bool resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	if (!std::cin)
		return false;

	std::vector<int> vector(nElem);

	for (int i = 0; i < vector.size(); ++i) 
		std::cin >> vector[i];

	int minimo = calcularMinimo(vector, 0, vector.size() - 1);

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