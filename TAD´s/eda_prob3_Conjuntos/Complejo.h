// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

# ifndef COMPLEJO
# define COMPLEJO

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Complejo {

	T real, imaginaria;

public:

	Complejo();
	Complejo(T r, T im);

	Complejo<T> operator + (Complejo<T> const & c) const;
	Complejo<T> operator * (Complejo<T> const & c) const;

	int getMod() const { return mod(); }
	
private:

	int mod() const;
};

// Constructores
template <typename T>
Complejo<T>::Complejo() {}

template <typename T>
Complejo<T>::Complejo(T r, T im) : real(r), imaginaria(im) {}


// Operadores
template <typename T>
Complejo<T> Complejo<T>::operator + (Complejo<T> const & c) const {	return Complejo<T>(real + c.real, imaginaria + c.imaginaria); }

template <typename T>
Complejo<T> Complejo<T>::operator * (Complejo<T> const & c) const { return Complejo<T>((real*c.real) - (imaginaria*c.imaginaria), (real*c.imaginaria) + (c.real*imaginaria)); }


// Operaciones aritmeticas
template<typename T>
int Complejo<T>::mod() const { return sqrt(real * real + imaginaria * imaginaria); }


// Control de flujo
template <typename T>
std::istream & operator >> (std::istream & in, Complejo<T> & complejo) {

	T r, im;
	in >> r >> im;
	complejo = Complejo<T>(r, im);

	return in;
}

#endif
