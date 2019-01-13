#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

/*
	EXPLICACIÓN:
		
		Para resolver este problema hemos usado la técnica divide y vencerás.

		Hemos realizado la division del vector y la elecciÓn de la parte a seguir estudiando atendiendo
		a la premisa de que si el elemento observado al hacer la división es más grande que el elemento x, 
		el valor que mas cercano estará a él se situará a la izquierda del vector, ya que esta ordenado de forma
		creciente.

		Una vez llegado al caso base en el que nos encontramos con los dos elementos mas cercanos al elemento x,
		comparamos ambos para decidir cuál es el más cercano.


	ECUACIÓN DE RECURRENCIA:

					c0					n == 1
		T (n) = {	c0					n == 2
					T(n / 2) + c1		n > 2


	DESPLIEGUE:
		
		T(n) = T(n / 2) + c1 = T(n / 2^2) + c1 + c1 = ... = T(n / 2^k) + c1*k = T(1) + log(n) + c1


	COSTE:
		
		O(n) --> siendo n el numero de elementos del vector.
*/

int resolver(std::vector<int> const & v, int x, int ini, int fin) {

	if (ini == fin) return v[ini];
	else if (ini + 1 == fin) {

		if (abs(v[ini] - x) <= abs(v[fin] - x)) return v[ini];
		else return v[fin];
	}
	else {

		int m = (ini + fin) / 2;

		if (v[m] > x) return resolver(v, x, ini, m);
		else return resolver(v, x, m, fin);
	}
}


void resuelveCaso() {

	int x, n;
	std::vector<int> v(n);

	std::cin >> x >> n;
	for (int & k : v) std::cin >> k;

	std::cout << resolver(v, x, 0, v.size() - 1) << std::endl;
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