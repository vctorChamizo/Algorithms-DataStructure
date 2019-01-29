// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>


long int calcularComplemetario(long int n, long int p, int c){

	if (n == 0) return c;
	else return  calcularComplemetario(n / 10, p * 10, (9 - (n % 10)) * p + c);
}


long int obtenerInverso(int n, int i) {

	if (n == 0) return i;
	else if (i == 0) return obtenerInverso(n / 10, 9 - (n % 10));
	else return obtenerInverso(n / 10, (i * 10) + (9 - (n % 10)));
}


void resuelveCaso() {

	long int numero;

	std::cin >> numero;

	if (numero == 0) std::cout << 9 << ' ' << 9;
	else {

		long int complementario = calcularComplemetario(numero, 1, 0);
		long int inverso = obtenerInverso(numero, 0);

		std::cout << complementario << ' ' << inverso;
	}
	
	std::cout << std::endl;
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