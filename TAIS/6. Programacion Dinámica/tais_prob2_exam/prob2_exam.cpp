
/*

	REALIZADO POR: Víctor Chamizo Rodríguez
	USUARIO JUEZ: TAIS58


	FUNCIÓN:

		resolver(i, j) = maximizar los dias en el los que i y j son iguales y distintos de cero.


	FUNCIÓN DE RECURRENCIA:

						resolver(i + 1, j - 1) + 1													bizcocho[i] = bizcocho[j] && bizcocho[i] != 0
	resolver(i,j) = {
						max(resolver(i + 1, j - 1), max(resolver(i + 2, j), resolver(i, j - 2))     si no es la misma fruta || no hay fruta


	COSTE:

		Coste en espacio = O(N ^ 2) --> Al usar una matriz: N x N.
		Coste en tiempo  = N ^ 3 --> Recorremos solo la mitad superior por encima de la diagonal principal.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Matriz.h"

int resolver(std::vector<int> const & v) {

	int n = v.size() - 1;
	Matriz<int> m(n + 1, n + 1, 0);

	for (int d = 1; d <= n - 1; ++d)
		for (int i = 1; i <= n - d; ++i) {

			int j = i + d;

			// Significa que la fruta de ambos lados son igaules y cumpliremos el requisito --> +1 día.
			if (v[i] == v[j] && v[i] != 0) m[i][j] = m[i + 1][j - 1] + 1;
			else {

				// En el primer maximo se comprueba si es mejor comer por los dos lados o el maximo anterior.
				// En el segundo maximo comprobamos si es mejor comer por un lado o por el otro.
				// Siempre debe haber al menos dos trozos de bizcocho --> los indices no puedes ser iguales.
				if (i < j - 2) m[i][j] = std::max(m[i + 1][j - 1], std::max(m[i + 2][j], m[i][j - 2]));
				else m[i][j] = m[i + 1][j - 1];
			}
		}

	return m[1][n];
}

bool resuelveCaso() {

	int N;
	std::cin >> N;

	if (!std::cin) return false;

	std::vector<int> bizcocho(N + 1);

	bizcocho[0] = -1;

	for (int i = 1; i <= N; i++) std::cin >> bizcocho[i];
	
	std::cout << resolver(bizcocho) << std::endl;

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
