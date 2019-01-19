// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

struct tOrquesta {

	int nPartitura  = 1;
	int nInstrumentos;

	bool operator < (tOrquesta const & o) const {

		int actual = nInstrumentos / nPartitura;
		if (nInstrumentos % nPartitura != 0) actual++;

		int entrante = o.nInstrumentos / o.nPartitura;
		if (o.nInstrumentos % o.nPartitura != 0) entrante++;

		return actual > entrante;
	}
};

int repartirPartituras(PriorityQueue<tOrquesta> & q, int p) {

	tOrquesta orquesta;

	for (int i = 0; i < p; ++i) {

		orquesta = q.top();
		q.pop();

		orquesta.nPartitura++;
		q.push(orquesta);
	}

	int grupoMayor = q.top().nInstrumentos / q.top().nPartitura;
	if (q.top().nInstrumentos % q.top().nPartitura != 0) grupoMayor++;

	return grupoMayor;
}

bool resuelveCaso() {

	int partituras, n;
	std::cin >> partituras >> n;

	if (!std::cin) return false;

	PriorityQueue<tOrquesta> q;
	tOrquesta orquesta;

	for (int i = 0; i < n; ++i) {

		std::cin >> orquesta.nInstrumentos;
		q.push(orquesta);
	}
	
	/*
		Restamos el numero de intrumentos distintos al numero total de partituras porque sabemos que
		como minimo cada grupo tendrá una partitura.
	*/
	partituras -= n;

	// Si todavia hay partituras para repartir...
	if (partituras > 0) std::cout << repartirPartituras(q, partituras);
	else std::cout << q.top().nInstrumentos;

	std::cout << std::endl;

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