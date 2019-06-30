// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <ctype.h>
#include <vector>
#include <algorithm>

/*
	Para resolver el problema se utilizan dos diccionarios y un vector en e cual se almacena la solucion.

	El resultado se calcula registrando en uno de los diccionarios, cada deporte como clave y los alumnos apuntados a dicho deportes
	como un conjuto de sus identificadores. Para el otro diccionario, se realiza la operación inversa: se registra como clave el nombre
	del alumno y su valor es un conjunto de los deportes en los que se ha inscrito el alumno.

	Al ser diccionarios, si un alumno se ha apunado varias veces en un mismo deporte, este no se registra automaticamente, puesto que 
	los diccionarios no almacenan valores repetidos con una misma clave. Para controlar que un alumno no este inscrito en varios deportes,
	se filtra a traves del segundo diccionario explicado.
*/

using name_sport = std::string;
using id_student = std::string;

struct tSport {

	std::string name;
	int n_students;

	tSport(std::string n, int n_s) : name(n), n_students(n_s) {}
};

class comparator {

public:

	bool operator () (tSport const & s1, tSport const & s2) { return s1.n_students > s2.n_students || (s1.n_students == s2.n_students) && s1.name < s2.name; }
};

bool resuelveCaso() {

	std::string word, sport, student;
	std::getline(std::cin, word);

	if (!std::cin) return false;

	std::map<name_sport, std::set<id_student>> sport_map; // Registra cada deporte con los alumnos apuntados al mismo.
	std::map<id_student, std::set<name_sport>> student_map; // Registra los deportes en los que cada alumno se ha inscrito.

	while (word != "_FIN_") {

		// Si es un deporte -> actulizamos el mapa de deportes
		if (isupper(word[0])) {

			sport = word;
			sport_map[sport];

			std::getline(std::cin, word);

			// Mientras que sea un alumno y no llegue al fin -> actulizamos los dos diccionarios con sus respectivos datos.
			while (!isupper(word[0]) && word != "_FIN_") {

				student = word;

				sport_map[sport].insert(student);
				student_map[student].insert(sport);

				std::getline(std::cin, word);
			}
		}
	}

	std::vector<tSport> sport_list;

	for (auto const & s : sport_map) {

		int n_students = 0;

		// Para cada uno de los estudiantes inscritos en cada deporte -> 
		// se comprueba que dicho estudiante solo este inscrito en un deporte
		for (auto it = s.second.begin(); it != s.second.end(); ++it) if (student_map[*it].size() == 1) n_students++;
		
		sport_list.push_back({ s.first, n_students });
	}

	// Ordenamos en orden decreciente de alumnos apuntados en cada deporte.
	std::sort(sport_list.begin(), sport_list.end(), comparator());

	for (auto const & l : sport_list ) std::cout << l.name << " " << l.n_students << std::endl;

	std::cout << "***" << std::endl;

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