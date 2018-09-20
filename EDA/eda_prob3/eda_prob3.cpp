// Nombre del alumno Víctor Chamizo Rodríguez
// Usuario del Juez E12


#include <iostream>
#include <iomanip>
#include <fstream>


struct tInverso {

	int numero;
	int pot;
};

// función que resuelve el problema
tInverso invertir(int n) {

	tInverso invertido;

	if (n / 10 == 0) {

		invertido.numero = n;
		invertido.pot = 10;
		
		return invertido;
	}
	else {

		int aux = n % 10;

		invertido = invertir(n / 10);

		invertido.numero = (aux * invertido.pot) + invertido.numero;
		invertido.pot = invertido.pot * 10;

		return invertido;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int n;

	std::cin >> n;

	if (!std::cin) return false;

	tInverso sol = invertir(n);

	std::cout << sol.numero << std::endl;

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