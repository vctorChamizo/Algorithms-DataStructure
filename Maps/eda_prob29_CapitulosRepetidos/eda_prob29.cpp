// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <algorithm>

/*
	Para resolver el problema se utiliza un diccionario para calcular el maximo de días consecutivos sin repetición de capítulos.

	Clave: número del capítulo.
	Valor: posición en la que el capítulo ha salido

	El resultado se calcula actulizando el diccionario con el día en el que ha aparecido el capítulo actual
	y actualizando el número máximo de dichos días.
*/

using n_chapter = int;
using position = int;

bool resuelveCaso() {

	if (!std::cin) return false;

	std::unordered_map<n_chapter, position> map;
	int max_days = 1, days = 0;
	int n_chapters, chapter;

	std::cin >> n_chapters;

	for (int i = 0; i < n_chapters; ++i) {

		std::cin >> chapter;
			
		// Si el capítulo ya se ha emitido.
		if (map.count(chapter) != 0) { 

			if (i - map[chapter] <= days) days = i - map[chapter];
			else days++;
		}
		// Si aún no se ha emitido, se aumentan los días consecutivos sin repeticiones.
		else days++;

		//Actualizamos el día en que se ha emitido el capítulo y se actualiza el maximo.

		map[chapter] = i;

		max_days = std::max(days, max_days);
	}

	std::cout << max_days << std::endl;

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}