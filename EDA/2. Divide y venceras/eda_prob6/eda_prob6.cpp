// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

/*
El problema se resuelve usando el esquema algoritmico Divide y Vencerás.

Antes de llamar a la función que aplicará este esquema algorítmico se
realizan unas comprobaciones basicas para descargar de argumentos dicha función.
Las comprobaciones ralizadas son en las que el preso fugado debería estar en la primera
o última posicion del vector.

La función "buscarPreso" realiza llamadas recusrsivas a derecha o izquierda dependiendo de
si el código de los presos de ese rango del vector son consecutivos o no.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


char buscarPreso(std::vector<char> const& v, int ini, int fin) {

	int m = (ini + fin) / 2;

	if (ini + 1 == fin) return v[ini] + 1;
	else {

		if (v[m] > v[0] + m) return buscarPreso(v, ini, m);
		else return buscarPreso(v, m, fin);
	}
}


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
	else if (presos[presos.size() - 1] != ultimoPreso) fugado = ultimoPreso;
	else {

		fugado = buscarPreso(presos, 0, presos.size() - 1);
	}
	
	std::cout << fugado << std::endl;
}

int main() {
	
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}