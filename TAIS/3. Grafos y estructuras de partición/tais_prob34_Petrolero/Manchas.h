// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <vector>
#include <algorithm>

#include "ConjuntosDisjuntos.h"

using Area = std::vector<std::vector<char>>;

class Manchas {

public:

	Manchas(Area & A) :  
		F(A.size()),
		C(A[0].size()),
		marcado(F, std::vector<bool>(C, false)),
		nManchas(0),
		maximo(0),
		conjuntos(F * C){

		for (int i = 0; i < F; ++i)
			for (int j = 0; j < C; ++j) 
				if (A[i][j] == '#' && !marcado[i][j]) {

					int size_m = 0;

					nManchas++;
					
					dfs(A, i, j, size_m);

					maximo = std::max(maximo, size_m);
				}
	}

	int getManchas() const { return nManchas; }

	int getMaximo() const { return maximo; }

	void meterMancha(Area & A, int i, int j) {

		A[i][j] = '#';

		for (auto d : direcciones) {

			int ni = i + d.first, nj = j + d.second;

			if (correcta(ni, nj) && A[ni][nj] == '#') 
				conjuntos.unir(getCoordenada(i, j), getCoordenada(ni, nj));
		}

		maximo = std::max(maximo, conjuntos.tam(getCoordenada(i, j)));
	}

private:

	int F, C; //Dimensiones del area.
	std::vector<std::vector<bool>> marcado; // marcado[i][j] = se ha visitado <i,j>
	int nManchas, maximo;

	ConjuntosDisjuntos conjuntos;

	const std::vector<std::pair<int, int>> direcciones = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };

	bool correcta(int i, int j) const { return i >= 0 && i < F && j >= 0 && j < C; }

	//Determina la posición unica que mantiene el conjunto disjunto dentro de la matriz.
	int getCoordenada(int i, int j) const { return i * C + j; }

	void dfs(Area const & A, int i, int j, int & size_m) {

		marcado[i][j] = true;

		size_m++;

		for (auto d : direcciones) {

			int ni = i + d.first, nj = j + d.second;

			if (correcta(ni, nj) && A[ni][nj] == '#' && !marcado[ni][nj]) {

				conjuntos.unir(getCoordenada(i, j), getCoordenada(ni, nj));

				dfs(A, ni, nj, size_m);
			}
		}
	}
};