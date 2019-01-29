/*
	COSTE:

		O(n) --> siendo n el numero de elementos del vector.

		Este orden de complejidad se da ya que solo se recorre el vector una vez  independientemente del
		tamaño de los datos.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

bool escaleraCreciente(std::vector<int> const & v) {

	int escalonAnterior = 0, escalonActual = 1, anterior = v[0];

	for (int i = 1; i < v.size(); ++i) {

		if (v[i] == anterior) escalonActual++;
		else {

			if (escalonActual < escalonAnterior) return false;

			anterior = v[i];
			escalonAnterior = escalonActual;
			escalonActual = 1;
		}
	}

	if (escalonActual < escalonAnterior) return false;
	else return true;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<int> v(n);

	for (int & k : v) std::cin >> k;

	if (escaleraCreciente(v)) std::cout << "SI";
	else std::cout << "NO";

	std::cout << std::endl;
	
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