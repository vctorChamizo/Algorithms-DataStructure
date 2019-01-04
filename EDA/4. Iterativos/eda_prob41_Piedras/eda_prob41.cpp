// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };

std::istream& operator >> (std::istream& entrada, piedrasPreciosas& p) {

	char num;
	std::cin >> num;

	switch (num) {

		case 'd': p = diamante; break;
		case 'r': p = rubi; break;
		case 'e': p = esmeralda; break;
		case 'z': p = zafiro; break;
		case 'j': p = jade; break;
	}

	return entrada;
}

int numeroSequencias(std::vector<piedrasPreciosas> const & v, int t, 
	int np1, piedrasPreciosas p1, int np2, piedrasPreciosas p2) {

	int aux_recorrido, contP1, contP2;
	int cont = 0;

	for (int i = 0; i <= v.size() - t; ++i) {

		aux_recorrido = i + t;
		contP1 = contP2 = 0;

		for (int j = i; j < aux_recorrido; ++j) {

			if (v[j] == p1) contP1++;
			else if (v[j] == p2) contP2++;
		}

		if (contP1 >= np1 && contP2 >= np2) cont++;
	}

	return cont;
}

void resuelveCaso() {

	int numPiedras, tamSeq, nPiedra1, nPiedra2;
	piedrasPreciosas piedra1, piedra2;

	std::cin >> numPiedras >> tamSeq >> piedra1 >> nPiedra1 >> piedra2 >> nPiedra2;

	std::vector<piedrasPreciosas> piedras(numPiedras);

	for (auto & p : piedras) std::cin >> p;

	int seq = numeroSequencias(piedras, tamSeq, nPiedra1, piedra1, nPiedra2, piedra2);

	std::cout << seq << std::endl;
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