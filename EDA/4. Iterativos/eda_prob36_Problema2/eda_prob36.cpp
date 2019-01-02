// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: EDA12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


void EstricCreciente(std::vector<int> & v) {

	int aux = 0;

	for (int i = 0; i < v.size(); ++i) {

		if (v[i] % 2 == 0) {
			
			v[aux] = v[i];
			aux++;
		}
	}

	v.resize(aux);
}


void resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	std::vector<int> vector(nElem);

	for (int &  n: vector) std::cin >> n;

	EstricCreciente(vector);

	if (vector.size() > 0) std::cout << vector[0];
	for (int i = 1; i < vector.size(); ++i)
		std::cout << ' ' << vector[i];
	std::cout << '\n';
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