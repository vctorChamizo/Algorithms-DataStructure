#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int tramosMaximos(std::vector<int> const & v) {

	int anterior = v[0];
	int max = 1;
	int max_aux = 1;

	for (int i = 1; i < v.size(); ++i) {

		if (v[i] <= anterior) {

			max_aux++;

			if (max < max_aux) max = max_aux;
		}
		else max_aux = 1;

		anterior = v[i];
	}

	return max;
}

void resuelveCaso() {

	int n; 
	std::cin >> n;

	std::vector<int> alturas(n);
	for (int & a : alturas) std::cin >> a;

	std ::cout << tramosMaximos(alturas) << std::endl;
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