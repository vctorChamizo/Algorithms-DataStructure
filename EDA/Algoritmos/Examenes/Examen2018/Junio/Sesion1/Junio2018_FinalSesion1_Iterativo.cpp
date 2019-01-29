/*

	ESPECIFICACIÓN:

		method nCeros (v : array<int>, m : int) returns (max : int)
			requires v != null && v.Length
			requires 0 <= m <= v.Length
			ensures 0 <= max <= v.Length
			[...]
			{
				max := 0;
				var max_aux := 0;
				var contCeros := 0;

				var i := 0;

				while (i < v.Length)
					invariant 0 <= i < v.Length
					[...]
					decreases (v.Length - i)
					{
						if (v[i] == 1) max_aux := max_aux + 1;
						else if (v[i] == 0) {

							contCeros := contCeros + 1;
							max_aux := max_aux + 1;

							if (contCeros > m) { 
							
								contCeros := 0;
								max_aux := 0;
							}
						}

						if (max < max_aux) max := max_aux;

						i := i + 1;
					{
			}


	COSTE:

		O(n) --> donde n es el numero de elementos del vector.

		Este orden de complejidad se da ya que el vector solo se recorre una unica vez independientemente
		del tamaño de los datos de entrada.
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


int nCeros(std::vector<int> const & v, int m) {

	int max = 0;
	int max_aux = 0;
	int contCeros = 0;

	for (int i = 0; i < v.size(); ++i) {

		if (v[i] == 1) max_aux++;
		else if (v[i] == 0) {

			contCeros++;
			max_aux++;

			if (contCeros > m) contCeros = max_aux = 0;
		}

		if (max < max_aux) max = max_aux;
	}
	return max;
}


bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	int m;
	std::vector<int> v(n);

	std::cin >> m;
	for (int & w : v) std::cin >> w;

	std::cout << nCeros(v, m) << std::endl;

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