// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

// función que resuelve el problema
bool resolver(const bintree<char>& arbol, int& altura) {

	if (arbol.empty()) {
		
		altura = 0;
		return true;
	}
	else if (arbol.left().empty() && arbol.right().empty()){
		
		altura = 1;
		return true;
	}
	else {

		int altL, altR;

		bool equL = resolver(arbol.left(), altL);
		bool equR = resolver(arbol.right(), altR);

		altura = std::max(altL, altR) + 1;

		if ((abs(altL - altR) <= 1) && equL && equR) return true;
		else return false;
	}
}
/*Alternativa de solucion:
	Controla el desiquilibrio del arbol saliendo de la función,
	evitando el recorrido completo del árbol.
*/
/*bool resolver(const bintree<char>& arbol, int& altura) {

	if (arbol.empty()) {
		
		altura = 0;
		return true;
	}
	else if (arbol.left().empty() && arbol.right().empty()) {

		altura = 1;
		return true;
	}
	else {

		int altL, altR;

		bool equL = resolver(arbol.left(), altL);

		if (equL) {

			bool equR = resolver(arbol.right(), altR);

			altura = std::max(altL, altR) + 1;

			if (equL && equR && (abs(altL - altR) <= 1)) return true;
			else return false;
		}
		else return false;
	}
}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	
	bintree <char> arbol;
	int altura;

	arbol = leerArbol('.');
	
	bool sol = resolver(arbol, altura);

	if (sol) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}