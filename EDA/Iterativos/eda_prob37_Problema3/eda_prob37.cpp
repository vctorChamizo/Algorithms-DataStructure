// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


bool resolver(std::vector<int> & v, int p) {

	int max = v[0];
	int min = v[p + 1];

	int i;

	for (i = 1; i <= p; ++i) 
		if (v[i] > max) max = v[i];
	
	for (i = p + 1; i < v.size(); ++i) 
		if (v[i] < min) min = v[i];
	

	if (min > max) return true;
	else return false;
}


void resuelveCaso() {

	int nElem, p, n;

	std::cin >> nElem >> p;

	std::vector<int> vector(nElem);

	for (int & n : vector) std::cin >> n;

	bool res = true;

	if (p < vector.size() - 1) res = resolver(vector, p);

	if (res) std::cout << "SI";
	else std::cout << "NO";

	std::cout << std::endl;
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