// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <set>

/*
	Para resolver el problema se utiliza dos diccionarios para comprobar las diferentes actualizaciones de cada uno.

	El resultado se obtiene almacenando de la información de los diccionarios en 3 conjuntos diferentes: 
	
	   - Conjunto 1: refleja las nuevas claves que se han introducido en el nuevo diccionario.
	   - Conjunto 2: relfeja las claves que se han eliminado del antiguo diccionario.
	   - Conjunto 3: refleja los valores que se han modifcado en claves existentes en ambos diccionarios.

	Estos resultados son obtenidos a traves de una iteraación por cada uno de los diccioanrios, en la cual, se compara con el
	otro para obtener dicho resultado.
*/

using chain = std::string;
using number = int;

void upgrade_map(std::unordered_map<chain, number> old_map, std::unordered_map<chain, number> new_map, std::set<chain> & new_key, std::set<chain> & delete_key, std::set<chain> & upgrade_key) {

	for (auto it_old = old_map.begin(); it_old != old_map.end(); ++it_old) {

		// Si es mayor que cero -> las claves coinciden --> no se ha borrado ninguna clave del nuevo diccionario.
		if (new_map.count(it_old->first) > 0 && it_old->second != new_map.at(it_old->first)) upgrade_key.insert(it_old->first);

		// Si es igual a cero -> las claves no coinciden --> se ha borrado una clave del nuevo diccionario.
		else if (new_map.count(it_old->first) == 0) delete_key.insert(it_old->first);
	}

	for (auto it_new = new_map.begin(); it_new != new_map.end(); ++it_new) if (old_map.count(it_new->first) == 0) new_key.insert(it_new->first);
}

void resuelveCaso() {

	int value;
	std::string key;
	std::unordered_map<chain, number> old_map;
	std::unordered_map<chain, number> new_map;
	std::set<chain> new_key, delete_key, upgrade_key;

	std::string line;
	std::getline(std::cin, line);
	std::stringstream ss_1(line);

	while (ss_1 >> key) {

		ss_1 >> value;

		old_map[key] = value;
	}

	std::getline(std::cin, line);
	std::stringstream ss_2(line);

	while (ss_2 >> key) {

		ss_2 >> value;

		new_map[key] = value;
	}

	upgrade_map(old_map, new_map, new_key, delete_key, upgrade_key);

	if (new_key.empty() && delete_key.empty() && upgrade_key.empty()) std::cout << "Sin cambios" << std::endl;
	else {

		if (!new_key.empty()) {

			std::cout << "+ ";

			for (auto it_new = new_key.begin(); it_new != new_key.end(); ++it_new) std::cout << *it_new << " ";

			std::cout << std::endl;
		}

		if (!delete_key.empty()) {

			std::cout << "- ";

			for (auto it_delete = delete_key.begin(); it_delete != delete_key.end(); ++it_delete) std::cout << *it_delete << " ";

			std::cout << std::endl;
		}

		if (!upgrade_key.empty()) {

			std::cout << "* ";

			for (auto it_upgrade = upgrade_key.begin(); it_upgrade != upgrade_key.end(); ++it_upgrade) std::cout << *it_upgrade << " ";
		
			std::cout << std::endl;
		}
	}

	std::cout << "----" << std::endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	std::cin.ignore();
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}