// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


struct tPelicula {

	int comienzo;
	int fin;

	bool operator < (tPelicula & p) const { return fin < p.fin; }
};


int maximoPeliculas(std::vector<tPelicula> const & p) {

	int nP = 1;

	int fin_aux = p[0].fin + 10;

	for (auto i = 1; i < p.size(); ++i) {

		if (p[i].comienzo >= fin_aux) {

			nP++;
			fin_aux = p[i].fin + 10;
		}
	}

	return nP;
}


bool resuelveCaso() {

	int nPeliculas;

	std::cin >> nPeliculas;

	if (nPeliculas == 0) return false;

	char puntos;
	int horas, minutos, duracion;
	tPelicula pelicula;
	std::vector<tPelicula> peliculas(nPeliculas);

	for (auto i = 0; i < nPeliculas; ++i) {

		std::cin >> horas >> puntos >> minutos >> duracion;
		pelicula.comienzo = (horas * 60) + minutos;
		pelicula.fin = pelicula.comienzo + duracion;
		peliculas[i] = pelicula;
	}

	std::sort(peliculas.begin(), peliculas.end());
		
	int maximo = maximoPeliculas(peliculas);

	std::cout << maximo << std::endl;

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