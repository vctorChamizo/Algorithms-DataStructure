// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>

/*
	Para resolver el problema se utiliza un diccionario para calcular la puntuación de cada alumno.

	Clave: nombre del alumno.
	Valor: puntuación de cada alumno.

	El resultado se calcula incrementando en uno la puntuación si el resultado es CORRECTO o disminuyendo
	en uno si el resultado es INCORRECTO.
*/

using name_student = std::string;
using point = int;

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::map<name_student, point> map;
	std::string space, n_s, p;

	// Lee cada uno de los datos de los alumos y actualiza el diccionario.
	for (int i = 0; i < n; ++i) {

		std::getline(std::cin, space); // Elimina el final de la linea.
		std::getline(std::cin, n_s);
		std::cin >> p;

		if (p == "CORRECTO") ++map[n_s];
		else --map[n_s];
	}

	// Muestra los resultados.
	for (auto const & m : map) if (m.second != 0) std::cout << m.first << ", " << m.second << std::endl;

	std::cout << "---" << std::endl;
	
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