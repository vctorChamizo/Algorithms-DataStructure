// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct tOrdenado {

	int max;
	int min;
	bool parcial = true;
};


bool esParcialOrdenado(std::vector<int> const& v, int ini, int fin, tOrdenado& ord) {

	if (ini == fin) return true;
	else if (ini + 1 == fin) {

		if (v[ini] <= v[fin]) {

			ord.max = v[fin];
			ord.min = v[ini];

			return true;
		}

		return false;
	}
	else {

		int m = (ini + fin) / 2;

		bool parOrdenadoIz, parOrdenadoDch;
		tOrdenado ordIz, ordDch;

		parOrdenadoIz = esParcialOrdenado(v, ini, m, ordIz);

		if (parOrdenadoIz) {

			parOrdenadoDch = esParcialOrdenado(v, m + 1, fin, ordDch);

			if (parOrdenadoDch && ordDch.max >= ordIz.max && ordIz.min <= ordDch.min) {

				ord.max = ordDch.max;
				ord.min = ordIz.min;

				return true;
			}
		}
			
		return false;
	}
}


bool resuelveCaso() {

	int n;

	std::cin >> n;

	if (n == 0)
		return false;

	std::vector<int> vector;

	do{

		vector.push_back(n);
		std::cin >> n;

	}while (n != 0);

	tOrdenado ord;

	bool parOrdenado = esParcialOrdenado(vector, 0, vector.size() - 1, ord);

	if (parOrdenado) std::cout << "SI";
	else std::cout << "NO";

	std::cout <<  std::endl;

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