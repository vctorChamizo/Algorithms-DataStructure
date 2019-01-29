// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int encontrarDistintos(std::vector<int> const& v, int ini, int fin) {

	if (ini == fin) return 1; //1 elemento en el array
	else if (ini + 1 == fin) { //2 elementos en el array

		if (v[ini] == v[fin]) return 1; //si ambos elementos son iguales
		else return 2; //si son distintos
	}
	else { //si hay 3 elementos o mas

		int m = (ini + fin) / 2;

		int contIz = encontrarDistintos(v, ini, m);
		int contDch = encontrarDistintos(v, m + 1, fin);

		int contParcial = contIz + contDch;

		if (v[m] == v[m + 1]) contParcial--;

		return contParcial;
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

	int nDistintos = encontrarDistintos(vector, 0, vector.size() - 1);

	std::cout << nDistintos << std::endl;

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