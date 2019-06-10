// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:
	
		Para solucionar este problema se ha usado una estrategia voraz que consiste en ordenar ambos vectores
		de menor a mayor para ir comparando entre ellos e ir iterando según es necesario en cada uno de ellos.


	COSTE TOTAL :
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

int min_buy(std::vector<int> const & v_p, std::vector<int> const & v_s) {

	int min = 0, j = 0, i = 0;

	while (i < v_p.size() && j < v_s.size()) {

		if (v_p[i] == v_s[j] || v_p[i] + 1 == v_s[j]) {

			i++;
			j++;
		}
		else if (v_p[i] < v_s[j]) {

			i++;
			min++;
		}
		else j++;
	}

	return v_p.size() - i + min;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (!std::cin) return false;

	int m;
	std::cin >> m;

	std::vector<int> v_players(n);
	std::vector<int> v_sizes(m);

	for (auto & p : v_players) std::cin >> p;
	for (auto & s : v_sizes) std::cin >> s;

	std::sort(v_players.begin(), v_players.end());
	std::sort(v_sizes.begin(), v_sizes.end());

	std::cout << min_buy(v_players, v_sizes) << std::endl;

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