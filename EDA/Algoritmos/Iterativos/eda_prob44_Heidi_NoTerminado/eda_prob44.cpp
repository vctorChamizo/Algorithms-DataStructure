// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void conseguirSecuencia(std::vector<int> const & v, int seqMin, std::vector<int> & vSol, int & seqMax) {

	int longitudSegmento = 1;
	int max = 1;

	for (int i = v.size() - 1; i >= 0; i--) {

		if (v[i] > max) { //Comenzamos un nuevo segmento.

			max = v[i];
			longitudSegmento = 1;
		}
		else if (v[i] == max) {

			longitudSegmento++;

			if (longitudSegmento >= seqMin) {

				//Si la longitud coincide con la minima --> guardamos su posicion de comienzo en el vector.
				if (longitudSegmento == seqMin) vSol.push_back(i + (longitudSegmento - 1));

				// Si la longitud es mayor que el maximo --> actualizamos el maximo.
				if (longitudSegmento > seqMax) seqMax = longitudSegmento;
			}
		}
		else longitudSegmento = 0;
	}
}

bool resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	if (!std::cin) return false;

	int secuenciaMinima;

	std::cin >> secuenciaMinima;

	std::vector<int> datos(nElem);

	for (int & d : datos) std::cin >> d;

	std::vector<int> vectorSolucion;
	int secuenciaMax = 0;

	conseguirSecuencia(datos, secuenciaMinima, vectorSolucion, secuenciaMax);

	std::cout << secuenciaMax << " " << vectorSolucion.size();
	for (int & s : vectorSolucion) std::cout << " " << s;

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