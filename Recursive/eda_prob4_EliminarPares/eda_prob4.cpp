// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

/*
EL problema se resuelve mediante recursividad no final, eliminado los números
pares de la secuencia y guardando las posiciones que les corresponderá a los 
numeros impares cuando se estén reconstryendo el nuevo número a la vuelta de las
funcioens llamadas.
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>


long long int eliminarPares(long long int n, long long int potencia) {

	if (n / 10 == 0) {

		if (n % 2 != 0) return n * potencia;
		else return 0;
	}
	else if (n % 2 != 0) {

		long long int pot = potencia;

		int aux = n % 10;

		potencia = potencia * 10;

		long long int numero = eliminarPares(n / 10, potencia);

		return numero + (aux * pot);
	}
	else return eliminarPares(n / 10, potencia);
}


bool resuelveCaso() {

	long long int numero;

	std::cin >> numero;

	if (!std::cin) return false;

	long long int potencia = 1;

	long long int nSinPares = eliminarPares(numero, potencia);

	std::cout << nSinPares << std::endl;

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

