// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>

#include "library.h"

bool resuelveCaso() {

	int n_operations;
	std::cin >> n_operations;

	if (!std::cin) return false;

	std::string operation, name_book;
	char c;
	int n_books;

	library library;

	for (int i = 0; i < n_operations; ++i) {

		std::cin >> operation;

		try {

			if (operation == "nuevoLibro") {

				std::cin >> n_books;
				std::cin.get(c);
				std::getline(std::cin, name_book);

				library.new_book(n_books, name_book);
			}
			else if (operation == "comprar") {

				std::cin.get(c);
				std::getline(std::cin, name_book);

				library.buy_book(name_book);
			}
			else if (operation == "estaLibro") {

				std::cin.get(c);
				std::getline(std::cin, name_book);

				if (library.has_book(name_book)) std::cout << "El libro " << name_book << " esta en el sistema";
				else std::cout << "No existe el libro " << name_book << " en el sistema";

				std::cout << std::endl << "---" << std::endl;
			}
			else if (operation == "elimLibro") {

				std::cin.get(c);
				std::getline(std::cin, name_book);

				library.delete_book(name_book);
			}
			else if (operation == "numEjemplares") {

				std::cin.get(c);
				std::getline(std::cin, name_book);

				try {

					int n = library.copies_book(name_book);

					std::cout << "Existen " << n << " ejemplares del libro " << name_book;
				}
				catch (std::invalid_argument e) { std::cout << "No existe el libro " << name_book << " en el sistema"; }

				std::cout << std::endl << "---" << std::endl;
			}
			else if (operation == "top10") {

				std::list<std::string> list_books = library.get_top_ten();

				for (auto const & l : list_books) std::cout << l << std::endl;

				std::cout << "---" << std::endl;
			}
			else std::cout << "OPERACION DESCONOCIDA";
		}
		catch (std::out_of_range e) { std::cout << e.what() << std::endl << "---" << std::endl; }
		catch (std::invalid_argument e) { std::cout << e.what() << std::endl << "---" << std::endl; }
	}

	std::cout << "------" << std::endl;

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