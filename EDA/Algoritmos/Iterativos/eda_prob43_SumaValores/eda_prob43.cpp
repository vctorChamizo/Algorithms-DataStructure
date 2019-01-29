// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int SumaNoMaximo(std::vector<int> const & v) {

	int max = v[0];
	int contMax = 1;
	int sum = 0;

	for (int i = 1; i < v.size(); ++i) {

		if (v[i] > max) {
			sum += max * contMax;
			contMax = 1;
			max = v[i];
		}
		else if (v[i] == max) contMax++;
		else sum += v[i];
	}

	return sum;
}


void resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	std::vector<int> vector (nElem);

	for (int & v : vector) std::cin >> v;

	int suma = SumaNoMaximo(vector);

	std::cout << suma << std::endl;
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