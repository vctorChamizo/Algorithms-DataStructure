// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>

#include "age_filter.h"
#include "Person.h"


bool resuelveCaso() {

	int N, min_age, max_age;
	std::cin >> N >> min_age >> max_age;

	if (N == 0 && min_age == 0 && max_age == 0) return false;

	age_filter predicate(min_age, max_age);

	Person person;
	std::list <Person> list_person;
	for (int i = 0; i < N; ++i) {

		std::cin >> person;
		list_person.push_back(person);
	}

	auto it_actual = list_person.begin();
	while (it_actual != list_person.end()) {

		if (!predicate(*it_actual)) it_actual = list_person.erase(it_actual);
		else it_actual++;
	}

	for (auto & elem : list_person) std::cout << elem.get_name() << std::endl;

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