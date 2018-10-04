// Nombre del alumno: Victor Chamizo Rodriguez
// Usuario del Juez: E12

/*
El programa se resuelve aplicando recursividad no final, mediante el metodo de la
multiplicacion del campesino egipcio.

Dependiendo de si el numero es par o impar, realizamos un tipo de operación sobre
la descomposicion del número u otra.
*/

#include <iostream>
#include <iomanip>
#include <fstream>


long long int resolverMultiplicacion(long long int a, long long int b) {

	if (b == 0) return 0;
	else if (b == 1) return a;
	else if (b % 2 == 0) return resolverMultiplicacion(2 * a, b / 2);
	else return resolverMultiplicacion(2*a, b / 2) + a;
}


void resuelveCaso() {

	long long int op1, op2;
	
	long long int producto = resolverMultiplicacion(op1, op2);

	std::cout << producto << astd::endl;
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