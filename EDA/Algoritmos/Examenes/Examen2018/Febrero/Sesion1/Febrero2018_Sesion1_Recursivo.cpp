// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

/*
	EXPLICACIÓN:

		El problema se resuelve usando la técnica de Divide y Vencerás.

		En primer lugar se comprueba que tanto el primer elemento del vector como el ultimo, no son impares,
		de ser asi el problema habria acabado.

		Una vez divido el vector debemos decidir cual de las dos partes analizar. Esto se resuelve atendiendo 
		a la logica de que, si los elementos del vector se suponen pares y consecutivos, si restamos la posicion del
		vector en la que nos encontramos multiplicada por dos, al elemento en el que nos encontramos, nos deberia dar
		el mismo valor que la posicion de inicio de ese sector del vector, de no ser asi, sabemos que hay un numero
		que no cuadra, en este caso, elemento impar que estamos buscando.


	FUNCIÓN DE RECURRENCIA:
		
				  c0				n = 1
		T(n) = {  c0				n = 2
				  T(n/2) + c1		n > 2	

	DESPLIEGUE:

		T(n) = T(n / 2) + c1 = T(n / 2^2) + c1 + c1 = T(n / 2^k) + (c1 * k) = T(1) + log(n) * c1

	COSTE:

		O(log(n)) --> siendo n el numeor de elementos del vector.
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector<int> const & v, int ini, int fin) {

	if (ini == fin) return v[ini];
	else if (ini + 1 == fin) {

		if (v[ini] % 2 == 0) return v[fin];
		else return v[ini];
	}
	else {

		int m = (ini + fin) / 2;

		if (v[m] % 2 != 0) return v[m];
		else if (v[m] - (2 * m) != v[ini]) return resolver(v, ini, m - 1);
		else return resolver(v, m + 1, fin);
	}
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<int> v(n);
	int impar;

	for (int & e : v) std::cin >> e;
	
	if (v[0] % 2 != 0) impar = v[0];
	else if (v[v.size() - 1] % 2 != 0) impar = v[v.size() - 1];
	else impar = resolver(v, 0, v.size() - 1);

	std::cout << impar << "\n";

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