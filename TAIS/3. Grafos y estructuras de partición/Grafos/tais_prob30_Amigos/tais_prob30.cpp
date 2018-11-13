// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Grafo.h"
#include "MaximaComponenteConexa.h"


void resuelveCaso() {

	int nPersonas; //Vertices del grafo
	int paresAmigos; //Aristas del grafo

	std::cin >> nPersonas >> paresAmigos;

	Grafo grafo(nPersonas); //Inicializamos el grafo con el numero de vertices que va a tener.

	int amigo1, amigo2;

	for (int i = 0; i < paresAmigos; ++i) {

		std::cin >> amigo1 >> amigo2;

		//Con esta función colcamos las aristas con los vertices correspondientes.
		grafo.ponArista(amigo1 - 1, amigo2 - 1); 
	}

	MaximaComponenteConexa mcc(grafo);

	std::cout << mcc.maximo() << std::endl;
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