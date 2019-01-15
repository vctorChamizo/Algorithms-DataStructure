// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

struct tCaja {

	int n;
	int t = 0;

	bool operator < (tCaja const & c) const { return t < c.t || (t == c.t && n < c.n); }
};

bool resuelveCaso() {

	int n, c;
	std::cin >> n >> c;

	if (n == 0) return false;

	PriorityQueue<tCaja> cajas;

	for (int i = 1; i <= n; ++i) {

		tCaja caja;
		caja.n = i;
		cajas.push(caja);
	}

	int tiempo_cliente;
	tCaja caja_mod;

	for (int j = 0; j < c; ++j) {

		std::cin >> tiempo_cliente;
		caja_mod = cajas.top();
		cajas.pop();

		caja_mod.t += tiempo_cliente;
		cajas.push(caja_mod);
	}

	std::cout << cajas.top().n << std::endl;
	
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