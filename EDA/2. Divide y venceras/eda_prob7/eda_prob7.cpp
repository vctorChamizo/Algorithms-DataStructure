// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

/*
El problema se resuelve com el esquema algorítmico Divide y Vencerás.

Los casos base que se comprueban son:
	- El vector tiene un solo elemento.
	- El vector tiene dos elementos.
	
De ser asi se hacen las comparaciones neceserias (numero cantado + posicion = v[posion]).

En caso contrario, el vector se parte por la mitad y pueden ocurrir dos cosas:
	- El elemento central cumple la condición.
	- Se determina cual de las dos partes (izquierda o derecha) ha de ser revisada de forma recursiva.
	
Este interrogante se resulve comprobando si el numero cantado mas la poscion central es menor o mayor que
el valor del mismo.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int tacharNumero(std::vector<int> const& v, int c, int ini, int fin) {

	if (ini == fin) {

		if (c + ini == v[fin]) return v[fin];
		else return -1;
	}
	else if (ini + 1 == fin) {

		if (c + ini == v[ini]) return v[ini];
		else if (c + fin == v[fin]) return v[fin];
		else return -1;
	}
	else {

		int m = (ini + fin) / 2;

		if (c + m == v[m]) return v[m];
		else if (c + m < v[m]) return tacharNumero(v, c, ini, m - 1);
		else return tacharNumero(v, c, m + 1, fin);
	}
}


void resuelveCaso() {

	int nElem, nCantado;

	std::cin >> nElem >> nCantado;

	std::vector<int> carton(nElem);

	for (int i = 0; i < carton.size(); ++i)
		std::cin >> carton[i];

	int tachado = tacharNumero(carton, nCantado, 0, carton.size() - 1);

	if (tachado != -1) std::cout << tachado << std::endl;
	else std::cout << "NO" << std::endl;
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