// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIIS58

/*
	EXPLICACIÓN:

		Para resolver el problema se ha utilizado una estrategia voraz que consiste en ordenar de mayor
		a menor ambos vectores. De esta forma e iterando con sobre los enemiegos sabremos el numero de victorias
		que obtendrán los aliados comprando con su número de efectivos.

	COSTE TOTAL:

		O(n) -> siendo n el número de ciudades.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

int max_victories(std::vector<int> const & v_a, std::vector<int> const & v_e) {

	int victories = 0;
	int i = 0;

	for (auto const & e : v_e) {

		if (e <= v_a[i]) {

			victories++;
			i++;
		}
	}

	return victories;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (!std::cin) return false;

	std::vector<int> v_enemies(n);
	std::vector<int> v_allies(n);
	
	for (auto & e : v_enemies) std::cin >> e;
	for (auto & a : v_allies) std::cin >> a;
	
	std::sort(v_enemies.begin(), v_enemies.end(), std::greater<int>());
	std::sort(v_allies.begin(), v_allies.end(), std::greater<int>());

	std::cout << max_victories(v_allies, v_enemies) << std::endl;

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