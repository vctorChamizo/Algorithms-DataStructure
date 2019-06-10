// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:

		Para resolver este problema se ha usado una estrategia voraz que consiste en ordenar los
		pesos de menor a mayor de tal forma que sumamos el mas mayor de ellos mas el menor para minimizar
		el numero de viajes que obtendrá el telesilla. Si la suma es superior al peso maximo entonces,
		el viaje solo lo podrá realziar el usuario con el peso maoyor, ya que al ser sumado con el peso mas
		pequeño es imposible que pueda realizar el viaje con otro usuario.

	COSTE TOTAL:

		O(n) -> siendo n el número de usuario que quieren realizar el viaje en el telesilla.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

int min_trips(std::vector<int> const & v, int p) {

	int trips = 0;

	int i = 0;
	int j = v.size() - 1;

	while (i <= j) {

		if (v[i] + v[j] <= p) i++;

		j--;
		trips++;
	}

	return trips;
}

bool resuelveCaso() {

	int p;
	std::cin >> p;

	if (!std::cin) return false;

	int n; 
	std::cin >> n;

	std::vector<int> v(n);

	for (auto & e : v) std::cin >> e;

	std::sort(v.begin(), v.end());

	std::cout << min_trips(v, p) << std::endl;

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