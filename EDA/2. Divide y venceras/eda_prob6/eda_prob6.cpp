// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
char buscarPreso(std::vector<char> const& v, int ini, int fin) {

	int m = (ini + fin) / 2;

	if (ini + 1 == fin) return v[ini] + 1;
	else {

		if (v[m] > v[0] + m) return buscarPreso(v, ini, m);
		else return buscarPreso(v, m, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	char primerPreso, ultimoPreso;

	std::cin >> primerPreso >> ultimoPreso;

	std::vector<char> presos;
	char letra;
	int cont = 0;

	while (cont < (ultimoPreso - primerPreso)) {

		std::cin >> letra;
		presos.push_back(letra);
		cont++;
	}

	char fugado;

	if (presos[0] != primerPreso) fugado = primerPreso;
	//si falta el ultimo preso
	else if (presos[presos.size() - 1] != ultimoPreso) fugado = ultimoPreso;
	else {

		fugado = buscarPreso(presos, 0, presos.size() - 1);
	}
	
	std::cout << fugado << std::endl;
}

int main() {
	
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}