// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

# ifndef CONJUNTO
# define CONJUNTO

# include <cstddef>
# include <stdexcept>
# include <utility>

template <typename T>
class set {

public:

	// Constructores
	set();
	set(set <T> const & other);

	// Destructor
	~set();

	// Operadores
	set <T> & operator = (set <T> const & other);
	
	// Operaciones
	void insert(T e);
	bool contains(T e) const;
	void erase(T e);
	bool empty() const;
	size_t size() const;

private:

	size_t contador;
	size_t capacidad;
	T * datos;

	// Operaciones
	void amplia();
	void libera();
	void copia(set <T> const & other);
};


// Constructores
template <typename T>
set <T >::set() : contador(0), capacidad(8), datos(new T[capacidad]) {}

template <typename T>
set <T >::set(set <T> const & other) { copia(other); }


// Destructor
template <typename T>
set <T >::~set() { delete[] datos; }


// Operadores
template <typename T>
set <T> & set <T >:: operator =(set <T> const & other) {

	if (this != &other) {

		libera();
		copia(other);
	}

	return *this;
}


// Operaciones publicas
// A~nadir elementos
template <typename T>
void set <T >::insert(T e) {

	if (!contains(e)) {

		if (contador == capacidad) amplia();

		datos[contador] = e;
		++contador;
	}
}

// Comprueba si un elemento pertenece al conjunto
template <typename T>
bool set <T >::contains(T e) const {

	size_t i = 0;
	while (i < contador && datos[i] != e) ++i;

	return i < contador;
}

// Elimina un elemento del conjuto
template <typename T>
void set <T >::erase(T e) {

	size_t i = 0;
	while (i < contador && datos[i] != e) ++i;

	if (i < contador) {

		datos[i] = datos[contador - 1];
		--contador;
	}
	else throw std::domain_error("El elemento no esta ");
}

// Comprueba si el conjunto esta vacio
template <typename T>
bool set <T >::empty() const { return contador = 0; }

// Obtiene el numero de elementos del conjunto
template <typename T>
size_t set <T >::size() const { return contador; }


// Operaciones privadas
// Libera la memoria dinamica
template <typename T>
void set <T >::libera() { delete[] datos; }

// Copia el contenido de un vector
template <typename T>
void set <T >::copia(set <T> const & other) {

	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];

	for (size_t i = 0; i < contador; ++i) datos[i] = other.datos[i];
}

// Amplia la memoria del vector
template <typename T>
void set <T >::amplia() {

	T * nuevos = new T[2 * capacidad];

	for (size_t i = 0; i < capacidad; ++i) nuevos[i] = std::move(datos[i]);

	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

# endif