// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

# ifndef HORA
# define HORA

# include <iostream>
# include <stdexcept>

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

	int aux_h, aux_m, aux_s;

	aux_h = h.getHoras();
	aux_m = h.getMinutos();
	aux_s = h.getSegundos();

	if (aux_h < 10) out << '0';
	out << aux_h << ':';

	if (aux_m < 10) out << '0';
	out << aux_m << ':';

	if (aux_s < 10) out << '0';
	out << aux_s;

	return out;
}

inline std::istream & operator >> (std::istream & in, Hora & hora) {

	char aux; // captura el caracter ':' del formato de entrada --> HH:MM:SS
	int h, m, s;

	in >> h >> aux >> m >> aux >> s;

	hora = Hora(h, m, s);

	return in;
}

#endif