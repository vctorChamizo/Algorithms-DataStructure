// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

# ifndef HORA
# define HORA

# include <iostream>
# include <stdexcept>
# include <iomanip>

class Hora {

public:

	Hora() {}

	Hora (int h, int m, int s) : horas(h), minutos(m), segundos(s) {
	
		if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) throw std::invalid_argument("ERROR");
	}
	
	int getHoras() const { return horas; }
	int getMinutos() const { return minutos; }
	int getSegundos() const { return segundos; }

	// Operadores de comparación
	bool operator < (Hora const & h) const {

		if (horas < h.horas) return true;
		else if (horas == h.horas && minutos < h.minutos) return true;
		else if (horas == h.horas && minutos == h.minutos && segundos < h.segundos) return true;

		return false;
	}

	bool operator == (Hora const & h) const { return horas == h.horas && minutos == h.minutos && segundos == h.segundos; }


private:

	int horas, minutos, segundos;
};

inline std::ostream & operator << (std::ostream & out, Hora const & h) {

	return out << std::setfill('0') << std::setw(2) << h.getHoras() << ':'
			   << std::setfill('0') << std::setw(2) << h.getMinutos() << ':'
			   << std::setfill('0') << std::setw(2) << h.getSegundos();
}

inline std::istream & operator >> (std::istream & in, Hora & hora) {

	char aux; // captura el caracter ':' del formato de entrada --> HH:MM:SS
	int h, m, s;

	in >> h >> aux >> m >> aux >> s;

	hora = Hora(h, m, s);

	return in;
}

#endif