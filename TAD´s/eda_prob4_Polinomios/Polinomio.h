// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

# ifndef POLINOMIO
# define POLINOMIO

#include <vector>

class Polinomio {

	/*
		first  --> coeficiente
		second --> exponente
	*/
	std::vector<std::pair<int, int>> monomios;

public:

	// Constructores
	Polinomio();
	
	// Operaciones
	void insert(int c, int e);
	int evaluate(int v) const;

private:

	// Operaciones
	bool contains(int c, int e);
};

// Constructores
Polinomio::Polinomio() {}


// Operaciones publicas
// Inserta el coeficente con su respectivo exponente en su posicion correspondiente
void Polinomio::insert(int c, int e) {

	if (c != 0 && !contains(c, e)) monomios.push_back(std::make_pair(c, e));
}

// Dado un valor resuelve el polimonio;
int Polinomio::evaluate(int v) const {

	int resultado = 0;

	for (auto & m : monomios) resultado += m.first * (std::pow(v, m.second));

	return resultado;
}


//Operaciones privadas
//Si el exponente ya esta contenido en el polinomio se suman sus coeficientes
bool Polinomio::contains(int c, int e) {

	int i = 0;
	while (i < monomios.size()) {

		if (monomios[i].second == e) {

			monomios[i].first += +c;
			return true;
		}
		else ++i;
	}

	return false;
}

#endif
