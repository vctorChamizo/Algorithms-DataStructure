// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:
		
		Para solucionar este problema se ha usado una estrategia voraz, en la que se ordenan las alturas de los
		esquiadores y las longitudes de los esquis de menor a maoyor en sus respectivos vectores, para así
		sumar las diferencias entre los que estén en las mismas posiciones, ya que serán las minimas al estar ordenados
		de mayor a menor.


	COSTES:
	
		- Coste de ordenar el vector -> O(log(n)) siendo n el numero de elementos del vector.


	COSTE TOTAL:
	
		O(n * log(n)) -> siendo n el número de esquiadores.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

int calculate_min_sub(std::vector<int> const & v_skrs, std::vector<int> const & v_sks, int n) {

	int sum_sub = 0;

	for (int i = 0; i < n; ++i) sum_sub += std::abs(v_skrs[i] - v_sks[i]);

	return sum_sub;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<int> v_skiers(n);
	std::vector<int> v_skies(n);

	for (auto & k : v_skiers) std::cin >> k;
	for (auto & e : v_skies) std::cin >> e;

	std::sort(v_skiers.begin(), v_skiers.end());
	std::sort(v_skies.begin(), v_skies.end());

	std::cout << calculate_min_sub(v_skiers, v_skies, n) << std::endl;

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