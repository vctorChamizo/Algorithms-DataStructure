// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


/*
El problema se resuelve aplicando el esquema algoritmico Divide y Vencerás.

Antes de la llamada a la función que resuleve el problema comprobamos los casos base
en los que el numero impar este en uno de los extremos del vector.

En el caso de que no se cumplan las premisas anteriores, la función divide el vector en dos
recursivamente hasta encontrar el numero impar comprobando los consecutivos.
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


/*
Recurrencia: T(n) = T(n/2) + C

Coste: O(log(n)): sea cual se el tamaño de datos, dividimos el vector por la mitad en cada llamada.
*/
int encontrarImpar(std::vector<int> const& v, int ini, int fin) {

	if (ini == fin) return v[ini];
	else if (ini + 1 == fin) {

		if (v[ini] % 2 == 0) return v[fin];
		else return v[ini];
	}
	else {

		int m = (ini + fin) / 2;

		if (v[m] % 2 != 0) return v[m];
		else if (v[ini] + (m - ini) * 2 != v[m]) return encontrarImpar(v, ini, m - 1);
		else return encontrarImpar(v, m + 1, fin);
	}
}


bool resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	if (nElem == 0)
		return false;

	std::vector<int> vector(nElem);

	for (int i = 0; i < vector.size(); ++i) 
		std::cin >> vector[i];

	int impar;

	if (vector[0] % 2 != 0) impar = vector[0];
	else if (vector[vector.size() - 1] % 2 != 0) impar = vector[vector.size() - 1];
	else impar = encontrarImpar(vector, 0, vector.size() - 1);

	std::cout << impar << std::endl;

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