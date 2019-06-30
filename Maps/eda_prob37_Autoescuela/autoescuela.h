// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef AUTOESCUELA
#define AUTOESCUELA

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <map>
#include <list>

const int PUNT_MIN = 0;

using alumno = std::string;
using profesor = std::string;
using punt = int;

struct info_alumno {

	profesor profe;
	punt puntos;
};

class autoescuela {

	std::unordered_map<alumno, info_alumno> alumnos;
	std::unordered_map<profesor, std::map<alumno, punt>> profesores;

public:

	autoescuela() {}

	void alta(alumno al, profesor prof) { alta_privado(al, prof);  }
	bool es_alumno(alumno al, profesor prof) { return es_alumno_privado(al, prof);  }
	int puntuacion(alumno al) { return  puntuacion_privado(al);  }
	void actualizar(alumno al, punt p) { actualizar_privado(al, p); }
	std::list<alumno> examen(profesor prof, punt p) { return examen_privado(prof, p);  }
	void aprobar(alumno al) { aprobar_privado(al); }

private:

	// COSTE: O(1);
	void alta_privado(alumno al, profesor prof) {
	
		// Si no está registrado --> se registra;
		if (this->alumnos.count(al) == 0) {

			this->alumnos[al] = {prof, PUNT_MIN}; // Se registra en el mapa de alumnos;
			this->profesores[prof][al] = PUNT_MIN; // Se registra nuevo alumno en la clave de profesor.
		}
		// Si ya está registrado y tiene nuevo profesor --> se actualza el profesor.
		else {

			this->profesores[this->alumnos[al].profe].erase(al); // Borramos el alumno de su antiguo profesor.
			this->alumnos[al].profe = prof; // Se actuliza el profesor en la clave del alumno.
			this->profesores[prof][al] = this->alumnos[al].puntos; //Se registra el alumno con el nuevo profesor y la puntación anterior.
		}
	}

	// COSTE: O(1);
	bool es_alumno_privado(alumno al, profesor prof) { return this->alumnos[al].profe == prof; }

	// COSTE: O(1);
	int puntuacion_privado(alumno al) {
	
		if (this->alumnos.count(al) == 0) throw std::domain_error("El alumno " + al + " no esta matriculado");
		else return this->alumnos[al].puntos;
	}

	// COSTE: O(1);
	void actualizar_privado(alumno al, punt p) {
	
		if (this->alumnos.count(al) == 0) throw std::domain_error("El alumno " + al + " no esta matriculado");
		else {

			int current_points = this->alumnos[al].puntos + p; // Actualizamos la puntación que el alumno tiene actualmente.

			this->alumnos[al].puntos = current_points; // Actualzimos la puntuación en la clave del alumno.
			this->profesores[this->alumnos[al].profe][al] = current_points; // Actualizamos la información de la ficha del profesro del alumno.
		}
	}

	// COSTE: O(n) -> siendo n el numero de alumnos a los que el profesor da clases de conducir.
	std::list<alumno> examen_privado(profesor prof, punt p) {
	
		std::list<alumno> lista_alumnos;

		// Recorremos la lista de alumnos que tiene el profesor y se filtr aquellos que cumplan el minimo de puntuación.
		for (auto it = this->profesores[prof].begin(); it != this->profesores[prof].end(); ++it) 
			if (it->second >= p) lista_alumnos.push_back(it->first);

		return lista_alumnos;		
	}

	// COSTE: O(1)
	void aprobar_privado(alumno al) {
	
		if (this->alumnos.count(al) == 0) throw std::domain_error("El alumno " + al + " no esta matriculado");
		else {

			this->profesores[this->alumnos[al].profe].erase(al);
			this->alumnos.erase(al);
		}
	}
};

#endif
