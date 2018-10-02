// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

/*
El problema se resuelve de forma recursiva no final, descomponiendo el 
numero en cada llamada que se hace a la función y conviertiendolo en 0 o 1
dependiendo de si es par o impar.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


std::string convertirABinario(long long int n) {

	if (n == 0) return "0";
	else if (n == 1) return "1";
	else return convertirABinario(n / 2) + char('0' + n % 2);
}


void resuelveCaso() {
	
	long long int entero;
	std::cin >> entero;

	std::string binario = convertirABinario(entero);
	
	std::cout << binario << std::endl;
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