
/*




*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct tAnchura {

	int primero;
	int ultimo;
	int ancho = 0;
};

void encontrarEscalera(std::vector<int> const & v, tAnchura & anch, int ini, int fin, int primero, int ultimo, int & max) {

	int anchPrimeroAux;
	int anchUltimoAux;

	if (ini == fin) { // Solo hay un elemento

		anch.primero = anch.ultimo = anch.ancho = 1;
	}
	else if (ini + 1 == fin) { // Hay dos elementos

		if (v[ini] == v[fin]) anch.primero = anch.ultimo = anch.ancho = 2;
		else anch.primero = anch.ultimo = anch.ancho = 1;
	}
	else {

		int m = (ini + fin) / 2;

		if (v[m] == primero && v[m + 1] != primero) {

			anch.primero = m + 1;
			if (v[m + 1] == ultimo) anch.ultimo = v.size() - (m + 1); 
		}
		else if (v[m] == ultimo && v[m - 1] != ultimo) {

			anch.ultimo = v.size() - m;
			if (v[m - 1] == primero) anch.primero = m - 1;
		}
		else {

			if (v[m + 1] == ultimo && v[m - 1] == primero) {

				anch.primero = m;
				anch.ultimo = v.size() - (m + 1);

				anch.ancho = std::max(anch.primero, anch.ultimo);
			}
		}

	}
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<int> vector(n);
	tAnchura anchuras;
	int max = 0;

	for (int & v : vector) std::cin >> v;
	
	if (vector[0] == vector[vector.size() - 1]) anchuras.primero = anchuras.ultimo = anchuras.ancho = vector.size();
	else encontrarEscalera(vector, anchuras, 0, vector.size() - 1, vector[0], vector[vector.size() - 1], max);

	std::cout << anchuras.primero << " " << anchuras.ultimo << " " << anchuras.ancho << std::endl;

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