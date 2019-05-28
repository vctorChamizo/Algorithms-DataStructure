// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

# ifndef FECHA
# define FECHA

#include <iostream>
#include <iomanip>
#include <stdexcept>

class fecha {

	int day, hour, minute;

public:

	fecha() {}

	fecha(int d, int h, int m) : day(d), hour(h), minute(m) {

		if (d < 1 || d > 31 || h < 0 || h > 23 || m < 0 || m > 59) throw std::invalid_argument("ERROR DATE");
	}

	int get_day() const { return this->day; }
	int get_hour() const { return this->hour; }
	int get_minute() const { return this->minute; }

	bool operator < (fecha const & f) const {

		if (day < f.day) return true;
		else if (day == f.day && hour < f.hour) return true;
		else if (day == f.day && hour == f.hour && minute < f.minute) return true;

		return false;
	}

	bool operator == (fecha const & f) const { return day == f.day && hour == f.hour && minute == f.minute; }
};

inline std::istream & operator >> (std::istream & in, fecha & f) {

	int d, h, m;

	in >> d >> h >> m;

	f = fecha(d, h, m);

	return in;
}

#endif