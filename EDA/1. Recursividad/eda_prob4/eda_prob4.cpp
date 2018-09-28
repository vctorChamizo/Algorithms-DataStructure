// Nombre del alumno Víctor Chamizo Rodríguez
// Usuario del Juez E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>


// función que resuelve el problema
long long int resolver(long long int n, long long int potencia) {

	if (n / 10 == 0) {

		if (n % 2 != 0) return n * potencia;
		else return 0;
	}
	else if (n % 2 != 0) {

		long long int pot = potencia;

		int aux = n % 10;

		potencia = potencia * 10;

		long long int numero = resolver(n / 10, potencia);

		return numero + (aux * pot);
	}
	else return resolver(n / 10, potencia);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	long long int n;

	std::cin >> n;

	if (!std::cin) return false;

	long long int potencia = 1;

	long long int sol = resolver(n, potencia);

	std::cout << sol << std::endl;

	return true;
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}

