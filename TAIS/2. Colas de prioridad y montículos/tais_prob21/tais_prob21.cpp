// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"


struct tUser {

	long int id;
	int acumulado;
	int tiempo;

	bool operator < (tUser const& u2) const{

		return acumulado < u2.acumulado || (acumulado == u2.acumulado && id < u2.id);
	}
};

/*bool operator < (tUser const& u1, tUser const& u2) {

	return u1.acumulado < u2.acumulado || (u1.acumulado == u2.acumulado && u1.id < u2.id);
}*/

// función que resuelve el problema
long int resolver(PriorityQueue<tUser>& monticulo) {

	tUser aux = monticulo.top();

	monticulo.pop();

	aux.acumulado += aux.tiempo;

	monticulo.push(aux);

	return aux.id;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int nUser;

	std::cin >> nUser;

	if (nUser == 0) return false;

	PriorityQueue<tUser> monticulo;
	tUser user_aux;

	for (int i = 0; i < nUser; ++i) {

		std::cin >> user_aux.id;
		std::cin >> user_aux.tiempo;
		user_aux.acumulado = user_aux.tiempo;

		monticulo.push(user_aux);
	}

	long int k;
	long int sol;

	std::cin >> k;

	for (int i = 0; i < k; ++i) {

		 sol = resolver(monticulo);

		 std::cout << sol << std::endl;
	}

	std::cout << "----" << std::endl;

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}