// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool comprobarDegradado(std::vector<int> const & v, int ini, int fin, int & suma) {

	if (ini == fin) return true;
	else if (ini + 1 == fin) {

		suma = v[ini] + v[fin];

		return v[ini] < v[fin];
	}
	else {

		int m = (ini + fin) / 2;

		int sumIz, sumDch;
		bool degIz, degDch;
		
		//Comprobamos la mitad izquierda
		degIz = comprobarDegradado(v, ini, m, sumIz);

		if (degIz) {

			//Comprbamos la mitad derecha
			degDch = comprobarDegradado(v, m + 1, fin, sumDch);

			suma = sumIz + sumDch;

			return degIz && degDch && sumIz < sumDch;
		}
		else return false;
	}
}


bool resuelveCaso() {

	int n;

	std::cin >> n;

	if (!std::cin)
		return false;

	int m;

	std::cin >> m;

	bool esDegradado = true, deg_aux;
	int cont = 0;

	std::vector<int> columna(m);

	for (int j = 0; j < n; ++j){
		for (int i = 0; i < columna.size(); ++i)
			std::cin >> columna[i];

		int suma;
		deg_aux = comprobarDegradado(columna, 0, columna.size() - 1, suma);

		if (!deg_aux) esDegradado = deg_aux;
	}

	if (esDegradado) std::cout << "SI";
	else std::cout << "NO";

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