// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;

struct tFib {

	lli n1;
	lli n2;
};

tFib sucesionFibonacci(int n) {

	tFib fib;

	if (n == 0) fib.n1 = fib.n2 = 0;
	else if (n == 1) {

		fib.n1 = 1;
		fib.n2 = 0;
	}
	else {
	
		fib = sucesionFibonacci(n - 1);
		lli aux = fib.n2;
		fib.n2 = fib.n1;
		fib.n1 = aux + fib.n1;
	}

	return fib;
}


bool resuelveCaso() {
	
	int n;

	std::cin >> n;

	if (!std::cin) return false;

	tFib f = sucesionFibonacci(n);

	std::cout << f.n1 << std::endl;

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