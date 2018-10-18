// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct tSospechoso {

	int primero, ultimo;
	bool existe = false;
};


tSospechoso buscarCulpable(std::vector<int> const& v, int ini, int fin, int altSos) {

	tSospechoso sospechoso;

	if (ini == fin) {//Si solo hay un sospechoso.

		if (v[ini] == altSos) {//Si el sospechoso coincide con la altura.

			sospechoso.primero = sospechoso.ultimo = ini;
			sospechoso.existe = true;
		}

		return sospechoso;
	}
	else if (ini + 1 == fin) {//Si solo hay dos sospechoso

		if (v[ini] == altSos && v[fin] == altSos) {//Si ambos sospechosos coinciden con la altura

			sospechoso.primero = ini;
			sospechoso.ultimo = fin;
			sospechoso.existe = true;;
		}
		else if (v[ini] == altSos) {//Si solo el primero de los dos coincide con la altura

			sospechoso.primero = ini;
			sospechoso.ultimo = ini;
			sospechoso.existe = true;;
		}
		else if (v[fin] == altSos) {//Si solo el ultimo de los dos coincide con la altura

			sospechoso.primero = fin;
			sospechoso.ultimo = fin;
			sospechoso.existe = true;
		}

		return sospechoso;
	}
	else {

		int m = (ini + fin) / 2;

		tSospechoso sospechosoIz, sospechosoDch;

		if (altSos < v[m]) return sospechosoIz = buscarCulpable(v, ini, m - 1, altSos);
		else if (altSos > v[m]) return sospechosoDch = buscarCulpable(v, m + 1, fin, altSos);
		else {

			tSospechoso sospechoso_aux;

			sospechosoIz = buscarCulpable(v, ini, m - 1, altSos);

			if (sospechosoIz.existe) sospechoso_aux.primero = sospechosoIz.primero;
			else sospechoso_aux.primero = m;

			if (altSos < v[m + 1]) sospechoso_aux.ultimo = m;
			else {

				sospechosoDch = buscarCulpable(v, m + 1, fin, altSos);
				sospechoso_aux.ultimo = sospechosoDch.ultimo;
			}

			sospechoso_aux.existe = true;

			return sospechoso_aux;
		}
	}
}


bool resuelveCaso() {

	long int nSospechosos;

	std::cin >> nSospechosos;

	if (!std::cin)
		return false;

	int alturaSospechoso;

	std::cin >> alturaSospechoso;

	std::vector<int> listaSospechosos(nSospechosos);

	for (int i = 0; i < listaSospechosos.size(); ++i)
		std::cin >> listaSospechosos[i];

	tSospechoso sospechosos = buscarCulpable(listaSospechosos, 0, listaSospechosos.size() - 1, alturaSospechoso);

	if (sospechosos.existe) {

		if (sospechosos.primero == sospechosos.ultimo) std::cout << sospechosos.primero << std::endl;
		else std::cout << sospechosos.primero << " " << sospechosos.ultimo << std::endl;
	}
	else std::cout << "NO EXISTE" << std::endl;

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