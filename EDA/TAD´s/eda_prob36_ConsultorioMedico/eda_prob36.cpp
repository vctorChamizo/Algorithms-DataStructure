// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "fecha.h"
#include "consultorio.h"

bool resuelveCaso() {

	int n_operaciones;
	std::cin >> n_operaciones;

	if (!std::cin) return false;

	std::string operacion, medico, paciente;
	fecha fecha_consulta;

	consultorio consultorio;

	for (int i = 0; i < n_operaciones; ++i) {

		std::cin >> operacion;

		try {

			if (operacion == "nuevoMedico") {

				std::cin >> medico;

				consultorio.nuevo_medico(medico);
			}
			else if (operacion == "pideConsulta") {

				std::cin >> paciente >> medico >> fecha_consulta;

				consultorio.pide_consulta(paciente, medico, fecha_consulta);
			}
			else if (operacion == "siguientePaciente") {

				std::cin >> medico;

				std::cout << "Siguiente paciente doctor " << medico << std::endl << consultorio.siguiente_paciente(medico);

				std::cout << std::endl << "---" << std::endl;
			}
			else if (operacion == "atiendeConsulta") {

				std::cin >> medico;

				consultorio.atiende_consulta(medico);
			}
			else if (operacion == "listaPacientes") {

				int dia;
				std::cin >> medico >> dia;

				std::list<std::pair<std::string, fecha>> lista = consultorio.lista_pacientes(medico, dia);

				std::cout << "Doctor " << medico << " dia " << dia << std::endl;

				for (auto const & l : lista) std::cout << l.first << ' '
											 << std::setfill('0') << std::setw(2) << l.second.get_hour() << ':'
											 << std::setfill('0') << std::setw(2) << l.second.get_minute() << std::endl;

				std::cout << "---" << std::endl;
			}
			else std::cout << "OPERACION DESCONOCIDA";

		} catch (std::domain_error e) { std::cout << e.what() << std::endl << "---" << std::endl; }
	}

	std::cout << "------" << std::endl;

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