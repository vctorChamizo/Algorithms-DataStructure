// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool comprobarCaucasico(std::vector<int> const & v, int ini, int fin, int & cont) {

	if (ini == fin) {

		if (v[ini] % 2 == 0) cont++;
		return true;
	}
	else if (ini + 1 == fin) {

		if (v[ini] % 2 == 0) cont++;
		if (v[fin] % 2 == 0) cont++;

		return true;
	}
	else {

		int m = (ini + fin) / 2;

		bool esCIzq, esCDch;
		int contIzq = 0, contDch = 0;

		esCIzq = comprobarCaucasico(v, ini, m, contIzq);

		if (esCIzq) esCDch = comprobarCaucasico(v, m + 1, fin, contDch);
		else return false;

		if (esCDch && std::abs(contIzq - contDch) <= 2) {
			cont = contIzq + contDch;
			return true;
		}
		
		return false;
	}
}


bool resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	if (nElem == 0) return false;

	std::vector<int> vector(nElem);

	for (int & n : vector) std::cin >> n;

	int contador = 0;

	bool esCaucasico = comprobarCaucasico(vector, 0, vector.size() - 1, contador);

	if (esCaucasico) std::cout << "SI";
	else std::cout << "NO";

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