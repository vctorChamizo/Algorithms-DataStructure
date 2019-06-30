// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>

#include "ipud.h"

bool resuelveCaso() {

	std::string funcion;
	std::cin >> funcion;

	if (!std::cin) return false;

	std::string cancion, artista;
	int duracion;

	ipud ipud;

	while (funcion != "FIN") {
		try {

			if (funcion == "addSong") {

				std::cin >> cancion >> artista >> duracion;

				ipud.addSong(cancion, artista, duracion);
			}
			else if (funcion == "addToPlaylist") {

				std::cin >> cancion;

				ipud.addToPlaylist(cancion);
			}
			else if (funcion == "current") ipud.current();
			else if (funcion == "play") {

				std::string c = ipud.play();

				if (c.size() == 0) std::cout << "No hay canciones en la lista";
				else std::cout << "Sonando " << c;

				std::cout << std::endl;
			}
			else if (funcion == "totalTime") std::cout << "Tiempo total " << ipud.totalTime() << std::endl;
			else if (funcion == "recent") {

				int n;
				std::cin >> n;

				std::list<std::string> lista_canciones = ipud.recent(n);

				if (lista_canciones.size() == 0) std::cout << "No hay canciones recientes" << std::endl;
				else {

					std::cout << "Las " << lista_canciones.size() << " mas recientes" << std::endl;
					for (auto const & l_c : lista_canciones) std::cout << "    " << l_c << std::endl;
				}
			}
			else if (funcion == "deleteSong") {

				std::cin >> cancion;

				ipud.deleteSong(cancion);
			}
		} 
		catch (std::domain_error e) { std::cout << "ERROR " << e.what() << std::endl; }
		catch (std::invalid_argument e) { std::cout << "ERROR " << e.what() << std::endl; }

		std::cin >> funcion;
	}

	std::cout << "----" << std::endl;

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
