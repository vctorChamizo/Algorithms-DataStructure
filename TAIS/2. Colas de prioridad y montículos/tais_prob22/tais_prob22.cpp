// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PriorityQueue.h"


struct tPaciente {

	std::string nombre;
	long int gravedad;
	int orden;

	bool operator < (tPaciente const& p) const {

		return gravedad > p.gravedad || (gravedad == p.gravedad && orden < p.orden);
	}
};


// función que resuelve el problema
std::string resolver(PriorityQueue<tPaciente>& monticulo) {

	tPaciente paciente_aux = monticulo.top();
	monticulo.pop();

	return paciente_aux.nombre;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	long int nEventos;

	std::cin >> nEventos;

	if (nEventos == 0)
		return false;

	tPaciente paciente;
	PriorityQueue<tPaciente> colaPacientes;

	char evento;
	int ordenLLegada = 0;

	for (int i = 0; i < nEventos; ++i) {

		std::cin >> evento;

		if (evento == 'I') {

			std::cin >> paciente.nombre;
			std::cin >> paciente.gravedad;

			paciente.orden = ordenLLegada;
			ordenLLegada++;

			colaPacientes.push(paciente);
		}
		else {

			std::string nombrePaciente = resolver(colaPacientes);

			std::cout << nombrePaciente << std::endl;
		}
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