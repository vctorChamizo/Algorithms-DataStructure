// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

bool esValida(std::vector<int> & vSol, 
				std::vector<int> & vUJ, 
				std::vector<std::string> const & vTJ, 
				std::vector<std::vector<int>> const & vSats, 
				int sats, 
				int k, 
				int i) {

	if (vUJ[i] == 0) return false; // Si no quedan unidades de ese juguete no se puede repartir.

	if (k >= 1) { //Si ya hay al menos un juguete repartido 


	}
}

 
bool esSolucion() {}


void resolver(std::vector<int> & vSol, 
				std::vector<int> & vUJ, 
				std::vector<std::string> const & vTJ, 
				std::vector<std::vector<int>> const & vSats,
				std::vector<int> & vNJC,
				bool & sol,
				int sats,
				int k) {

	for (int i = 0; i < vTJ.size(); ++i) {

		vSol[k] = i;
		vUJ[i]--;

		if (esValida(vSol, vUJ, vTJ, vSats)) {

			if (!esSolucion()) resolver(vSol, vUJ, vTJ, vSats, vNJC, sol, sats, k + 1);
			else {

				sol = true;

				std::cout << vSol[0];
				for (int j = 0; j < vSol.size(); ++j)
					std::cout << " " << vSol[j];
			}
		}//esValida
	}//for
}


bool resuelveCaso() {

	int nJuguetes, nChicos, satisfaccionMin;
	std::cin >> nJuguetes >> nChicos >> satisfaccionMin;

	if (!std::cin) return false;

	//Numero de unidades disponibles de cada juguete.
	std::vector<int> unidadesJuguetes (nJuguetes);
	for (int & u : unidadesJuguetes) std::cin >> u;

	//Tipo de cada juguete.
	std::vector<std::string> tipoJuguete(nJuguetes);
	for (std::string & t : tipoJuguete) std::cin >> t;

	//Niveles de satisfaccin de los niños
	std::vector<std::vector<int>> satisfacciones(nChicos, std:: vector<int>(nJuguetes));
	for (int i = 0; i < nChicos; ++i)
		for (int j = 0; j < nJuguetes; ++j)
			std::cin >> satisfacciones[i][j];

	//Vector que contabiliza el numero de juguetes que lleva cada niño
	std::vector<int> nJuguetesChico(nChicos, 0);

	//Vector Solucion 
	std::vector<int> vectorSolucion(2 * nChicos);

	bool solucion = false;

	resolver(vectorSolucion, unidadesJuguetes, tipoJuguete, satisfacciones, nJuguetesChico, solucion, satisfaccionMin, 0);

	if (!solucion) std::cout << "SIN SOLUCION" << std::endl;

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