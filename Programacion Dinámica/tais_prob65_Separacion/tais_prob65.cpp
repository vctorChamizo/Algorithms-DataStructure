// Nombre del alumno: V�ctor Chamizo Rodr�guez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>

bool resuelveCaso() {

	if (!std::cin) return false;

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