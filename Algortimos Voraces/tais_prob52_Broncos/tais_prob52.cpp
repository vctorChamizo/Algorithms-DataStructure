// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:

		Este problema se resuelve aplicando una estrategia voraz en la que los patidos jugados por 
		los rivales son ordenador de menor a mayor mientras que los partidos jugados por los Broncos
		son ordenados de mayor a menor de tal forma que se maximice la diferencia de los partidos ganados por
		los broncos, ya que en caso de no tener una diferencia mayor a cero, esta no se sumaria.

	COSTES:
	
		- Coste de ordenar el vector -> O(log(n)) siendo n el numero de elementos del vector.


	COSTE TOTAL:
	
		O(n * log(n)) -> siendo n el número de partidos jugados.
*/
 
#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

int calculate_max_sub(std::vector<int> const & v_b, std::vector<int> const & v_r, int n) {

	int max_sub = 0, sub_aux;

	for (int i = 0; i < n; ++i) {

		sub_aux = v_b[i] - v_r[i];

		if (sub_aux > 0) max_sub += sub_aux;
	}

	return max_sub;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<int> v_rivals(n);
	std::vector<int> v_broncos(n);
	
	for (auto & r : v_rivals) std::cin >> r;
	for (auto & b : v_broncos) std::cin >> b;
	
	std::sort(v_rivals.begin(), v_rivals.end());
	std::sort(v_broncos.begin(), v_broncos.end(), std::greater<int>());

	std::cout << calculate_max_sub(v_broncos, v_rivals, n) << std::endl;

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