// Nombre del alumno: V�ctor Chamizo Rodr�guez
// Usuario del Juez: TAIS58

/*
	EXPLICACI�N:

		Para solucionar el problema se ha utilizado una estrategia voraz en la que se recorre el vector
		en el que est�n reflejados las posiciones de los agujeros que tiene la manguera.
		
		Por tanto, el primer agujero siempre debe llevar un parche. Para el resto de agujeros, si la posicion
		actual del agujero menos la posici�n del ultimo agujero en en el que se puso el parche es mayor que la
		longitud del parche, se debe a�dir un nuevo parche.


	COSTE TOTAL:

		O(n) -> siendo n el n�mero de agujeros que contiene la manguera.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

int calculate_patchs(std::vector<int> const & v, int l) {

	int n_patchs = 1;

	int pos_last_patch = v[0];

	for (int i = 1; i < v.size(); ++i) {

		if (v[i] - pos_last_patch > l) {

			n_patchs++;
			pos_last_patch = v[i];
		}
	}

	return n_patchs;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (!std::cin) return false;

	int l;
	std::cin >> l;

	std::vector<int> v(n);

	for (auto & e : v) std::cin >> e;

	std::cout << calculate_patchs(v, l) << std::endl;

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