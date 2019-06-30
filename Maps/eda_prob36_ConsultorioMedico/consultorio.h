// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef CONSULTORIO
#define CONSULTORIO

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <map>
#include <list>

#include "fecha.h"

using medico = std::string;
using paciente = std::string;
using consulta = std::map<fecha, paciente>;

class consultorio {

	std::unordered_map<medico, consulta> consultorio_mapa;

public:

	consultorio() {}

	void nuevo_medico(medico m) { nuevo_medico_privado(m); }
	void pide_consulta(paciente p, medico m, fecha f) { pide_consulta_privado(p, m, f); }
	std::string siguiente_paciente(medico m) { return siguiente_paciente_privado(m); }
	void atiende_consulta(medico m) { atiende_consulta_privado(m); }
	std::list<std::pair<paciente, fecha>> lista_pacientes(medico m, int d) { return lista_pacientes_privado(m, d); }

private:

	// COST: O(1);
	void nuevo_medico_privado(medico m) { this->consultorio_mapa[m]; }

	// COST: O(1);
	void pide_consulta_privado(paciente p, medico m, fecha f) { 
	
		if (existe_medico(m)) throw std::domain_error("Medico no existente");
		else if (this->consultorio_mapa[m].count(f) != 0) throw std::domain_error("Fecha ocupada");
		else this->consultorio_mapa[m][f] = p;
	}

	// COST: O(1);
	std::string siguiente_paciente_privado(medico m) {

		if (existe_medico(m)) throw std::domain_error("Medico no existente");
		else if (this->consultorio_mapa[m].size() == 0) throw std::domain_error("No hay pacientes");
		else return this->consultorio_mapa[m].begin()->second;
	}

	// COST: O(1);
	void atiende_consulta_privado(medico m) {

		if (existe_medico(m)) throw std::domain_error("Medico no existente");
		else if (this->consultorio_mapa[m].size() == 0) throw std::domain_error("No hay pacientes");
		else this->consultorio_mapa[m].erase(this->consultorio_mapa[m].begin()->first);
	}

	// COST: O(n) -> siendo n el numero de pacientes que tiene el medico en esa fecha;
	std::list<std::pair<paciente, fecha>> lista_pacientes_privado(medico m, int d) {

		if (existe_medico(m)) throw std::domain_error("Medico no existente");
		else {

			std::list<std::pair<paciente, fecha>> lista;

			for (auto it = this->consultorio_mapa[m].begin(); it != this->consultorio_mapa[m].end(); ++it)
				if (it->first.get_day() == d)  lista.push_back({ it->second, it->first });

			return lista;
		}
	}

	bool existe_medico(medico m) { return this->consultorio_mapa.count(m) == 0;  }
};

#endif
