// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

# ifndef PELICULA
# define PELICULA

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "Hora.h"

class Pelicula {

public:

	Pelicula() {}

	Pelicula(Hora h_i, Hora d, std::string t) : h_inicio(h_i), duracion(d), titulo(t), h_fin(h_i + d) {}

	Hora getHoraInicio() const { return h_inicio; }
	Hora getHoraFin() const { return h_fin; }
	Hora getDuracion() const { return duracion; }
	std::string getTitulo() const { return titulo; }

	// Operadores de comparación
	bool operator < (Pelicula const & p) const { return h_fin < p.h_fin || (h_fin == p.h_fin && titulo < p.titulo);  }


private:

	Hora h_inicio, duracion, h_fin;
	std::string titulo;
};

inline std::ostream & operator << (std::ostream & out, Pelicula const & p) { return out << p.getHoraFin() << ' ' << p.getTitulo(); }

inline std::istream & operator >> (std::istream & in, Pelicula & p) {

	Hora h_inicio, duracion;
	std::string titulo;

	in >> h_inicio >> duracion;
	getline(std::cin, titulo);

	p = Pelicula(h_inicio, duracion, titulo);

	return in;
}

#endif