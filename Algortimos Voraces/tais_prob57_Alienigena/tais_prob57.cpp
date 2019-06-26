// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*
	EXPLICACIÓN:
	
		Para solucionar este problema se ha usado una estrategia voraz que consiste en ordenar los trabajos
		de menor a mayor segun su momento de inicio.
		
		** Comentarios en el código **
	
	
	COSTES:
	
		- Coste de ordenar el vector -> O(log(n)) siendo n el numero de elementos del vector.


	COSTE TOTAL:
	
		O(n * log(n)) -> siendo n el número de trabajos.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

struct tWork {

	int begin;
	int end;

	tWork() {}

	tWork(int b, int e) : begin(b), end(e) {}

	bool operator < (tWork const & w) { return begin < w.begin; }
};

int min_works(std::vector<tWork> const & v, int c, int f) {

	int works = 0;
	int current_end = c;
	int max_end = 0;
	int i = 0;

	while (i < v.size() && current_end < f) {

		// Si la tarea actual tiene un comienzo mayor que el intervalo cubierto hasta el momento -> imposible de realizar.
		if (v[i].begin > current_end) return 0; 
		
		while (i < v.size() && v[i].begin <= current_end) {

			// Si el final cubierto por el trabajo actual es mayor que el intervalo cubierto hasta el momento -> se actualiza el final maximo.
			if (v[i].end > v[max_end].end && v[i].end > current_end) max_end = i;

			i++;
		}

		current_end = v[max_end].end;
		works++;
	}

	if (current_end < f) return 0;
	else return works;
}

bool resuelveCaso() {

	int c, f, n;
	std::cin >> c >> f >> n;

	if (c == 0 && f == 0 && n == 0) return false;

	if (n == 0) std::cout << "Imposible"; // Si el numero de tareas es igual cero -> imposible de realizar
	else {

		std::vector<tWork> v(n);
		int b, e;

		for (int i = 0; i < n; ++i) {

			std::cin >> b >> e;

			v[i] = { b, e };
		}

		std::sort(v.begin(), v.end());

		if (v[0].begin > c) std::cout << "Imposible"; // Si la tarea que antes comienza, comienza despues del inicio del intervalo -> imposible
		else {

			int min = min_works(v, c, f);

			if (min == 0) std::cout << "Imposible";
			else std::cout << min;
		}
	}

	std::cout << std::endl;

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