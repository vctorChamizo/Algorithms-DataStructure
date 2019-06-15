// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:

		Para resolver este problema se ha usado una estrategia voraz en la que se han ordenado
		de menor a mayor las peliculas emitidas segun se momento de finalización, ya que así, se
		duspone del tiempo maximo para visualizar las peliculas.

		De esta forma, si la pelicual actual tiene un comienzo superior al fin de la ultima pelicula vista
		el numero de peliculas vistas aumenta en uno y se actualiza el fin de la ultima pelicula vista.

	
	COSTES:
	
		- Coste de ordenar el vector -> O(log(n)) siendo n el numero de elementos del vector.


	COSTE TOTAL:
	
		O(n * log(n)) -> siendo n el número de peliculas emitidas.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

struct tMovie {

	int begin;
	int end;

	tMovie() {}

	tMovie(int b, int e) : begin(b), end(e) {}

	bool operator < (tMovie const & m) const { return end < m.end; }
};

int max_movies(std::vector<tMovie> const & v) {

	int movies = 1;
	int aux_end = v[0].end + 10;

	for (int i = 1; i < v.size(); ++i) {

		if (v[i].begin >= aux_end) {

			movies++;

			aux_end = v[i].end + 10;
		}
	}

	return movies;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<tMovie> v(n);
	int h, m, d;
	char p;

	for (int i = 0; i < n; ++i) {

		std::cin >> h >> p >> m >> d;

		v[i] = { (h * 60) + m, (h * 60) + m + d };
	}

	std::sort(v.begin(), v.end());

	std::cout << max_movies(v) << std::endl;

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