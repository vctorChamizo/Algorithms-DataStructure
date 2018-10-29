#include <vector>

using Imagen = std::vector<std::vector<char>>;

class Ovejas {

public:

	/*
		- Inicializamos el valor de las filas y columnas.
		- El vector de marcado también es una matriz, que inicializamos a falso.
		- El numero de manchas blancas inicializa a cero.
	*/
	Ovejas(Imagen const & I) :  F(I.size()), C(I[0].size()), marcado(F, std::vector<bool>(C, false)), manchasBlancas(0) {

		//Comparabamos cada uno de los elementos de la matriz.
		for (int i = 0; i < F; ++i)
			for (int j = 0; j < C; ++j)
				//Encontramos una nueva mancha blanca que no está marcada.
				if (I[i][j] == '.' && !marcado[i][j]) {

					manchasBlancas++;

					dfs(I, i, j);
				}
	}

	int getOvejasBlancas() const { return manchasBlancas - 1; }


private:

	int F, C; //Dimensiones de la imagen
	std::vector<std::vector<bool>> marcado; // marcado[i][j] = se ha visitado <i,j>
	int manchasBlancas; // número de manchas blancas

	// Creamos un vector de un vector de pares. Su finalidad es mirar los elemntos colindantes del elemento de la matriz
	const std::vector<std::pair<int, int>> direcciones = { {1,0},{0,1},{-1,0},{0,-1} };

	//Verifica que el elemento al que se quiere acceder esta dentro de los limites de la matriz.
	bool correcta(int i, int j) const { return i >= 0 && i < F && j >= 0 && j < C; }

	void dfs(Imagen const & I, int i, int j) {

		marcado[i][j] = true;

		for (auto d : direcciones) {

			int ni = i + d.first, nj = j + d.second;

			if (correcta(ni, nj) && I[ni][nj] == '.' && !marcado[ni][nj]) dfs(I, ni, nj);
		}
	}
};
